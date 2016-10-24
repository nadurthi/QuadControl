//============================================================================
// Name        : learnopencv.cpp
// Author      : Nagnanamus
// Version     :
// Copyright   : Do what ever you want!!! I am not responsible
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace cv;
using namespace std;
//#include <opencv.hpp>
int main() {
int i=0;
char buffer[100];
    CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
    if ( !capture ) {
        fprintf( stderr, "ERROR: capture is NULL \n" );
        getchar();
        return -1;
                     }
    // Create a window in which the captured images will be presented
    cvNamedWindow( "mywindow", CV_WINDOW_AUTOSIZE );
    // Show the image captured from the camera in the window and repeat
    while ( 1 ) {
        // Get one frame
        IplImage* frame = cvQueryFrame( capture );
        if ( !frame ) {
            fprintf( stderr, "ERROR: frame is null...\n" );
            getchar();
            break;
        }
        cvShowImage( "mywindow", frame );
        // Do not release the frame!

        if ( cvWaitKey(100) < 0 ) {
        	snprintf(buffer,100,"matteo_%d.jpg",i);
            cvSaveImage(buffer,frame);
            i++;
        }
     if ( (cvWaitKey(10) & 255) == 27 ) break;
    }
    // Release the capture device housekeeping
    cout<<"releasing"<<endl;
    cvReleaseCapture( &capture );
    cvDestroyWindow( "mywindow" );
    return 0;
}
