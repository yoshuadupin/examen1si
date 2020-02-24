

#include <iostream>
#include <vector>
#include<string>
using namespace std;


class Subject {
    vector < class Observer* > views; 
    string value;
public:
    void attach(Observer* obs) {
        views.push_back(obs);
    }
    void setVal(string val) {
        value = val;
        cout << "Vuelos a " << val << " esta a punto de salir" << endl;
        notify();
    }
    string getVal() {
        return value;
    }
    void notify();
};

class Observer {
    Subject* model;
    string vuelo;
public:
    Observer(Subject* mod, string vue) {
        model = mod;
        vuelo = vue;
        model->attach(this);
    }
    virtual void update() = 0;
protected:
    Subject* getSubject() {
        return model;
    }
    string getVuelo() {
        return vuelo;
    }
};

void Subject::notify() {
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}



class EspanolObserver : public Observer {
public:
    EspanolObserver(Subject* mod, string vuelo) : Observer(mod, vuelo) {}
    void update() {
        string v = getSubject()->getVal();
        string d = getVuelo();
        if (v == d) {
            cout << "Hey ese es mi vuelo" << endl;
        }
        else {
            cout << "No ese no es mi vuelo" << endl;
        }
    }
};



class AmericanObserver : public Observer {
public:
    AmericanObserver(Subject* mod, string div) : Observer(mod, div) {}
    void update() {
        string v = getSubject()->getVal();
        string d = getVuelo();
        if (v == d) {
            cout << "That is my fly" << endl;
        }
        else {
            cout << "Not that is no my fly" << endl;
        }
    }
};
int main()
{
    Subject subj;
    AmericanObserver pedro(&subj, "China"); // 7. Client configures the number and
    EspanolObserver ana(&subj, "Argentina"); //    type of Observers
    AmericanObserver manuel(&subj, "China");
    subj.setVal("China");
    subj.setVal("Argentina");

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
