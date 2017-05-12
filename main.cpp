#include <iostream>
#include "opencv2/opencv.hpp"
#include "AprilTags/TagDetector.h"
#include "AprilTags/Tag36h11.h"

void MyFilledCircle( cv::Mat &img, cv::Point center,int i)
{
  int thickness = 1;
  int lineType = 8;
  /*circle( img,
          center,
          4,
          cv::Scalar( 0, 0, 255 ),
          thickness,
          lineType );*/
  cv::putText( img, std::to_string(i), center, 5,
           0.5, cv::Scalar( 255, 0, 0 ), 1, lineType);
}

int main() {
  AprilTags::TagDetector* m_tagDetector =
          new AprilTags::TagDetector(AprilTags::tagCodes36h11);

  cv::Mat image = cv::imread("./a.jpg");
  cv::Mat image_gray;
  cv::cvtColor(image, image_gray, CV_BGR2GRAY);

  vector<AprilTags::TagDetection> detections =
          m_tagDetector->extractTags(image_gray);


  for (int i=0; i<detections.size(); i++) {
    AprilTags::TagDetection &detection = detections[i];
    cout << "  Id: " << detection.id
         << " (Hamming: " << detection.hammingDistance << ")"<<endl;
    cout<<"good: "<<(detection.good ? "true":"false")<<endl;
    for(int j = 0; j < 4; ++j){
      cv::Point p((int)detection.p[j].first,(int)detection.p[j].second);
      cout<<"p"<<j<<": "<<p<<endl;
      MyFilledCircle(image,p,j);
    }
  }

  for (int i=0; i<detections.size(); i++) {
    // also highlight in the image
    detections[i].draw(image);
  }
  imshow("apriltags_demo", image); // OpenCV call
  cv::waitKey();



  return 0;
}