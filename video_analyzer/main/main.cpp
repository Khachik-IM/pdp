// Class headers
#include "VideoProcessor.hpp"


int main(int argc, const char** argv) {
    VA::VideoProcessor videoProcessor;
    bool status = videoProcessor.run(argv[1]);
    return 0;
}
