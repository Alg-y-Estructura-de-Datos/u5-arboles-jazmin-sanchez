/*Sistema de inscripción en un gimnasio
Problema: Estás diseñando un sistema de inscripción para un gimnasio, donde cada socio
tiene un número de socio único. El sistema debe permitir la inscripción de nuevos socios, la
eliminación de socios que se dan de baja, y la búsqueda de socios activos.
● Tarea: Inscribe a los socios con los siguientes números de socio: 500, 250, 750, 100,
300, 600, 800.
● Desafío: Un socio con el número 250 se da de baja, así que elimínalo. Luego,
verifica si los socios con los números 300 y 750 aún están activos. Imprime la lista
de socios actualizada.*/
#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

int main() {
    ArbolBinario<int> gym;

    cout << "\nEstructura del sistema original : \n" <<endl;
    gym.put(500);
    gym.put(250);
    gym.put(750);
    gym.put(100);
    gym.put(300);
    gym.put(600);
    gym.put(800);

    gym.print();

    gym.remove(250);
    cout << "\nse da la baja del usuario: 250"<<endl;
    gym.print();

    int usuario = 0;

    try {
        usuario = gym.search(300);
        cout << "\nEl Usuario "<< usuario <<" esta activo en el gym." <<endl;
    } catch (int e) {
        if (e == 404) {
            cout << "\nEl Usuario  no está en el gym." <<endl;
        }
    }

    try {
        usuario = gym.search(700);
        cout << "\nEl Usuario "<< usuario <<" esta activo en el gym." <<endl;
    } catch (int e) {
        if (e == 404) {
           // int usuario = gym.search(700);
            cout << "\nEl Usuario no esta en el gym." <<endl;
        }
    }
    // Imprimir la estructura del árbol después de la eliminación
    cout << "\nEstructura del sistema: \n" <<endl;
    gym.print(); // Imprime el árbol en orden (en este caso, por IDs de libros)

    return 0;
}
