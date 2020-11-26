#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;


class Node
{
public:
    Node();
    Node(string clave, string nombre, string descripcion, int precio, int cantidad);
    ~Node();

    Node* next;
    T data;

    void delete_all();
    void print();

private:
    string clave, nombre, descripcion;
    int precio, cantidad;
};

#endif // NODE_H