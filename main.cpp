#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    string codigo;
};

struct Nodo {
    Estudiante dato;
    Nodo* siguiente;
};

class GestionTurnos {
private:
    Nodo* frente;
    Nodo* final;

public:
    GestionTurnos() : frente(nullptr), final(nullptr) {}

    void registrarEstudiante(string nombre, string codigo) {
        Nodo* nuevo = new Nodo();
        nuevo->dato.nombre = nombre;
        nuevo->dato.codigo = codigo;
        nuevo->siguiente = nullptr;

        if (frente == nullptr) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        cout << "Estudiante registrado: " << nombre << endl;
    }


    void atenderEstudiante() {
        if (frente == nullptr) {
            cout << "No hay estudiantes en espera." << endl;
            return;
        }
        Nodo* temp = frente;
        cout << "Atendiendo a: " << temp->dato.nombre << " (Codigo: " << temp->dato.codigo << ")" << endl;

        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;

        delete temp;
    }


    void mostrarEstudiantes() {
        if (frente == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        Nodo* actual = frente;
        int pos = 1;
        cout << "...Estudiantes en Espera..." << endl;
        while (actual != nullptr) {
            cout << pos << ". " << actual->dato.nombre << " [" << actual->dato.codigo << "]" << endl;
            actual = actual->siguiente;
            pos++;
        }
    }


    void buscarEstudiante(string nombre) {
        Nodo* actual = frente;
        int pos = 1;
        while (actual != nullptr) {
            if (actual->dato.nombre == nombre) {
                cout << "Estudiante " << nombre << " encontrado en la posicion: " << pos << endl;
                return;
            }
            actual = actual->siguiente;
            pos++;
        }
        cout << "Estudiante no encontrado." << endl;
    }
};

int main() {
    GestionTurnos sistema;
    int opcion = 0;
    string nom, cod;

 while (opcion != 5){

     cout << "Elija una opción: " <<endl;
        cout << "1. Registrar estudiante"<<endl;
        cout << "2. Atender estudiante"<<endl;
        cout << "3. Mostrar estudiantes en espera"<<endl;
        cout << "4. Buscar estudiante por nombre"<<endl;
        cout << "5. Salir"<<endl;
        cout << "Su opción" <<endl;

    cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Nombre: "; cin >> nom;
                cout << "Codigo: "; cin >> cod;
                sistema.registrarEstudiante(nom, cod);
                break;
            case 2:
                sistema.atenderEstudiante();
                break;
            case 3:
                sistema.mostrarEstudiantes();
                break;
            case 4:
                cout << "Nombre a buscar: "; cin >> nom;
                sistema.buscarEstudiante(nom);
                break;
            default:

            cout << "Opcion no valida intente de nuevo por favor"<<endl;

 };
}
    return 0;
}
