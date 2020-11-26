#include "list.h"
#include <time.h>
 
using namespace std;
 
// Constructor por defecto
List::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}
 
// Insertar al inicio
void List::add_head(Node* nodo);
{
    Node aux = new Node (nodo);
    Node *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;
 
        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}
 
// Insertar al final
void List::add_end(Nodo *nodo)
{
    Node aux = new Node (nodo);
    Node *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}
 
// Insertar de manera ordenada
void List::add_sort(Nodo *nodo)
{
    Node aux = new Node (nodo);
    Node *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        if (m_head->data > data_) {
            new_node->next = m_head;
            m_head = new_node;
        } else {
            while ((temp->next != NULL) && (temp->next->data < data_)) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    m_num_nodes++;
}
 
// Concatenar a otra List
void List::concat(List list)
{
    Node *temp2 = list.m_head;
 
    while (temp2) {
        add_end(temp2->data);
        temp2 = temp2->next;
    }
}
 
// Eliminar todos los nodos
void List::del_all()
{
    m_head->delete_all();
    m_head = 0;
}
 
// Eliminar por data del nodo
void List::del_by_data(Nodo *nodo)
{
    Node *temp = m_head;
    Node *temp1 = m_head->next;
 
    int cont = 0;
 
    if (m_head->data == nodo) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->data == data_) {
                Node *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
 
    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}
 
// Eliminar por posición del nodo
void List::del_by_position(int pos)
{
    Node *temp = m_head;
    Node *temp1 = temp->next;
 
    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}
 
// Llenar la Lista por teclado
void List::fill_by_user(int dim)
{
    T ele;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        add_end(ele);
    }
}
 

// Usado por el método intersección
void insert_sort(int  a[], int size)
{
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i-1; j>= 0 && a[j+1] < a[j]; j--) {
            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }
}
 
// Números que coinciden en 2 Lists
void List::intersection(List list_2)
{
    Node *temp = m_head;
    Node *temp2 = list_2.m_head;
 
    // Creo otra Lista
    List intersection_list;
 
    int num_nodes_2 = list_2.m_num_nodes;
    int num_inter = 0;
 
    // Creo 2 vectores dinámicos
    Node *v1 = new Node[m_num_nodes];
    Node *v2 = new Node[num_nodes_2];
 
    // Lleno los vectores v1 y v2 con los datas de la lista original y segunda lista respectivamente
    int i = 0;
 
    while (temp) {
        v1[i] = temp->data;
        temp = temp->next;
        i++;
    }
 
    int j = 0;
 
    while (temp2) {
        v2[j] = temp2->data;
        temp2 = temp2->next;
        j++;
    }
 
    // Ordeno los vectores
    insert_sort(v1, m_num_nodes);
    insert_sort(v2, num_nodes_2);
 
    // Índice del 1er vector (v1)
    int v1_i = 0;
 
    // Índice del 2do vector (v2)
    int v2_i = 0;
 
  // Mientras no haya terminado de recorrer ambas Lists
  while (v1_i < m_num_nodes && v2_i < num_nodes_2) {
      if (v1[v1_i] == v2[v2_i]) {
          intersection_list.add_end(v1[v1_i]);
          v1_i++;
          v2_i++;
          num_inter++;
      } else if (v1[v1_i] < v2[v2_i]) {
          v1_i++;
      } else {
          v2_i++;
      }
  }
 
  // Solo si hay alguna intersección imprimo la nueva lista creada
  if (num_inter > 0) {
      cout << "Existen " << num_inter << " intersecciones " << endl;
      intersection_list.print();
  } else {
      cout << "No hay intersección en ambas listas" << endl;
  }
}
 
// Invertir la lista
void List::invert()
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *temp = m_head;
 
    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    m_head = prev;
}
 
// Cargar una lista desde un archivo

void List::load_file(string file)
{
    Node line;
    ifstream in;
    in.open(file.c_str());
 
    if (!in.is_open()) {
        cout << "No se puede abrir el archivo: " << file << endl << endl;
    } else {
        while (in >> line) {
            add_end(line);
        }
    }
    in.close();
}
 
// Imprimir la Lista
void List::print()
{
    Node *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}
 
// Buscar el dato de un nodo
void Lista::search(Node *nodo)
{
    Node *temp = m_head;
    int cont = 1;
    int cont2 = 0;
 
    while (temp) {
        if (temp->data == nodo) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }
 
    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
 
// Ordenar de manera ascendente
void List::sort()
{
    Node temp_data;
    Node *aux_node = m_head;
    Node *temp = aux_node;
 
    while (aux_node) {
        temp = aux_node;
 
        while (temp->next) {
            temp = temp->next;
 
            if (aux_node->data > temp->data) {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }
 
        aux_node = aux_node->next;
    }
}
 
// Guardar una lista en un archivo
template<typename T>
void List::save_file(string file)
{
    Node *temp = m_head;
    ofstream out;
    out.open(file.c_str());
 
    if (!out.is_open()) {
        cout << "No se puede guardar el archivo " << endl;
    } else {
        while (temp) {
            out << temp->data;
            out << " ";
            temp = temp->next;
        }
    }
    out.close();
}