#include <iostream>

using namespace std;


//#############################################
//FUNCIONES

// las funciones void no retornan nada.
void sumasimple(int &a, int b)
{
  a = a+b;
}

//fuciones con asignaciones numericas

/*
double sumasimple(int a, int b)
{
  int c = a+b;
double l= 40.555;

  return l;
}
*/
//#############################################


int main()
{
  int t=2, k=8;
  cout << t << endl;
  sumasimple(t,k);// llama al espacio de memoria, directamente, de t y
  //opera directamente sobre el espacio en memoria.
  cout << t << endl;

  return 0;

}
