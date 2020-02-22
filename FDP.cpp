// FDP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>

class Minion {
public:
    virtual void  atacar() = 0;
};

class Mago : public Minion {
public:
    void atacar() {
    }
};

class Cuchillo: public Minion {
public:
    void atacar() {
    }
};

class Pesado : public Minion {
public:
    void atacar() {
    }
};


class Super : public Minion {
public:
    void atacar() {
    }
};

class Inhibidor {
public:
    static Minion* crearMinion(int tipo) {
        if (tipo == 1)
            return new Mago;
         if (tipo == 2) {
             return new Cuchillo;
        }

         if (tipo == 3) {
             return new Pesado;
         }

         return new Super;
}

};

using namespace std;
int main()
{
    cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
