/*
 * OpenGLVizualizator.h
 *
 *  Created on: 08.11.2012
 *      Author: djbelyak
 */
#include <GL/glu.h>
#include <GL/glut.h>

#ifndef OPENGLVIZUALIZATOR_H_
#define OPENGLVIZUALIZATOR_H_

#define key_ESC 27

namespace CppParallelDrop
{

	class OpenGLVizualizator
	{
	public:
		/*
		 * Конструктор по умолчанию
		 */
		OpenGLVizualizator();
		/*
		 * Виртуальный деструктор
		 */
		virtual ~OpenGLVizualizator();
		/*
		 * Метод обработки изменения размеров окна
		 */
		void static Reshape(int, int);
		/*
		 * Метод отрисовки сцены OpenGL
		 */
		void static Display();
		/*
		 * Метод обработки нажатий клавиш
		 */
		void static KeyPressed(unsigned char, int, int);
		/*
		 * Метод запуска приложения
		 */
		void Start (int, char*[]);
	};


}
/* namespace CppParallelDrop */
#endif /* OPENGLVIZUALIZATOR_H_ */
