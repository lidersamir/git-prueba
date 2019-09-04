/*
este es mi primer
bloque de comentarios
muy largo
*/

#include <iostream>
using namespace std;
/*
esta linea sirve para especificar el uso origen de las funciones "std" y 
da la posibilidad de quitar este del codigo.

lo que se ejecuta siempre va dentro del main de lo contrario 
no se va a ejecutar.
*/

int main()
{
  std::cout << "hola mundo!" << std::endl; //comentario al final de la linea


/*
cout: manda a imprimir

<<: redirecciona la salida 

endl: termina la linea

std: librerias estandar de c++

:: : llamar una funcion de una libreria

; : siempre finaliza las lineas, equivale a la tabulacion a python

una funcion de tipo "int" siempre debe retornar algo, en este caso 
"return 0", este siempre debe ir al final de todo lo que se vaya a ejecutar


*/

  //tipos de variables
//las variables en C++ se deben declarar los tipos de variables
  
  int a = 3; // 10 digitos + signo
  int b;
  
  float c = 0.95; // esta variable tiene 7 digitos + signo
  double DD = 15.85451543; // 15 digitos + signo

  bool BB = true; // true o false, el "true" saca 1 y "false" 0
    
  std::cout << a << " " << b << " " << c << " " << DD << " " << BB << " " <<std::endl;

  //Operadores
  // +, -, *, /, % (solo sobre enteros)

  cout << a%22 << endl;

  //Relaciones
  // <, >, <=, >=, == !=

  //Logicos
  // || -> OR, && -> AND, ! -> NOT

  //ejemplo

  bool w1, w2;
  w1 = true; w2 = false;

  cout << (w1&&w2) << " " << (w1||w2) << " " << (!w1) << endl;

  //Otros
  // ++, --, +=, -=, *=, /=, %=

  cout << a << " " << (a+=2) << " " << (a*=2) << endl;

  //jueves 29/08/2019

  //tarea decir por que el ultimo print da 8 8 8, a debe ser 3.

  //condicionales

  //if, else , else if, (if, else, elif de python)

  a=0;

  if (a<=3 && a>1)
    {
     cout << a << " " << endl;
    }
  else if (a<1)
    {
      cout << a << "a es menor que 1 " << endl;
    }
  else
    {
     cout << a << "a no es igual a 3" << endl;
    }


  //BUCLES
  //while, for

  
  
  return 0;
}
