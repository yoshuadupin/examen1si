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
	 int cont1, cont2;
	char tablero1[tam][tam];
	char tablero2[tam][tam];
	BatallaNaval();


public:
	static BatallaNaval* getInstance();
	void imprimirTablero(int tablero);
	void generarBarcos();
	int	atacar1(int x , int y);
	int atacar2(int x, int y);


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
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			if ((rand()%100) % 5== 0) {
				tablero1[i][j] = '*';
				cont1++;
			}
			else {
				tablero1[i][j] = '#';
			}
			if ((rand() % 100) % 5 == 0){
				tablero2[i][j] = '*';
				cont2++;
			}
			else {
				tablero2[i][j] = '#';
			}
		}
	}
}

int BatallaNaval::atacar1(int x, int y)
{
	if (x<tam && y<tam && x >= 0 && y >=0) {
		if (tablero2[x][y] =='*') {
			cout << "Ha acertado" << endl;
			tablero2[x][y] = '#';
		return 	cont2--;
		}
	}
	else {
		cout << "Ha fallado" << endl;
	}
	return 1;

}
int BatallaNaval::atacar2(int x, int y)
{
	if (x < tam && y < tam && x >= 0 && y >= 0) {
		if (tablero1[x][y] == '*') {
			cout << "Ha acertado" << endl;
			tablero1[x][y] = '#';
			return cont1--;
		}
	}
	else {
		cout << "Ha fallado" << endl;
	}
	return 1;

}

BatallaNaval::BatallaNaval() {
}
	
int main()
{
	bool turno = true;
	int x, y;
	BatallaNaval* s = BatallaNaval::getInstance();
	s->generarBarcos();
	while (true) {
		cout << "Batalla Naval" << endl;
		if (turno) {
			s->imprimirTablero(0);
			cout << "Turno del jugador" << endl;
			cout << "Ingrese X:" << endl;
			cin >> x;
			cout << "Ingrese Y:" << endl;
			cin >> y;
			int temp = s->atacar1(x, y);
			if (temp == 0) {
				cout << "Gana el jugador" << endl;
				break;
			}
			cout << "Presiona una tecla para continuar" << endl;
			cin;
			system("cls");
			turno = false;

		}
		else {
			cout << "Turno de la maquina" << endl;
			x = rand() % 8;
			y = rand() % 8;
			int temp = s->atacar2(x, y);
			cout << "Tu nave esta en: " << x << " y " << y << endl;
			if (temp == 0) {
				cout << "Gana la maquina" << endl;
				break;
			}
			Sleep(2000);
			system("cls");
			turno = true;



		}
	}

	delete s;

}

