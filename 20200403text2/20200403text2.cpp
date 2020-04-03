#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(){
	cv::Mat dstMat2;
	cv::Mat dstMat3;
	cv::Mat srcMat = cv::imread("D:\\lena.jpg", 1);
	if (srcMat.empty()) return -1;
	//��ת�����Ų���
	//��ת-40�㣬���ų߶�Ϊ
	float angle = -10.0, scale = 1;
	//��ת����Ϊͼ������
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	//��ñ任����
	const cv::Mat affine_matrix1 = cv::getRotationMatrix2D(center, angle, scale);
	cv::warpAffine(srcMat, dstMat2, affine_matrix1, srcMat.size());
	//����任����
	//�任ǰ��������
	const cv::Point2f src_pt[] = {
									cv::Point2f(200,200),
									cv::Point2f(250,200),
									cv::Point2f(200,100) };
	//�任����������
	const cv::Point2f dst_pt[] = {
								cv::Point2f(300,100),
								cv::Point2f(300,50),
								cv::Point2f(200,100) };
	//����������
	const cv::Mat affine_matrix2 = cv::getAffineTransform(src_pt, dst_pt);

	cv::warpAffine(srcMat, dstMat3, affine_matrix2, srcMat.size());

	cv::imshow("src", srcMat);
	cv::imshow("dst2", dstMat2);
	cv::imshow("dst3", dstMat3);
	cv::waitKey(0);


}