#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(){
	cv::Mat dstMat2;
	cv::Mat dstMat3;
	cv::Mat dstMat4;
	cv::Mat srcMat = cv::imread("D:\\lena.jpg", 1);
	if (srcMat.empty()) return -1;
	//旋转和缩放操作
	//旋转-40°，缩放尺度为
	float angle = -10.0, scale = 1;
	//旋转中心为图像中心
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	//获得变换矩阵
	const cv::Mat affine_matrix1 = cv::getRotationMatrix2D(center, angle, scale);
	cv::warpAffine(srcMat, dstMat2, affine_matrix1, srcMat.size());
	//仿射变换操作
	//变换前三点坐标
	const cv::Point2f src_pt[] = {
									cv::Point2f(200,200),
									cv::Point2f(250,200),
									cv::Point2f(200,100) };
	//变换后三点坐标
	const cv::Point2f dst_pt[] = {
								cv::Point2f(300,100),
								cv::Point2f(300,50),
								cv::Point2f(200,100) };
	//计算仿射矩阵
	const cv::Mat affine_matrix2 = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, dstMat3, affine_matrix2, srcMat.size());
	//投影变换操作
	//变换前四点坐标
	const cv::Point2f pts1[] = {
									cv::Point2f(150,150),
									cv::Point2f(150,300),
									cv::Point2f(350,300),
									cv::Point2f(350,150) };
	//变换后四点坐标
	const cv::Point2f pts2[] = {
								cv::Point2f(200,150),
								cv::Point2f(200,300),
								cv::Point2f(340,270),
								cv::Point2f(340,180) };
	//透视变换行列计算
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	cv::warpPerspective(srcMat, dstMat4, perspective_matrix, srcMat.size());

	cv::imshow("src", srcMat);
	cv::imshow("dst2", dstMat2);
	cv::imshow("dst3", dstMat3);
	cv::imshow("dst4", dstMat4);
	cv::waitKey(0);


}