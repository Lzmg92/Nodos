#ifndef LISTA
#define LISTA

#include <iostream>
#include<stdlib.h>
using namespace std;

struct nodo{
    nodo* siguiente;
    nodo* anterior;
    int dato;

    nodo(int dato)
    {
        this->dato = dato;
        siguiente = anterior = NULL;
    }
};


struct lista{
    nodo* cabeza;
    nodo* cola;

    lista(){
        cabeza = cola = NULL;
            }


    bool vacia(){
        if (cabeza==NULL){
            return true;
        }else{
            return false;
        }
    }


    int Get(){
        if(!vacia()){
            int val = cabeza->dato;
            nodo *bor = cabeza;
                    if (cabeza == cola)
                    {
                        cabeza = NULL;
                        cola = NULL;
                    }
                    else
                    {
                        cabeza = cabeza->siguiente;
                    }
                    delete bor;
                    return val;
                }
                else
                    return -1;
        }




    void Insertar(nodo* nod){
            if(vacia()){
                cabeza = cola = nod;
            }  else {
                if(nod->dato < cabeza->dato){
                    InsertarFrente(nod);
                }else if(nod->dato > cola->dato){
                    InsertarAtras(nod);
                }else{
                    InsertarEnmedio(nod);
                }
            }
    }

     void InsertarFrente(nodo* nod){
        cabeza->anterior = nod;
        nod->siguiente = cabeza;
        cabeza = cabeza->anterior;
    }

    void InsertarAtras(nodo* nod){
        cola->siguiente = nod;
        nod->anterior = cola;
        cola = cola->siguiente;
    }

    void InsertarEnmedio(nodo* nod){
        nodo* temp1;
        nodo* temp2;
        temp1 = cabeza;

        while(temp1->dato < nod->dato){
            temp1 = temp1->siguiente;
           }

        temp2 = temp1->anterior;
        temp2->siguiente = nod;
        temp1->anterior = nod;
        nod->anterior = temp2;
        nod->siguiente = temp1;
    }

    void Recorrer(){
        nodo* temp;

        temp = cabeza;

        while(temp){
            cout << "el valor es: " << temp->dato << endl;
            temp = temp->siguiente;
        }
    }

};


#endif // LISTA

