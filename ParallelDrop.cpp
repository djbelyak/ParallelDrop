//============================================================================
// Name        : ParallelDrop.cpp
// Author      : djbelyak
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================


#include "OpenGLVizualizator.h"



/**
 * Главная функция программы.
 */
int main(int argc, char** args)
{
	using namespace CppParallelDrop;
	OpenGLVizualizator* viz = new OpenGLVizualizator();
	viz->Start(argc,args);
	return 0;
}
