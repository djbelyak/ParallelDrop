/*
 * OpenGLVizualizator.h
 *
 *  Created on: 08.11.2012
 *      Author: djbelyak
 */


#ifndef OPENGLVIZUALIZATOR_H_
#define OPENGLVIZUALIZATOR_H_

#define key_ESC 27

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Greed.h"

namespace CppParallelDrop
{

	class OpenGLVizualizator
	{
	public:
		/*
		 * Конструктор
		 */
		OpenGLVizualizator();
		/*
		 * Виртуальный деструктор
		 */
		virtual ~OpenGLVizualizator();
		/*
		 * Метод запуска приложения
		 */
		void Start (int, char**);

	private:
		/*
		 * Метод обработки изменения размеров окна
		 */
		static void Reshape(int, int);
		/*
		 * Метод отрисовки сцены OpenGL
		 */
		static void Display();
		/*
		 * Метод обработки нажатий клавиш
		 */
		static void  KeyPressed(unsigned char, int, int);

	};

}
/* namespace CppParallelDrop */
#endif /* OPENGLVIZUALIZATOR_H_ */
