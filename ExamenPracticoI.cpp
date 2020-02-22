// ExamenPracticoI.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<Windows.h>
#include <stdlib.h>
using namespace std;

class BatallaNaval
{
private:
	static BatallaNaval* instace;
	static const int tam = 8;
	static char tablero1[tam][tam];
	static char tablero2[tam][tam];
	BatallaNaval();


public:
	static BatallaNaval* getInstance();
	static void imprimirTablero(int tablero);
	static void generarBarcos();

};

BatallaNaval* BatallaNaval::instace = 0;

BatallaNaval* BatallaNaval::getInstance() {
	if (instace == 0) { 
		instace = new BatallaNaval();
	}
	return instace;
}

void BatallaNaval::imprimirTablero(int tablero)
{
	if (tablero == 1) {
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				cout << "[";
				cout << tablero1[i][j];
				cout << "]";
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				cout << "[";
				cout << tablero1[i][j];
				cout << "]";
			}
			cout << endl;

		}
	}
}

void BatallaNaval::generarBarcos()
{
	int contBarco = 9;
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			if ((rand()%100) % 5== 0 && contBarco>0  ) {
				tablero1[i][j] = '*';
				contBarco++;
			}
			else {
				tablero1[i][j] = '#';
			}
			if ((rand() % 100) % 5 == 0 && contBarco) {
				tablero2[i][j] = '*';
				contBarco--;
			}
			else {
				tablero2[i][j] = '#';
			}
		}
	}
}

BatallaNaval::BatallaNaval() {

}
	
int main()
{
	BatallaNaval* s = BatallaNaval::getInstance();
	s->generarBarcos();
	s->imprimirTablero(0);
	s->imprimirTablero(1);
	delete s;

}

