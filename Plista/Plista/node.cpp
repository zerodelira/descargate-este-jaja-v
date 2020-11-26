#include "node.h"

// Constructor por defecto

Node::Node()
{
    nombre=" ";
    clave = " ";
    descripcion = " ";
    precio = 0;
    cantidad = 0;
    
}

// Constructor por parametro

Node::Node(string _clave, string _nombre, string _descripcion, int _precio, int _cantidad)
{
    nombre = _nombre;
    clave = _clave;
    descripcion = _descripcion;
    precio = _precio;
    cantidad = _cantidad;
}

// Eliminar todos los Nodos
void Node::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}

// Imprimir un Nodo
void Node::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << data << "-> ";
}