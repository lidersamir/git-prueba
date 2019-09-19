#include <iostream>

using namespace std;


//#############################################
//FUNCIONES

// las funciones void no retornan nada.
void sumasimple(int &a, int b)
{
  a = a+b;
}

void Derivada(x,y)
{

}

void Rkt6(float y0, float x0)
{
  
  float h=0.5;
  float k1 = Derivada(x0, y0);
  float k2 = Derivada(x0 + h*c2, y0 + h*(a11*k) );
  float k3 = Derivada();
  float k4 = Derivada();
  float k5 = Derivada();
  float k6 = Derivada();
  
  float y1 = y0 + h*(b1*k1 + b2*k2 + b3*k3 + b4*k4 + b5*k5 + b6*k6);
}

  return 0;

}
