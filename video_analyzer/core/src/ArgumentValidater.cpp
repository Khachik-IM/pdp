// Class headers
#include "ArgumentValidater.hpp"
// Headers from OpenCV
#include "opencv2/opencv.hpp"


/**********************************************************
* Public members
**********************************************************/

utils::ArgumentValidater::
ArgumentValidater(int argc, char** argv) {
    this->argc = argc;
    this->argv = argv;
 /* this->keys = "{videopath v    |.     | path to video file         }"
                 "{keep ki        | -1.0 | forder path to keep images }"
                 "{show           |      | show video or not          }";
*/
}

/*bool utils::ArgumentValidater::
validate()const {
    this->parser = cv::CommandLineParser parser(this->argc, this->argv,this->keys);
    this->videoPath = this->parser.get<cv::String>("videopath");
    this->keepImagesPath = this->parser.get<cv::String>("keep");
    if (!this->parser.check()) {
        this->parser.printErrors();
        return false;
    }
    return true;
}

cv:String utils::ArgumentValidater::
getVideoPath()const {
    return this->videopath;
}

cv:String utils::ArgumentValidater::
getKeepImagesPath()const {
    return this->keepImagesPath;
}

bool utils::ArgumentValidater::
isShowEnable()const {
   return this->parser.has("show"); 
}
*/
