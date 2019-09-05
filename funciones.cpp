
#include <iostream>

using namespace std;


//#############################################
//FUNCIONES

// las funciones void no retornan nada.
void sumasimple(int &a, int b)
{
  a = a+b;
}


//fuciones con asignaciones numericas.

/*
double sumasimple(int a, int b)
{
  int c = a+b;
double l= 40.555;

  return l;
}
*/

// ESTRUCTURAS: generalizacion de tipos de datos.
struct posicionycarga
{
  int 
  Carga; //clases.
  float X;
  float Y;
  float Z;
} particula1, particula2;//instancias de las clases.


//CLASES: publico: en cualquier momento se puede acceder.
class particle
{
public:
  int Carga;
  float X, Y, Z;
  float VX, VY, VZ;
  float M;
  
  //metodos
  //estos reciben solo el tipo de variables
  //no poseen cuerpo definido
  void setvalues(float, float, float, float, float, float, float, int);
  float pos_evol( float,float,float, float);
} p1, p2;

void particle::setvalues(float x, float y, float z, float vx, float vy, float vz, float m, int carga)
{
  X=x;
  Y=y;
  Z=z;
  VX=vx;
  VY=vy;
  VZ=vz;
  M=m;
  Carga=carga;
}

float particle::pos_evol(float ax, float ay, float az, float t)
{
  X=X+(VX*t)*(0.5*ax*t*t);
  Y=Y+(VY*t)*(0.5*ay*t*t);
  Z=Z+(VZ*t)*(0.5*az*t*t);
  return t;
}


//#############################################


int main()
{
  int t=2, k=8;
  //cout << t << endl;
  sumasimple(t,k);// llama al espacio de memoria, directamente, de t y
  //opera directamente sobre el espacio en memoria.
  //cout << t << endl;

  posicionycarga * particula3;

    cout << particula1.Carga << " " << particula1.X << " " << particula1.Y << " " << particula1.Z << endl;
  
  particula1.Carga=0;
  particula1.X=10.1;
  particula1.Y=10.3;
  particula1.Z=10.5;

    cout << particula1.Carga << " " << particula1.X << " " << particula1.Y << " " << particula1.Z << endl;

    // cout << particula3->carga << " " << particula3->X << " " << particula3->Y << " " << particula3->Z << endl;

    //particula3->carga=0;
    //particula3->X=10.1;
    //particula3->Y=10.3;
    //particula3->Z=10.5;

  // trucazo cambiar una columna: ctrl_espace + cotrl_x + rt + caracter a
  //reemplazar

    particle particula4;

    cout << particula4.Carga << " " << particula4.X << " " << particula4.Y << " " << particula4.Z << endl;

    particula4.setvalues( 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 0);

      cout << particula4.Carga << " " << particula4.X << " " << particula4.Y << " " << particula4.Z << endl;

      particula4.pos_evol(1.0, 0.0, 0.0, 1.0);

         cout << particula4.Carga << " " << particula4.X << " " << particula4.Y << " " << particula4.Z << endl;
      
  return 0;

}
