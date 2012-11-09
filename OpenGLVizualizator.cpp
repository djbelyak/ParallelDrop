/*
 * OpenGLVizualizator.cpp
 *
 *  Created on: 08.11.2012
 *      Author: djbelyak
 */

#include "OpenGLVizualizator.h"

namespace CppParallelDrop
{

	/*
	 * Конструктор
	 */
	OpenGLVizualizator::OpenGLVizualizator()
	{
		greed = new Greed (-10.0, -10.0, 10.0, 10.0, 1000, 1000);
	}

	/*
	 * Виртуальный деструктор
	 */
	OpenGLVizualizator::~OpenGLVizualizator()
	{
		delete greed;
	}

	/*
	 * Метод обработки изменения размеров окна
	 * w - ширина окна (пикселы)
	 * h - высота окна (пикселы)
	 */
	void OpenGLVizualizator::Reshape(int w, int h)
	{

		//Если высота окна равна 0 - искусственно увеличиваем ее до 1
		if (h == 0)
			h = 1;

		//Устанавливаем размер проецируемого изображения
		glViewport (0, 0, (GLsizei)w, (GLsizei)h);

		//Выбираем матрицу проекции
		glMatrixMode (GL_PROJECTION);
		//Очищем ее
		glLoadIdentity ();
		//Задаем перспективную проекцию
		gluPerspective (45.0, (GLfloat)w/(GLfloat)h, 0.1, 1000.0);
		//Устанавливаем камеру
		gluLookAt(12.0, 12.0, 12.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);

		//Переключаемся к модельно-видовой матрицу
		glMatrixMode (GL_MODELVIEW);
		//Очищаем ее
		glLoadIdentity ();
		//Перерисовываем сцену
		glutPostRedisplay ();
	}

	/*
	 * Метод обработки нажатий клавиш
	 * key - код нажатой клавиши
	 */
	void OpenGLVizualizator::KeyPressed(unsigned char key, int x, int y)
	{
		// Если нажали ECS
		if (key == key_ESC)
		{
			//Закрываем окно
			glutDestroyWindow((int)glutGetWindow());
			//Выходим из программы
			exit(0);
		}
	}

	/*
	 * Метод отрисовки сцены OpenGL
	 */
	void OpenGLVizualizator::Display()
	{
		//Очищаем буферы кадра  и глубины
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Загружаем единичную модельно-видовую матрицу
		glLoadIdentity ();

		//Отрисовываем полигоны
		glBegin(GL_TRIANGLES);
			for (long i=0; i<greed->getM(); i++)
				for (long j=0; j<greed->getN(); j++)
				{
					glColor3d(greed->getR(i,j),greed->getG(i,j),greed->getB(i,j));
					glVertex3d(greed->getX(i,j),greed->getZ(i,j),greed->getY(i,j));
					glColor3d(greed->getR(i+1,j),greed->getG(i+1,j),greed->getB(i+1,j));
					glVertex3d(greed->getX(i+1,j),greed->getZ(i+1,j),greed->getY(i+1,j));
					glColor3d(greed->getR(i+1,j+1),greed->getG(i+1,j+1),greed->getB(i+1,j+1));
					glVertex3d(greed->getX(i+1,j+1),greed->getZ(i+1,j+1),greed->getY(i+1,j+1));

					glColor3d(greed->getR(i,j),greed->getG(i,j),greed->getB(i,j));
					glVertex3d(greed->getX(i,j),greed->getZ(i,j),greed->getY(i,j));
					glColor3d(greed->getR(i,j+1),greed->getG(i,j+1),greed->getB(i,j+1));
					glVertex3d(greed->getX(i,j+1),greed->getZ(i,j+1),greed->getY(i,j+1));
					glColor3d(greed->getR(i+1,j+1),greed->getG(i+1,j+1),greed->getB(i+1,j+1));
					glVertex3d(greed->getX(i+1,j+1),greed->getZ(i+1,j+1),greed->getY(i+1,j+1));
				}
		glEnd();
		//Отрисовываем оси
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

		//Отправлем на отрисовку
		glFlush();
		//Меняем буферы кадра местами
		glutSwapBuffers();
	}

	/*
	 * Метод запуска приложения
	 */
	void OpenGLVizualizator::Start (int argc, char** args)
	{
		//Инициализация GLUT
		glutInit (&argc,args);

		//Создание OpenGL окна
		glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize (640, 480);
		glutCreateWindow ("ParallelDrop");

		//Установка цвета очистки экрана - черный
		glClearColor (0.0f, 0.0f, 0.0f, 0.0f);

		//Настройка функций обратной связи GLUT
		glutReshapeFunc(OpenGLVizualizator::Reshape);
		glutDisplayFunc(OpenGLVizualizator::Display);
		glutKeyboardFunc(&OpenGLVizualizator::KeyPressed);

		//Вход в основной цикл
		glutMainLoop ();

	};

}

/* namespace CppParallelDrop */
