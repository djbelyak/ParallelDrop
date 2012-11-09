/*
 * Greed.h
 *
 *  Created on: 09.11.2012
 *      Author: djbelyak
 */


#ifndef GREED_H_
#define GREED_H_

#include <math.h>

namespace CppParallelDrop
{

	class Greed
	{
	public:
		//Конструктор
		Greed(double, double, double, double, long, long);
		//Метод получения X по итеративным координатам
		double getX (long, long);
		//Метод получения Y по итеративным координатам
		double getY (long, long);
		//Метод получения Z по итеративным координатам
		double getZ (long, long);
		//Метод получения R по итеративным координатам
		double getR (long, long);
		//Метод получения G по итеративным координатам
		double getG (long, long);
		//Метод получения B по итеративным координатам
		double getB (long, long);
		//Виртуальный деструктор
		virtual ~Greed();
	private:
		//Координата X начальной точки сетки
		double BeginX;
		//Координата Y начальной точки сетки
		double BeginY;
		//Координата X конечной точки сетки
		double EndX;
		//Координата Y конечной точки сетки
		double EndY;
		//Количество точек по оси X
		long M;
		//Количество точек по оси Y
		long N;
		//Функция расчета координаты по Z
		static double CalcZ (double, double);
		//Функция расчета красного цвета
		static double CalcR (double);
		//Функция расчета зеленого цвета
		static double CalcG (double);
		//Функция расчета синего цвета
		static double CalcB (double);
		//Метод построения сетки
		void Calculate ();
		//Массив точек по X
		double** X;
		//Массив точек по Y
		double** Y;
		//Массив точек по Z
		double** Z;
		//Массив точек по R
		double** R;
		//Массив точек по G
		double** G;
		//Массив точек по B
		double** B;

	};

}
/* namespace CppParallelDrop */
#endif /* GREED_H_ */
