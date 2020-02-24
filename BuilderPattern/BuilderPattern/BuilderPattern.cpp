// BuilderPattern.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>

using namespace std;


class Zord {
public:
    string rangerNombre;
    string creatura;
    string nombreZord;
    string color;

    string gritoDeUnion() {
        return rangerNombre + " yo te llamo " + nombreZord;
    }

};
class MegaZord {
public:
   
    Zord* m_pierDer;
    Zord* m_pierIzq;
    Zord* m_brazDer;
    Zord* m_brazIzq;
    Zord* m_centro;

    void transformacion() {
        cout << m_centro->gritoDeUnion() << endl;
        cout << m_pierDer->gritoDeUnion()  << endl;
        cout << m_pierIzq->gritoDeUnion()  << endl;
        cout << m_brazDer->gritoDeUnion()  << endl;
        cout << m_brazIzq->gritoDeUnion()  << endl;
    }
};



class MegaZordBuilder
{
public:
    virtual Zord* BuildPiernaDerecha() = 0;
    virtual Zord* BuildPiernaIzquierda() = 0;
    virtual Zord* BuildBrazoDerecho() = 0;
    virtual Zord* BuildBrazoIzquierdo() = 0;
    virtual Zord* BuildCentro() = 0;

    

};

class Director {
    MegaZordBuilder* builder;
public:
    void setBuilder(MegaZordBuilder* newMegaZordBuilder) {
        builder = newMegaZordBuilder;
    }
    MegaZord* getMegazord() {
        MegaZord* megazord = new MegaZord();

        megazord->m_pierDer= builder->BuildPiernaDerecha();
        megazord->m_pierIzq = builder->BuildPiernaIzquierda();
        megazord->m_brazDer = builder->BuildBrazoDerecho();
        megazord->m_brazIzq = builder->BuildBrazoIzquierdo();
        megazord->m_centro = builder->BuildCentro();
        return megazord;
    }

};
class DinoChargeMegaZordBuilder: public  MegaZordBuilder
{
public:
    Zord* BuildPiernaDerecha() {
        Zord* zord = new Zord();
        zord->color = "Negro";
        zord->rangerNombre = "Black Dino";
        zord->nombreZord = "Para Zord";
        zord->creatura = "Parasaurolophus";
        return zord;

    };
    Zord* BuildPiernaIzquierda() {
        Zord* zord = new Zord();
        zord->color = "Verde";
        zord->rangerNombre = "Green Dino";
        zord->nombreZord = "Raptor Zord";
        zord->creatura = "Velociraptor";
        return zord;

    };
    Zord* BuildBrazoDerecho() {
        Zord* zord = new Zord();
        zord->color = "Azul";
        zord->rangerNombre = "Blue Dino";
        zord->nombreZord = "Stego Zord";
        zord->creatura = "Stegosaurio";
        return zord;

    };
    Zord* BuildBrazoIzquierdo() {
        Zord* zord = new Zord();
        zord->color = "Rosa";
        zord->rangerNombre = "Pink Dino";
        zord->nombreZord = "Tricera Zord";
        zord->creatura = "Triceratops";
        return zord;

    };
    Zord* BuildCentro() {
        Zord* zord = new Zord();
        zord->color = "Rojo";
        zord->rangerNombre = "Red Dino";
        zord->nombreZord = "T-Rex Zord";
        zord->creatura = "Tiranosaurio";
        return zord;

    };

};


int main()
{
    MegaZord* megazord; 

    Director director;

    DinoChargeMegaZordBuilder dinoChargeMegaZordBuilder;
     

    std::cout << "Dino Charge Mega Zord!!!!!" << std::endl;
    director.setBuilder(&dinoChargeMegaZordBuilder); 
    megazord = director.getMegazord();
    megazord->transformacion();

    std::cout << std::endl;


    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
