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

void
init ()
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

  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();

  glutPostRedisplay ();
}

/**
 * Функция обратной связи GLUT при отрисовки окна.
 * Выполняет отрисовку OpenGL-сцены.
 */
void
display ()
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity ();

  /* Позиционирование камеры */
  glTranslated (0.0f, 0.0f, -7.0f);
  glRotated (0.0f, 1.0f, 0.0f, 0.0f);
  glRotated (0.0f, 0.0f, 1.0f, 0.0f);
  glRotated (0.0f, 0.0f, 0.0f, 1.0f);


  glBegin(GL_TRIANGLES);
  	  glColor3d(1.0,0.0,0.0);
      glVertex3d( 0.0, 1.0, 0.0);
      glColor3d(0.0,1.0,0.0);
      glVertex3d(-1.0, -1.0, 0.0);
      glColor3d(0.0,0.0,1.0);
      glVertex3d( 1.0, -1.0, 0.0);
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
