
#include<windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
//#include "headerlib.h"
double X1[20], Y1[20], X2[20], Y2[20];
  int counter=0;

float round_value(float v)
{
  return floor(v + 0.5);
}
void LineDDA(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
double k=0;
    for(int p=0;p<400;p++){
         glBegin(GL_POINTS);
    k +=1;
    glVertex2d(round_value(0), round_value(k));
    glVertex2d(round_value(k), round_value(0));

glEnd();
glFlush();
    }

    int i=0;
    for(i=0;i<counter;i++)
    {
  if(i%3==0)
  {int a = rand()%2;
  int b = rand()%2;
  int c = rand()%2;
  glColor3f(a,b,c);
  }
        double x1=X1[i];
        double y1=Y1[i];
        double x2=X2[i];
        double y2=Y2[i];
  double dx=(x2-x1);
  double dy=(y2-y1);
  double steps;
  float xInc,yInc,x=x1,y=y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;
  /* Clears buffers to preset values */
  //glClear(GL_COLOR_BUFFER_BIT);
  /* Plot the points */

  glBegin(GL_POINTS);
  /* Plot the first point */
  glVertex2d(x,y);
  int k;
  /* For every step, find an intermediate vertex */
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
    glVertex2d(round_value(x), round_value(y));
  }
  glEnd();
  glFlush();
}
}
void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(-10 , 490 , -10 , 490);
}

int main(int argc, char **argv)
{
  int num=0;
    printf("Enter the number of inputs:");
    scanf("%d",&num);

      /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Bar chart");
  /* Initialize drawing colors */
double x1,x2,y1,y2,d,f;
    for(int i=0;i<num;i++){
        printf("Enter the difference and corresponding Frequency: ");
        scanf("%lf%lf",&d,&f);
        if(counter==0){
        X1[0]=0;
        Y1[0]=0;
        X2[0]=0;
        Y2[0]=f;
        /*for(int s=1;s<5;s++){
            X1[s]=X2[s-1];
            Y1[s]=Y2[s-1];
            X2[s]=
        }*/
        X1[1]=0;
        Y1[1]=f;
        X2[1]=d;
        Y2[1]=f;

        X1[2]=d;
        Y1[2]=f;
        X2[2]=d;
        Y2[2]=0;
        counter=3;
        }
        else{
        X1[counter]=X1[counter-1]+100;
        Y1[counter]=0;
        X2[counter]=X1[counter];
        Y2[counter]=f;
        counter++;
        X1[counter]=X2[counter-1];
        Y1[counter]=f;
        X2[counter]=X1[counter]+d;
        Y2[counter]=Y1[counter];
        counter++;
        X1[counter]=X2[counter-1];
        Y1[counter]=Y2[counter-1];
        X2[counter]=X1[counter];
        Y2[counter]=0;
        counter++;
        }
    }
for(int p=0;p<counter;p++)
    printf("x1: %lf y1:%lf X2: %lf y2: %lf\n",X1[p],Y1[p],X2[p],Y2[p]);
  Init();

  /* Call the displaying function */
  glutDisplayFunc(LineDDA);

  /* Keep displaying untill the program is closed */
  glutMainLoop();
  return 0;
}
