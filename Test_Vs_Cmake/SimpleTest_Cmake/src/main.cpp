// matrix_cal1.cpp
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

void MM_MV();

int main()
{
	MM_MV();
	return 0;
}

void vplusv(){
  Matrix2d a;
  a << 1, 2,
       3, 4;

  MatrixXd b(2,2);
  b << 5, 6,
       7, 8;

  std::cout << "a + b =\n" << a + b << std::endl;
  std::cout << "a - b =\n" << a - b << std::endl;
  std::cout << "Doing a += b;" << std::endl;
  a += b;
  std::cout << "Now a =\n" << a << std::endl;

  std::cout << std::endl;
  Vector3d v(1,2,3);
  Vector3d w(1,0,0);
  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
}

void MM_MV(){
  Matrix2d mat;
  mat << 1, 2,
         3, 4;

  Vector2d u(-1,1), v(2,0);

  std::cout << "Here is mat*mat:\n" << mat*mat << std::endl;
  std::cout << "Here is mat*u:\n" << mat*u << std::endl;
  std::cout << "Here is u^T*mat:\n" << u.transpose()*mat << std::endl;
  std::cout << "Here is u^T*v:\n" << u.transpose()*v << std::endl;
  std::cout << "Here is u*v^T:\n" << u*v.transpose() << std::endl;
  std::cout << "Let's multiply mat by itself" << std::endl;

  mat = mat*mat;

  std::cout << "Now mat is mat:\n" << mat << std::endl;
}