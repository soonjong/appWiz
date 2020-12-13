


#if 0
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //Video (note book cam)
    VideoCapture cap(0); // access First connected webcam
    if(!cap.isOpened())
    {
        cout << "Capture(Webcam) Couldn't open." << endl;
        return -1;
    }

    namedWindow("Video");

    Mat frame;

    while(char(waitKey(1)) != 'q' && cap.isOpened())
    {
        cap >> frame; // get a frame from captures
        if(frame.empty())
        {
            cout << "Video over!" << endl;
            break;
        }
        //Show frame
        imshow("Video", frame);
    }

    return 0;
}
#endif
