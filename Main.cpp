#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat myImg; // Matrix to load the frame
	namedWindow("Camera"); //Declaring Video
	VideoCapture cap(0); //Declaring an object to capture stream of frames from default camera

	CascadeClassifier facedetect;
	facedetect.load("haarcascade_frontalface_default.xml");


	if (!cap.isOpened())   //This section prompt an error message if no video stream is found
	{
		cout << "No Video Stream Detected." << endl;
		system("pause");
		return -1;
	}

	while (true) // loop to show the video
	{
		cap >> myImg;
		if (myImg.empty()) //Breaking the loop if no video frame is detected
		{
			break;
		}

		vector<Rect> faces;
		facedetect.detectMultiScale(myImg, faces, 1.5, 5);

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(myImg, faces[i].tl(), faces[i].br(),Scalar(255,0,255), 2); //rectangle for face detection 
			rectangle(myImg, Point(0,0),Point(400,60), Scalar(0,0,0), FILLED); //rectangle to contain text
			putText(myImg, to_string(faces.size())+" Face Detected.",Point(50,40),FONT_HERSHEY_TRIPLEX,1,Scalar(0,255,255),2); // text to show how many face detected.

		}

		imshow("Camera", myImg); //Showing the video
		char c = (char)waitKey(1); //fram time prtimeocessing 
		if (c == 27) //if ESC is entered break the loop
		{
			break;
		 }

	}

	cap.release(); //releasing the buffer memory
	return 0;


}





