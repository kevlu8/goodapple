// im going to have to use opencv aren't i
#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

#define CON_X 236
#define CON_Y 56

using namespace cv;

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	// read from video.mp4
	VideoCapture cap("video.mp4");
	if (!cap.isOpened()) {
		std::cerr << "where tf is your video\n";
		return -1;
	}
	// video will be a black and white video
	// for each frame, for each pixel, print a ' ' if it's white and '.' if it's black
	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			break;
		}
		// resize the frame to 1920x1080
		resize(frame, frame, Size(CON_X, CON_Y));
		// convert to grayscale
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		// for each pixel, print a ' ' if it's white and '.' if it's black
		for (int y = 0; y < CON_Y; y++) {
			for (int x = 0; x < CON_X; x++) {
				if (frame.at<uchar>(y, x) > 127) {
					std::cout << ' ';
				} else {
					std::cout << '.';
				}
			}
			std::cout << '\n';
		}
		std::cout << "\x1b[3J" << std::flush;
		// wait 1/30th of a second
		usleep(1000000 / 30);
	}
	return 0;
}