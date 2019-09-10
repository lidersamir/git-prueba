#/bin/python

import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

#metodo de euler tomando Y'=f(x,y) y h=(Xm+1 - Xm)
#Euler: Yn+1 = Yn + hY'n = Yn + hf(Xn, Yn)
#n: muestreso, espacio muestral, entre mayor sea el numero de pasos
#mejor es el resultado del metodo

def euler(xn, yn, h, MyF):
    return yn+(h*MyF(xn,yn))

def myfirstode(y,x):#en la libreria odei se debe definir la funcion con la
                    #primera entrada en y
    return x-y

def exactsolution (x):
    return x-1+2*np.exp(-x)

numpuntos=np.array([10, 100, 1000, 10000])
x0=0.
xf=5.
y0=1.0
h=(xf- x0)/numpuntos

y1_difference = []
yE_difference = []

totaleuler = []
totalexact = []
totalYS = []
totalXS = []

totaldifeuler = []
totaldifYS = []

for j in numpuntos:
    eulersolutions = []

    xs = np.linspace(x0, xf, j)

    eulersolutions.append(y0)

    for i in xs[1:]:# para descartar el valor x0 de la lista xs
        currentsolution = euler(i, eulersolutions[-1], ((xf-x0)/j), myfirstode)
        eulersolutions.append(currentsolution)


    ys = odeint(myfirstode, y0, xs)
    ys = np.array(ys).flatten()#¿para que sirve?

    y_exact = exactsolution(xs)

    totaldifeuler.append(np.abs(eulersolutions-y_exact))
    totaldifYS.append(np.abs(ys-y_exact))
    
    
    totaleuler.append(eulersolutions)
    totalexact.append(y_exact)
    totalYS.append(ys)
    totalXS.append(xs)

#en la grafica correspondiente a nuestro metodo de euler encontramos que el
#error es acumulativo


#plt.plot(totalXS[3], totalYS[3], "r")
#plt.plot(totalXS[3], totaleuler[3], "b")
#plt.plot(totalXS[3], totalexact[3], "g--")

plt.semilogy(totalXS[0], totaldifeuler[0], "r")#la grafica en semilogy no
                                               #nos permite visualizar mejor el error
plt.semilogy(totalXS[0], totaldifYS[0], "b")
#plt.plot(totalXS[3], totalexact[3], "g--")

plt.show()
