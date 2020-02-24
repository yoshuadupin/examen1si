// FDP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include<cstdlib>
#include<Windows.h>

#define MinionMago  1
#define MinionCuchillo 2 
#define MinionPesado  3
#define MinionSuper  0

using namespace std;

class Minion {
public:
    virtual ~Minion() {}
    virtual void  atacar() = 0;
};

class Mago : public Minion {
public:
    void atacar() {
        cout << "       __/\__" << endl;
        cout << " ._    \\\\''//" << endl;
        cout << "-( )-  /_||_\\ "<<endl;
        cout << " .'.   \\_()_/" << endl;
        cout << "  |     | . \\ "<<endl;
        cout << "  |mrf  | .  \\ "<<endl;
        cout << " .'.   ,\\_____'."<<endl;
    }
};

class Cuchillo: public Minion {
public:
    void atacar() {
        cout << "|\\            //" << endl;
        cout << "\\\\           _!_" << endl;
        cout << " \\\\         /___\\" << endl;
        cout << "  \\\\        [+++] " << endl;
        cout << "   \\\\    _ _\^^^/_ _" << endl;
        cout << "    \\\\/ (    '-'  ( )" << endl;
        cout << "    /( \\/ | {&}   /\\ \\ " << endl;
        cout << "      \\\\  / \\     / _> )" << endl;
        cout << "       \"`   >:::;-'`\"\"'-." << endl;
        cout << "           /:::/         \\" << endl;
        cout << "          /  /||   {&}   |" << endl;
        cout << "         (  / (\         /" << endl;
        cout << "         / /   \'-.___.-'" << endl;
        cout << "   jgs _/ /     \\ \\" << endl;
        cout << "      /___|    /___|" << endl;
    }
};

class Pesado : public Minion {
public:
    void atacar() {
        cout << "       !" << endl;
        cout << "      .-." << endl;
        cout << "    __|=|__" << endl;
        cout << "   (_/`-`\\_)" << endl;
        cout << "   //\\___/\\\\ " << endl;
        cout << "   <>/   \\<>" << endl;
        cout << "    \\|_._|/" << endl;
        cout << "     <_I_>" << endl;
        cout << "      |||  " << endl;
        cout << "jgs  /_|_\\ " << endl;
    }
};


class Super : public Minion {
public:
    void atacar() {
    cout<<"        .==.        .==.  /|" << endl;
    cout<<"       //`^\\\\      //^`\\\\//" << endl;
    cout<<"      //^^^ ^(\\__/) ^^ ^//" << endl;
    cout<<"     //^ ^ ^^(6  6) ^  //\\\\ " << endl;
    cout<<"    //^^ ^/\\ |v""v| __//^ \\\\  " << endl;
    cout<<"   // ^/\\/ _/ `~~` |@\"/\^ ^\\\\ " << endl;
    cout<<"  \\\\^ /   // /IIIII\\_/  \\^ // " << endl;
    cout<<"   \\\\/    \\(((`II\"   /   \\// " << endl;
    cout<<"    ^   .--' /\\___/\\ `--. ^ " << endl;
    cout<<"jgs    (((--'       '--))) " << endl;
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
    
    cout << "Los Minions han sido creados:\n";

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << endl;
        }
        Inhibidor::crearMinion(1)->atacar();
        Sleep(500);
        system("cls");

    }

    for (size_t i = 0; i < 15; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << endl;
        }
        Inhibidor::crearMinion(2)->atacar();
        Sleep(500);
        system("cls");

    }
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << endl;
        }
        Inhibidor::crearMinion(3)->atacar();
        Sleep(500);
        system("cls");
    }

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << endl;
        }
        Inhibidor::crearMinion(0)->atacar();
        Sleep(500);
        system("cls");
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
