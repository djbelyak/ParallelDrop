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
		static void Reshape(int, int);
		/*
		 * Метод отрисовки сцены OpenGL
		 */
		static void Display();
		/*
		 * Метод обработки нажатий клавиш
		 */
		static void  KeyPressed(unsigned char, int, int);
		/*
		 * Метод запуска приложения
		 */
		static void Start (int, char**);
	};


}
/* namespace CppParallelDrop */
#endif /* OPENGLVIZUALIZATOR_H_ */
