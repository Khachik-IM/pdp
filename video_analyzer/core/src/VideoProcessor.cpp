// Class headers
#include "VideoProcessor.hpp"
#include "Detector.hpp"

// Headers from OpenCV
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

// Headers from system
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>


#define MAX_FAIL_FRAMES_COUNT 30

VA::VideoProcessor::
VideoProcessor() {
    this->frameIndex = 0;
}

VA::VideoProcessor::
~VideoProcessor() {
}

/**********************************************************
 * Public members
 **********************************************************/

bool VA::VideoProcessor::
run(const std::string& name) {
    if (!this->videoCapture.open(name)) {
        std::cout << "Faled to open the following video file: " << name << std::endl;
        return false;
    }
    mkdir("./images", 0777);
    this->videoCapture.set(CV_CAP_PROP_FPS, 10);
    this->createNamedWindow();
    cv::Mat origin;
    int wrongFramesCount = 0;
    int sliderVal[4] = {0,0,0,0};
    if (!this->detector.loadClassifier()) {
        return false;
    }
    do {
        if (!this->videoCapture.read(origin)) {
            wrongFramesCount++;
            if (MAX_FAIL_FRAMES_COUNT <= wrongFramesCount) {
                std::cout << "Video capture fail\n";
                break;
            }
            continue;
        }
        wrongFramesCount = 0;
        this->frameIndex++;
        std::vector<cv::Rect> rects;
        cv::Mat currentImage;
        std::string folderName = generateFolderName();

        // Process the current frame
        cv::resize(origin, origin, cv::Size(640, 480));
        origin.copyTo(currentImage);
        cv::Rect cropedFrame = imageArea(sliderVal);
        if (cropedFrame.tl().x != 0 || cropedFrame.tl().y != 0 || cropedFrame.br().x != 0 || cropedFrame.br().y != 0) {
            if (cropedFrame.tl().x != cropedFrame.br().x && cropedFrame.tl().y != cropedFrame.br().y) {
                currentImage = currentImage(cropedFrame);
            }
            cv::rectangle(origin, cropedFrame.tl(), cropedFrame.br(), cv::Scalar(61, 53, 53), 2, 8, 0);
        }       
        bgSubtractor.getForground(currentImage);
        cv::cvtColor(currentImage, currentImage, CV_BGR2GRAY);
        
        // Detects
        this->detector.detect(currentImage, rects);
        for (int i = 0; i < rects.size(); ++i) {
            rects[i] = cv::Rect(rects[i].tl().x + cropedFrame.tl().x,
                                rects[i].tl().y + cropedFrame.tl().y,
                                rects[i].width,
                                rects[i].height);
        }
         
        // Draw detected objects
        for (int i = 0; i < rects.size(); ++i) {
            cv::rectangle(origin, rects[i].tl(), rects[i].br(), cv::Scalar(255,0,0), 2, 8, 0);
        }
        cv::imshow("showDetect", origin);
        this->createFolder(rects, origin,  folderName);
    } while((char)cv::waitKey(10) != 'q');
    return true;
}   

/********************************************************** 
 * Private members
 **********************************************************/ 

cv::Rect VA::VideoProcessor::
imageArea(int sliderVal[] ) {
    cv::createTrackbar( "top left  x", "showDetect", &sliderVal[0], 640);
    cv::createTrackbar( "top left  y", "showDetect", &sliderVal[1], 480);
    cv::createTrackbar( "bottom right  x", "showDetect", &sliderVal[2], 640);
    cv::createTrackbar( "bottom right  y", "showDetect", &sliderVal[3], 480);
    return cv::Rect(cv::Point(sliderVal[0], sliderVal[1]), cv::Point(sliderVal[2], sliderVal[3]));
}

std::string VA::VideoProcessor::
generateFolderName() const {
    std::ostringstream s;
    s << "./images/folder" << this->frameIndex;
    return s.str();
}

void VA::VideoProcessor::
createNamedWindow() const {
    cv::namedWindow("showDetect", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("showDetect",0, 0);
    cv::namedWindow("Contours", cv::WINDOW_NORMAL);
    cv::resizeWindow("Contours",400,300);
    cv::moveWindow("Contours",700, 350);
    cv::namedWindow("Foreground", cv::WINDOW_NORMAL);
    cv::resizeWindow("Foreground",400,300);
    cv::moveWindow("Foreground",700, 0);
}

void VA::VideoProcessor::
createFolder(const std::vector<cv::Rect> rects, const cv::Mat& original, const std::string& folderName ) const {
    if (rects.size() > 0) { 
        int res = mkdir(folderName.c_str(), 0777);
        this->saveImages(original, folderName);
    }
}

void VA::VideoProcessor::
saveImages (const cv::Mat& original, const std::string& folderName ) const {
    std::ostringstream s;
    s << folderName << "/image" << this->frameIndex << ".jpg";
    std::string name = s.str();
    cv::imwrite(name, original);
}

