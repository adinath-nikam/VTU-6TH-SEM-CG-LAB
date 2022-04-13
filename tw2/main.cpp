#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLfloat house[3][3]={{100.0,150.0,200},{100.0,150.0,100.0},{1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][3]={{0},{0},{0}};
GLfloat h;
GLfloat k;
GLfloat theta,rad;
int ch;

void multiply()
{
	int i,j,l;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		{
			result[i][j]=0;
			for(l=0;l<3;l++)
				result[i][j]=result[i][j]+rot_mat[i][l]*house[l][j];
		}
}
void rotate()
{
	GLfloat m,n;
	m=-h*(cos(theta)-1)+k*(sin(theta));
	n=-k*(cos(theta)-1)-h*(sin(theta));
	rot_mat[0][0]=cos(theta);
	rot_mat[0][1]=-sin(theta);
	rot_mat[0][2]=m;
	rot_mat[1][0]=sin(theta);
	rot_mat[1][1]=cos(theta);
	rot_mat[1][2]=n;
	rot_mat[2][0]=0;
	rot_mat[2][1]=0;
	rot_mat[2][2]=1;
	multiply();
}

void drawhouse(GLfloat mat[3][3])
{

	glBegin(GL_TRIANGLES);
	glVertex2f(mat[0][0],mat[1][0]);
	glVertex2f(mat[0][1],mat[1][1]);
	glVertex2f(mat[0][2],mat[1][2]);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	theta=rad;
	glColor3f(1.0,1.0,0.0);
	drawhouse(house);
	if(ch==1)
		{
			h=100;
			k=100;
			rotate();
glColor3f(1.0,0.0,0.0);
}
	if(ch==2)
	{
		h=(house[0][0]+house[0][1]+house[0][2])/3;
		k=(house[1][0]+house[1][1]+house[1][2])/3;
		rotate();
		glColor3f(1.0,0.0,1.0);
	}

	drawhouse(result);
	glFlush();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc,char** argv)
{
	printf("\nEnter the rotation angle : ");
	scanf("%f",&theta);
printf("\nEnter the choice \n1.fixed point \n2.origin\n\n");
	scanf("%d",&ch);
	rad=theta*(3.14/180.0);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("House Rotation");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
