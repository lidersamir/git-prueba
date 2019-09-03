/* OPERADORES.
    "direccion de": & : recupera la direccion de memoria de algo guardado.
    "desreferencia": * : *p quita la referencia y usa el valor de la variabl     e

   METODOS. 
    operador "."
    operador "->"

   (1)int_(2)x_(3)=_(4)10.25

    (1) tipo variable
    (2) identificador 
    (4) operador 
    (5) valor

  TIPOS DE VARIABLES.

   DATATYPE ---> Identificadores (esta toma mas tiempo de computo)

   DATATYPE* ---> Referencias (este llama directamente el espacio de memoria)


*/


#include <iostream>

using namespace std;


int main() {

  int x = 10;
  cout << x << " " << &x << endl;

  int * X=&x;// * var es un  puntero; apunta a la direccion de la variable.

  cout << x << " " << X << endl;

  x+=2;//modifica directamente el espacio de memoria para x
  
  cout << x << " " << &x << endl;
  cout << x << " " << X << endl;
  
  //memoria para X,
  //la memoria de la direccion de memoria se guarda en otro
  //espacio de memoria
  cout << X << " " << &X << endl;


  int ** XX=&X;// **var es un puntero de un puntero.

  cout << X << " " << XX << endl;

  
  // Ejemplos practicos.
  
  int a=1, b=2;

  int * p;
  
  cout << a << " " << b << " " << p << " " << *p << endl;

  p=&a;// las salidas de p modifican a a y viceversa

  cout << a << " " << b << " " << p << " " << *p << endl;

  *p=10;// modificamos el espacio de memoria correspondiente a a

  cout << a << " " << b << " " << p << " " << *p << endl;

  p=&b;//p igual a la direccion de memoria de b, desvincula la salida de p
  //de a y lo asigna a la direccion de b

  cout << a << " " << b << " " << p << " " << *p << endl;

  *p=20; // modifico el contenido de b
  
  cout << a << " " << b << " " << p << " " << *p << endl;



    return 0;

}
