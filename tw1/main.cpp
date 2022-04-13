#include<GL/glut.h>
#include<stdio.h>
int x1, y1, x2, y2;
void draw_pixel(int x, int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void bresenhams_line_draw(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy/dx;
    if(m < 1)
    {
        int decision_parameter = 2*dy - dx;
        int x = x1;
        int y = y1;
        if(dx < 0)
         {
            x = x2;
            y = y2;
            x2 = x1;
        }
        draw_pixel(x, y);
        while(x < x2)
        {
            if(decision_parameter >= 0)
            {
                x = x+1;
                y = y+1;
                decision_parameter=decision_parameter + 2*dy - 2*dx * (y+1 - y);
            }
            else
            {
                x = x+1;
                y = y;
                decision_parameter = decision_parameter + 2*dy - 2*dx * (y- y);
            }
            draw_pixel(x, y);
        }
    }
    else if(m > 1)
    {
        int decision_parameter = 2*dx - dy;
        int x = x1; // initial x
        int y = y1; // initial y
        if(dy < 0)
        {
            x = x2;
            y = y2;
            y2 = y1;
        }
        draw_pixel(x, y);
        while(y < y2)
        {
            if(decision_parameter >= 0)
            {
                x = x+1;
                y = y+1;
                decision_parameter=decision_parameter + 2*dx - 2*dy * (x+1 - x);
            }
            else
            {
                y = y+1;
                x = x;
                decision_parameter = decision_parameter + 2*dx - 2*dy * (x- x);
            }
            draw_pixel(x, y);
        }
    }
    else if (m == 1)
    {
        int x = x1;
        int y = y1;
        draw_pixel(x, y);
        while(x < x2)
        {
            x = x+1;
            y = y+1;
            draw_pixel(x, y);
        }
    }
}
void init()
{
    glClearColor(1,1,1,1);
    gluOrtho2D(0, 500, 0, 500);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhams_line_draw(x1, y1, x2, y2);
    glFlush();
}
int main(int argc, char **argv)
{
    printf( "Enter Start Points (x1,y1)\n");
    scanf("%d %d", &x1, &y1);
    printf( "Enter End Points (x2,y2)\n");
    scanf("%d %d", &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(220, 200);
    glutCreateWindow("Bresenham's Line Drawing - FVBIE");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
