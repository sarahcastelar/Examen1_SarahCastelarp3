#include <iostream>
#include "Metodos.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;


void stringJugador1();

void stringJugador2();

void ejercicio1(){
	Metodos* play = new Metodos();
	bool gameOver1 = false, gameOver2 = false;

   while (gameOver1==false || gameOver2 == false){

	char** matrix;
	int size = 11;
	matrix = play->createMatrix(size, matrix);
	matrix = play->llenarMatrix(size, matrix);
	play->printMatrix(size,matrix);

	int x, x2, y, y2;

	cout<<"Mueve jugador 1 (+)"<<endl
	<<"Ingrese coordenada X de la pieza a mover:  "<<endl;
	cin>>x;
	cout<<"Ingrese coordenada Y de la pieza a mover: "<<endl;
	cin>>y;
	cout<<"Ingrese coordenada X a donde mover: "<<endl;
	cin>>x2;
	cout<<"ingrese coordenada Y a donde mover: "<<endl;
	cin>>y2;

	//empieza el juego. se valida si donde decidio moverse es valido.
	matrix = play->muevePiezaJ1(x,y,x2,y2,matrix);
	
	cout<<"Mueve jugador 2 (#)"<<endl
	<<"Ingrese coordenada X de la pieza a mover: "<<endl;
	cin>>x;
	cout<<"Ingrese coordenada Y de la pieza a mover: "<<endl;
	cin>>y;
	cout<<"Ingrese coordenada X a donde mover: "<<endl;
	cin>>x2;
	cout<<"ingrese coordenada Y a donde mover: "<<endl;
	cin>>y2;

	matrix = play->muevePiezaJ2(x,y,x2,y2,matrix);



	gameOver1 = play->isItGameOver(matrix);
	gameOver2 = play->isItGameOver2(matrix);
	
	//validar si ya es game over. 


   }//while game over


	delete play;
}




int menu (){
   int opcion = 0;
   while (true){
  	cout<<"	MENU" << endl
	<< "1. Jugar" << endl
	<< "2. Salir" << endl;
	cin >> opcion;

	if (opcion < 1 || opcion > 2)
	   cout<<"Opcion incorrecta, intente de nuevo."<<endl;
	else 
	   return opcion;
}
}

int main (){
	int opcion = 0;
	while (opcion != 2){
		switch (opcion = menu()){
			case 1:
				ejercicio1();
			break;

		}
	 }
	return 0;
};



