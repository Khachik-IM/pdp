#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

// Headers from OpenCV
#include "opencv2/opencv.hpp"
namespace utils {
    class ArgumentValidater {
        private: 
	    int argc;
	    char** argv;
            /*cv:String keys;
            cv:String videoPath;
            cv:String keepImagesPath;
            bool show;
            cv:CommandLineParser parser;
            */
        public: 
            /**
             * Class constructor.
             */
            ArgumentValidater ()=delete;
			
            ArgumentValidater (int argc, char** argv);
			/**
			 * Class destructor
			 */
            /*bool validate()const;
            cv:String getVideoPath()const;
            cv:String getKeepImagesPath()const;
            bool isShowEnable()const;
            */
    }; // end of class ArgumentValidater
} // end of namespace utils
#endif // ARGUMENT_HPP
