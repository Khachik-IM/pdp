#ifndef VIDEOPROCESSOR_HPP
#define VIDEOPROCESSOR_HPP

#include "opencv2/highgui.hpp"
#include "Detector.hpp"
#include "BgSubtractor.hpp"

namespace VA {

    class VideoProcessor {
        private: 
            cv::VideoCapture videoCapture;
            VA::Detector detector;
            VA::BgSubtractor bgSubtractor;
            int frameIndex;

        public: 

            /**
             * Class constructor.
             */
            VideoProcessor();

            /**
             * Class destructor
             */
            ~VideoProcessor();

            /**
             * Reads video frames and do some transformations with them.
             * Detectes human in video frame.
             *
             * @param name - the video file name or steam
             * @return true if process completed with success and false otherwise
             */
            bool run(const std::string& name);

        private:
            cv::Rect imageArea(int sliderVal[]); // choose image rectangle area
            std::string generateFolderName() const; // Generates folder name
            void createNamedWindow() const; // Creates windows to show images;
            void createFolder(const std::vector<cv::Rect> rects, const cv::Mat& original, const std::string& folderName) const; // Creates rectangles for detected objects.
            void saveImages(const cv::Mat& original, const std::string& folderName) const; // Saves the images.
    }; // end of VideoProcessor class

} // end of VA namespace

#endif // VIDEOPROCESSOR_HPP
