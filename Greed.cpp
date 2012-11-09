/*
 * Greed.cpp
 *
 *  Created on: 09.11.2012
 *      Author: djbelyak
 */

#include "Greed.h"

namespace CppParallelDrop
{
	//Конструктор
	Greed::Greed(double b_x, double b_y, double e_x, double e_y, long m, long n)
	{
		//Копируем начальную и конечную точки
		BeginX = b_x;
		EndX = e_x;
		BeginY = b_y;
		EndY = e_y;
		//Копируем информацию о разрешении сетки
		M = m;
		N = n;

	}

	//Метод получения X по итеративным координатам
	double Greed::getX(long i_x, long i_y)
	{
		return X[i_x][i_y];
	}

	//Метод получения Y по итеративным координатам
	double Greed::getY(long i_x, long i_y)
	{
		return Y[i_x][i_y];
	}

	//Метод получения Z по итеративным координатам
	double Greed::getZ(long i_x, long i_y)
	{
		return Z[i_x][i_y];
	}

	//Метод получения R по итеративным координатам
	double Greed::getR(long i_x, long i_y)
	{
		return R[i_x][i_y];
	}

	//Метод получения G по итеративным координатам
	double Greed::getG(long i_x, long i_y)
	{
		return G[i_x][i_y];
	}

	//Метод получения B по итеративным координатам
	double Greed::getB(long i_x, long i_y)
	{
		return Z[i_x][i_y];
	}

	//Функция расчета координаты по Z
	double Greed::CalcZ (double X, double Y)
	{
		return cos(X*X+Y*Y);
	}
	//Функция расчета красного цвета
	double Greed::CalcR (double Z)
	{
		return 0.0;
	}
	//Функция расчета зеленого цвета
	double Greed::CalcG (double Z)
	{
		return (1.0+Z)/2.0;
	}
	//Функция расчета синего цвета
	double Greed::CalcB (double Z)
	{
		return (1.0-Z)/2.0;
	}
	//Метод построения сетки
	void Greed::Calculate ()
	{
		//Выделяем память под хранимые массивы данных
		X = new double* [M];
		Y = new double* [M];
		Z = new double* [M];
		R = new double* [M];
		G = new double* [M];
		B = new double* [M];
		for (long i=0; i<M; i++)
		{
			X[i] = new double [N];
			Y[i] = new double [N];
			Z[i] = new double [N];
			R[i] = new double [N];
			G[i] = new double [N];
			B[i] = new double [N];
		}

		//Производим расчет сетки
		for (long i=0; i<M; i++)
		{
			for (long j=0; j<N; j++)
			{
				X[i][j] = BeginX + i*(EndX-BeginX)/(double)M;
				Y[i][j] = BeginY + i*(EndY-BeginY)/(double)N;
				Z[i][j] = Greed::CalcZ(X[i][j],Y[i][j]);
				R[i][j] = Greed::CalcR(0.0);
				G[i][j] = Greed::CalcG(Z[i][j]);
				B[i][j] = Greed::CalcB(Z[i][j]);
			}
		}
	}
	//Деструктор
	Greed::~Greed()
	{
		//Собираем за собой мусор
		for (long i=0; i<M; i++)
		{
			delete[] X[i];
			delete[] Y[i];
			delete[] Z[i];
			delete[] R[i];
			delete[] G[i];
			delete[] B[i];
		}
		delete[] X;
		delete[] Y;
		delete[] Z;
		delete[] R;
		delete[] G;
		delete[] B;
	}

} /* namespace CppParallelDrop */
