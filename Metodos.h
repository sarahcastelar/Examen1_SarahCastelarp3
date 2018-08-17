#ifndef METODOS_H
#define METODOS_H

class Metodos{

	public:
		char** createMatrix(int,char**);
		char** llenarMatrix(int, char**);
		void freeMatrix(int, char**);
		void printMatrix(int, char**);
		
		char** muevePiezaJ1(int, int, int, int,char**);
		char** muevePiezaJ2(int, int, int, int,char**);

		bool isItGameOver(char**);
		bool isItGameOver2(char**);
		Metodos();//default


		~Metodos();



};



#endif
