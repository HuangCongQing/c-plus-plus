/*
 * @Description: https://blog.csdn.net/wyg1997/article/details/78282981?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_baidulandingword-1&spm=1001.2101.3001.4242
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-12 15:37:38
 * @LastEditTime: 2021-05-12 15:37:50
 * @FilePath: /c-plus-plus/practice/B样条曲线/连续绘制三次B样条曲线.cpp
 */
#include<gl/glut.h>
#include<math.h>
#include<windows.h>
#include<vector>
#include<algorithm>
using namespace std;
bool mouseRightIsDown = false;
struct Point
{
	int x, y;
	Point(){};
	Point(int tx, int ty)
	{
		x = tx;
		y = ty;
	}
};
vector<Point> p;
double getRatio(double t,double a,double b,double c,double d)
{
	return a * pow(t, 3) + b * pow(t, 2) + c * t + d;
}
double caculateSquarDistance(Point a, Point b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int getIndexNearByMouse(int x, int y)
{
	double precision = 200;		//精确度
	int index = -1;
	double Min;
	for (int i = 0; i < p.size(); i++)
	{
		double dis = caculateSquarDistance(p[i], Point(x, y));
		if (dis < precision)
		{
			if (index == -1)
			{
				index = i;
				Min = dis;
			}
			else if (dis < Min)
			{
				index = i;
				Min = dis;
			}
		}
	}
	return index;
}
void Bspline(Point a,Point b,Point c,Point d)
{
	int n = 500;
	double derta = 1.0 / n;
	glPointSize(2);
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= n; i++)
	{
		double t = derta * i;
		double ratio[4];
		ratio[0] = getRatio(t, -1, 3, -3, 1);
		ratio[1] = getRatio(t, 3, -6, 0, 4);
		ratio[2] = getRatio(t, -3, 3, 3, 1);
		ratio[3] = getRatio(t, 1, 0, 0, 0);
		double x=0, y=0;
		x += ratio[0] * a.x + ratio[1] * b.x + ratio[2] * c.x + ratio[3] * d.x;
		y += ratio[0] * a.y + ratio[1] * b.y + ratio[2] * c.y + ratio[3] * d.y;
		x /= 6.0;
		y /= 6.0;
		glVertex2d(x, y);
	}
	glEnd();
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);    //清除颜色缓存和深度缓存

	//画点
	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < p.size(); i++)
		glVertex2d(p[i].x, p[i].y);
	glEnd();

	//画线
	glLineWidth(2);
	glColor3d(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < p.size(); i++)
		glVertex2d(p[i].x, p[i].y);
	glEnd();

	if (p.size() >= 4)
		for (int i = 0; i < p.size() - 3; i++)
			Bspline(p[i], p[i + 1], p[i + 2], p[i + 3]);

	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)		//ESC
		exit(0);
	if (key == 8)		//退格键
	{
		int index = getIndexNearByMouse(x, y);
		if (index == -1)
			return;
		p.erase(p.begin() + index);
		glutPostRedisplay();
	}
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Point t(x, y);
		p.push_back(t);
		glutPostRedisplay();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		mouseRightIsDown = true;
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
		mouseRightIsDown = false;
}
void motion(int x, int y)
{
	if (mouseRightIsDown)		//按住右键移动点
	{
		int index = getIndexNearByMouse(x, y);
		if (index == -1)
			return;
		p[index].x = x;
		p[index].y = y;
		glutPostRedisplay();
	}
}
void Reshape(int w, int h)      //两个参数：窗口被移动后大小
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void initWindow(int &argc, char *argv[], int width, int height, char *title)    //初始化并显示到屏幕中央
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - width) >> 1, (GetSystemMetrics(SM_CYSCREEN) - height) >> 1);       //指定窗口位置
	glutInitWindowSize(width, height);       //指定窗口大小
	glutCreateWindow(title);

	glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);
}

int main(int argc, char *argv[])
{
	initWindow(argc, argv, 1000, 600, "B样条曲线");

	puts("\n\t鼠标在窗口点击绘制B样条曲线，鼠标右键移动控制点");
	puts("\t退格键（←）删除鼠标所在的点");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

