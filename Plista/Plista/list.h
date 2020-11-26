#pragma once
#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "node.h"
#include "node.cpp"

using namespace std;


class List
{
public:
    List();
    ~List();

    void add_head(Node *nodo);
    void add_end(Node *nodo);
    void add_sort(Node *nodo);
    void concat(List);
    void del_all();
    void del_by_data(Nodo *nodo);
    void del_by_position(int);
    void fill_by_user(int);
    void intersection(List);
    void invert();
    void load_file(string);
    void print();
    void save_file(string);
    void search(Node *nodo);
    void sort();

private:
    Node* m_head;
    int m_num_nodes;
};

#endif // LIST_H