#include<GL/glut.h>
#include<math.h>


int theta = 0;
int ps = 1;
int len = 20;

void dispcallback();
void reshapecallback(int,int);

/*
double s(double t)
{
double var = 2 * 3.13159;
var /= 360;
var *= t;
return sin(var);
}
double c(double t)
{
double var = 2 * 3.13159;
var /= 360;
var *= t;
return cos(var);
}
*/

void animate(int a)
{

theta+=ps;

if (theta == 40)ps = -1;
else if (theta == -50)ps = 1 ;

glutPostRedisplay();
glutTimerFunc(1000/60, animate,0);

}

/*
void point(int len, double theta)
{
glVertex2f(len * s(theta), len * c(theta));

}
*/

void init()
{
glClearColor(0, 0, 0, 1);
theta = -50;
}

int main(int   a,char**b)
{
glutInit(&a, b);

glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
glutInitWindowPosition(500, 500);
glutInitWindowSize(800, 800);

glutCreateWindow("pokemon");
glutDisplayFunc(dispcallback);
glutReshapeFunc(reshapecallback);
animate(0);
glutMainLoop();


}

void dispcallback()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
////
glColor3f(0.3,0.5,0.7);
glPointSize(10);

//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

glBegin(GL_POLYGON);
//
glColor3f(1, 1, 0);
glVertex3f(theta, 0, 0);
glColor3f(1, 1, 1);
glVertex3f(theta + 10, 0, 0);
glColor3f(1, 0, 0);
glVertex3f(theta + 10, 10, 0);
glColor3f(1, 0, 1);
glVertex3f(theta , 10, 0);


glEnd();
////
// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


glutSwapBuffers();

}


void reshapecallback(int a,int b)
{
glViewport(0, 0, a, b);

//to set in graph like cordinsate system
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-50, 50, -50, 50);
glMatrixMode(GL_MODELVIEW);


}
