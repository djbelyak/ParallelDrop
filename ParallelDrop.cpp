//============================================================================
// Name        : ParallelDrop.cpp
// Author      : djbelyak
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>


double f(double x, double y)
{
	return cos (pow(x,2)+pow(y,2));
}

void init ()
{
  /*
   * Инициализация OpenGL
   */

  glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
}

/**
 * Функция обратной связи GLUT при изменении размеров окна.
 * Обновляет матрицы viewport и projection.
 */
void
reshape (int w, int h)
{
  if (h == 0)
    h = 1;

  glViewport (0, 0, (GLsizei)w, (GLsizei)h);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45.0, (GLfloat)w/(GLfloat)h, 0.1, 1000.0);
  gluLookAt(12.0, 12.0, 12.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();

  glutPostRedisplay ();
}

/**
 * Функция обратной связи GLUT при отрисовки окна.
 * Выполняет отрисовку OpenGL-сцены.
 */
void display ()
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity ();


  glBegin(GL_LINES);
  	  //Ось X
  	  glColor3d(1.0, 0.0, 0.0);
      glVertex3d(0.0, 0.0, 0.0);
      glVertex3d(10.0, 0.0, 0.0);
  	  //Ось Y
  	  glColor3d(0.0, 1.0, 0.0);
      glVertex3d(0.0, 0.0, 0.0);
      glVertex3d(0.0, 10.0, 0.0);
  	  //Ось Z
  	  glColor3d(0.0, 0.0, 1.0);
      glVertex3d(0.0, 0.0, 0.0);
      glVertex3d(0.0, 0.0, 10.0);
  glEnd();

  long n = 1000; //Количество точек по x
  long m = 1000; //Количество точек по y
  double x_b=-10.0, x_e=10.0, y_b=-10.0, y_e=10.0;
  double d_x = (x_e-x_b)/(double)n;
  double d_y = (y_e-y_b)/(double)m;
   glBegin(GL_TRIANGLES);
  	  for (long i=0; i<n-1; i++)
  		  for (long j=0; j<m-1;j++)
  		  {
  			  double x = x_b + i*d_x;
  			  double y = y_b + j*d_y;

  			  glColor3d (0.0, (1+f(x,y))/2.0, (1-f(x,y))/2.0);
  			  glVertex3d (x, f(x,y), y);
  			  glColor3d (0.0, (1+f(x+d_x,y))/2.0, (1-f(x+d_x,y))/2.0);
  			  glVertex3d (x+d_x, f(x+d_x,y), y);
  			  glColor3d (0.0, (1+f(x+d_x,y+d_y))/2.0, (1-f(x+d_x,y+d_y))/2.0);
  			  glVertex3d (x+d_x, f(x+d_x, y+d_y), y+d_y);

  			  glColor3d (0.0, (1+f(x,y))/2.0, (1-f(x,y))/2.0);
  			  glVertex3d (x, f(x,y), y);
  			  glColor3d (0.0, (1+f(x,y+d_y))/2.0, (1-f(x,y+d_y))/2.0);
  			  glVertex3d (x, f(x,y+d_y), y+d_y);
  			  glColor3d (0.0, (1+f(x+d_x,y+d_y))/2.0, (1-f(x+d_x,y+d_y))/2.0);
  			  glVertex3d (x+d_x, f(x+d_x,y+d_y), y+d_y);
  		  }
  glEnd();


  glutSwapBuffers ();
}

void keyPressed(unsigned char key, int x, int y)
{

    /* If escape is pressed, kill everything. */
    if (key == 27)
    {
	/* shut down our window */
	glutDestroyWindow(glutGetWindow());

	/* exit the program...normal termination. */
	exit(0);
    }
}

/**
 * Главная функция программы.
 */
int
main (int argc, char *argv[])
{
  /* Иничиализация GLUT */
  glutInit (&argc, argv);

  /* Создание OpenGL окна */
  glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize (640, 480);
  glutCreateWindow ("ParallelDrop");

  /* Инициализация приложения */
  init ();

  /* Настройка функций обратной связи GLUT */
  glutReshapeFunc (reshape);
  glutDisplayFunc (display);
  glutKeyboardFunc(&keyPressed);

  /* Вход в основной цикл */
  glutMainLoop ();

  return 0;
}
