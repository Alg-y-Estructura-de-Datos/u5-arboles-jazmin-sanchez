/*: En una tienda de electrónica, cada producto tiene un código único y quieres
gestionar el inventario. A medida que entran y salen productos, es necesario mantener el
sistema actualizado.
● Tarea: Inserta los productos con los siguientes códigos: 4001, 2002, 6003, 1500,
3500, 5000, 7000.
● Desafío: Un cliente compró los productos con códigos 2002 y 6003, así que
elimínalos del sistema. Luego, un nuevo producto con el código 2500 llega al
inventario. Imprime el inventario actualizado y verifica si el código 4001 todavía está
en el sistema.*/
#include <iostream>
#include "Arbol/ArbolBinario.h"
using namespace std;

int main() {
    // Crear el árbol binario
    ArbolBinario<int> tienda;

    // Insertar los libros en el sistema de gestión
    std::cout << "\nEstructura del sistema original : \n" << std::endl;
    tienda.put(4001);
    tienda.put(2002);
    tienda.put(6003);
    tienda.put(1500);
    tienda.put(3500);
    tienda.put(5000);
    tienda.put(7000);

    tienda.print();

    tienda.remove(2002);
    tienda.remove(6003);
    std::cout << "\nse eliminaron dos productos, 6003 y 2002." << std::endl;
    tienda.print();

    std::cout << "\nSe agrega nuevo producto: (2500) \n" << std::endl;
    tienda.put(2500);

    try {
        int producto = tienda.search(4001);
        std::cout << "\nEl producto "<< producto <<" esta en la tienda: " << std::endl;
    } catch (int e) {
        if (e == 404) {
            std::cout << "\nEl producto 4001 no está en la tienda." << std::endl;
        }
    }
    // Imprimir la estructura del árbol después de la eliminación
    std::cout << "\nEstructura del sistema: \n" << std::endl;
    tienda.print(); // Imprime el árbol en orden (en este caso, por IDs de libros)

    return 0;
}
