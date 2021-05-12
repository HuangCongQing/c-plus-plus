/*
 * @Description: https://github.com/lkj1114889770/B-Spline-Curve/blob/master/BSplineCurve.cpp
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-12 15:18:26
 * @LastEditTime: 2021-05-12 15:18:44
 * @FilePath: /c-plus-plus/practice/B样条曲线/BSplineCurve.cpp
 */
#include <Eigen/Dense>
#include <iostream>
#include <cmath>
#include <gl/glut.h>
using namespace Eigen;
using namespace std;

void Display();
void Caculate_R(int i);
Vector3d Caculate_Curve(int i, double u);
double delta_u(int i, double u_j);

MatrixXd P(10, 3); //10个型值点，n+1=10
MatrixXd B(12, 3); //12个控制点，10+2=12
Vector3d R3, R2, R1, R0; //B样条曲线的参数矩阵，Pi = R0 + R1*u + R2*u*u + R3*u*u*u
int main(int argc, char *argv[])
{
	
	P << -0.5, -0.5, 0.0,
		-0.8, -0.1, 0.0,
		-0.4, 0.5, 0.0,
		-0.1, 0.6, 0.0,
		0.3, 0.4, 0.0,
		0.5, 0.25, 0.0,
		0.7, 0.0, 0.0,
		0.8, -0.2, 0.0,
		0.3, -0.4, 0.0,
		0.4, -0.5, 0.0; 
	MatrixXd A(12, 12);
	A = MatrixXd::Zero(12, 12);
	cout << A << endl;
	for (int i = 0; i < 12; i++){
		if (i == 0){
			A(0, 0) = -1;
			A(0, 1) = 1;
		}
		else if (i == 11){
			A(11, 10) = 1;
			A(11, 11) = -1;
		}
		else{
			A(i, i - 1) = 1;
			A(i, i) = 4;
			A(i, i + 1) = 1;
		}
	}
	cout << A << endl;
	MatrixXd PP(12, 3);
	PP = MatrixXd::Zero(12, 3);
	for (int i = 1; i < 11; i++){
		for (int j = 0; j < 2; j++){
			PP(i, j) = 6*P(i - 1, j);
		}
	}
	cout << PP << endl;
	B = A.inverse()*PP;
	cout << "控制点" << endl;
	cout << B << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(600, 600);
	glutCreateWindow("B样条曲线");
	glutDisplayFunc(&Display);
	glutMainLoop();

	return 0;
}
void Caculate_R(int i)
{
	R3 = (-B.row(i) + 3 * B.row(i + 1) - 3 * B.row(i + 2) + B.row(i + 3)) / 6;
	R2 = (3 * B.row(i) - 6 * B.row(i + 1) + 3 * B.row(i + 2)) / 6;
	R1 = (-3 * B.row(i) + 3 * B.row(i + 2)) / 6;
	R0 = (B.row(i) + 4 * B.row(i + 1) + B.row(i + 2)) / 6;
}
Vector3d Caculate_Curve(int i,double u)
{
	Caculate_R(i);
	return (R0 + R1*u + R2*u*u + R3*u*u*u);
}
double delta_u(int i, double u_j)
{
	Caculate_R(i);
	double a4, a3, a2, a1, a0;
	a4 = 9 * R3.transpose()*R3;
	a3 = 12 * R3.transpose()*R2;
	a2 = 4 * R2.transpose()*R2;
	a2= a2 + (6 * R3.transpose()*R1);
	a1 = 4 * R2.transpose()*R1;
	a0 = R1.transpose()*R1;
	double delta;
	delta = sqrt(a4*pow(u_j,4)+a3*pow(u_j,3)+a2*pow(u_j,2)+a1*u_j+a0);
	return delta;
}

void Display(void)//OpenGL来绘制曲线
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	float g_CP[24];
	int k = 0;
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 2; j++){
			g_CP[k] = B(i, j);
			cout << g_CP[k] << endl;
			k++;
		}
	}
	glPointSize(10);
	glColor3d(255, 0, 0);
	glBegin(GL_POINTS);
	k = 0;
	while (k < 22){
		glVertex2f(g_CP[k], g_CP[k + 1]);
		k = k + 2;
	}
	glEnd();

	glVertexPointer(2, GL_FLOAT, 0, g_CP);
	glPointSize(2);
	glColor3d(255, 0, 0);
	glDrawArrays(GL_LINE_STRIP, 0, 12); //不闭合折线绘制

	float u;
	Vector3d point_3d;
	GLfloat point[2];
	glColor3d(0, 255, 0);
	glBegin(GL_LINE_STRIP);
	glPointSize(4);
	for (int i = 0; i < 9; i++) {
		u = 0;
		Caculate_R(i);
		for (int j = 0; j < 20; j++){
			//u = u + delta_u(i, u);
			point_3d = Caculate_Curve(i,u);

			u = u + 0.05;
			point[0] = point_3d(0), point[1] = point_3d(1);
			glVertex2f(point[0], point[1]);
		}
		
	}
	glEnd();
	glPointSize(10);
	glBegin(GL_POINTS);
	for (int i = 0; i<10; i++){
		glVertex2f(P(i, 0), P(i, 1));
	}
	glEnd();
	glFlush();
}
