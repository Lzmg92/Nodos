#include <QCoreApplication>
#include "lista.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    lista* lis = new lista();

    lis->Insertar(new nodo(2));
    lis->Insertar(new nodo(9));
    lis->Insertar(new nodo(3));

    lis->Recorrer();

    cout << lis->Get() << endl;

    lis->Recorrer();

    cout << lis->Get() << endl;

    lis->Recorrer();


    return a.exec();
}
