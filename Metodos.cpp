#include "Metodos.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


char** Metodos::createMatrix(int size, char** matrix){
	char** retVal = new char*[size];

	for (int i = 0; i < size; i++){
		retVal[i] = new char [size];
	}
	return retVal;
}


char** Metodos::llenarMatrix(int size, char** matrix){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
		    if ( i == 0 && j == 5)
			matrix[i][j] = '+' ;
		    else if (i == 10 && j == 5)
			matrix[i][j] = '+';
		    else if (i == 5 && j == 0)
			matrix[i][j] = '#';
		    else if (i == 5 && j == 10)
			matrix[i][j] = '#';
		    else
			    matrix[i][j] = ' ';
		}
	}
	return matrix;
}


void Metodos::freeMatrix(int size, char** matrix){
	for (int i = 0; i < size; i++){
		delete [] matrix[i];
	}
	delete[] matrix;
}

void Metodos::printMatrix(int size, char** matrix){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout<<"["<<matrix[i][j]<<"]";
		}
		cout<<endl;
	}
	cout<<"entra too"<<endl;
}

char** Metodos::muevePiezaJ1(int x, int y, int x2, int y2, char** matrix){	
	bool movimientoValido = false;
	
	if  (matrix[x][y] == '+'){
	    if (matrix[x2][y2] = ' '){
		if( (x2 >= 0 && x2 <=10) && (y2 >= 0 && y2 <= 10) ){ //que esten dentro del rango de la matriz y que no se quiera mover al mismo lugar
			
			//cuando se clona
			if ( (x2 == (x-1)) || (x2 == (x+1)) || (y2 == (y-1)) || (y2 == (y+1)) || (x2==x) || (y2==y) ){//si se puede mover en ese rango que lo haga. y que no 													quite el original
				matrix[x2][y2] = '+';
				movimientoValido = true;

			} else if ( (x2 == (x-2)) || (x2 == (x+2)) || (y2 == (y-2)) || (y2 == (y+2)) || (y2==y) || (x2==x)  ) { //cuando se mueve y no se clona. 
				matrix[x2][y2] = '+';
				matrix[x][y] = ' ';
				movimientoValido=true;
			}


		}else
			cout<<"Sus coordenadas se salen del limite. "<<endl;
			
	    }else 
		    cout<<"No puede moverse encima `de otra pieza."<<endl;
	    
	}else
		cout<<"No puede mover piezas de su contricante. "<<endl;	    

	if (movimientoValido){
		printMatrix(11,matrix);
	}else
		cout<<"Movimiento invalido. Ingrese coordenadas otra vez."<<endl;

	return matrix;

}


char** Metodos::muevePiezaJ2(int x, int y, int x2, int y2, char** matrix){	
	bool movimientoValido = false;
	
	if  (matrix[x][y] == '#'){
	    if (matrix[x2][y2] = ' '){
		if( (x2 >= 0 && x2 <=10) && (y2 >= 0 && y2 <= 10) ){ //que esten dentro del rango de la matriz y que no se quiera mover al mismo lugar
			
			//cuando se clona
			if ( (x2 == (x-1)) || (x2 == (x+1)) || (y2 == (y-1)) || (y2 == (y+1)) || (x2==x) || (y2==y) ){//si se puede mover en ese rango que lo haga. y que no 													quite el original
				matrix[x2][y2] = '#';
				movimientoValido = true;

			} else if ( (x2 == (x-2)) || (x2 == (x+2)) || (y2 == (y-2)) || (y2 == (y+2)) || (y2==y) || (x2==x)  ) { //cuando se mueve y no se clona. 
				matrix[x2][y2] = '#';
				matrix[x][y] = ' ';
				movimientoValido=true;
			}


		}else
			cout<<"Sus coordenadas se salen del limite. "<<endl;
			
	    }else 
		    cout<<"No puede moverse encima de otra pieza."<<endl;
	    
	}else
		cout<<"No puede mover piezas de su contricante. "<<endl;
    	    

	if (movimientoValido){
		printMatrix(11,matrix);
	}else
		cout<<"Movimiento invalido. Ingrese coordenadas otra vez."<<endl;

	return matrix;
}


bool Metodos::isItGameOver(char** matrix){
	bool perdio = false;
	int contadorMas = 0;

	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			if (matrix[i][j] == '+')
				contadorMas++;	

		}
	}

	if (contadorMas > 0)
		perdio = false;
	else 
		perdio = true;

	return perdio;
}

bool Metodos::isItGameOver2(char** matrix){
	int contadorNumeral = 0;
	bool perdio= false;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			if (matrix[i][j] == '#')
				contadorNumeral++;
		}
	}

	if (contadorNumeral > 0)
		perdio = false;
	else 
		perdio = true;

	return perdio;

}





Metodos::Metodos(){
}

Metodos::~Metodos(){
	cout<<"Memoria liberada"<<endl;
}

