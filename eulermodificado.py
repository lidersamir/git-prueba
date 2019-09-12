#/bin/python

import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

#metodo de euler tomando Y'=f(x,y) y h=(Xm+1 - Xm)
#Euler: Yn+1 = Yn + hY'n = Yn + hf(Xn, Yn)
#n: muestreso, espacio muestral, entre mayor sea el numero de pasos
#mejor es el resultado del metodo

def euler(xn, yn, h, MyF):
    return yn+(h*MyF(yn,xn))

def myfirstode(y,x):#en la libreria odei se debe definir la funcion con la
                    #primera entrada en y
    return x-y

def exactsolution (x):
    return x-1+2*np.exp(-x)

def euler_mod (xn, yn, h, MyF):##euler modificado
    yn2=yn+0.5*h*MyF(yn, xn)
    xn2=xn+0.5*h
    return yn+h*MyF(yn2, xn2)

numpuntos=np.array([10, 100, 1000, 10000])
x0=0.
xf=5.
y0=1.0
h=(xf- x0)/numpuntos

y1_difference = []
yE_difference = []
yEM_difference = []

totaleulermod = []##euler modificado
totaleuler = []
totalexact = []
totalYS = []
totalXS = []


totaldifeuler = []
totaldifYS = []
totaldifXS = []
totaldifeulermod = []##euler modificado


for j in numpuntos:
    eulersolutions = []
    eulermodsolutions = []##euler modificado
    xs = np.linspace(x0, xf, j)

    eulersolutions.append(y0)
    eulermodsolutions.append(y0)##euler modificado

    for i in xs[1:]:# para descartar el valor x0 de la lista xs
        currentsolution = euler(i, eulersolutions[-1], ((xf-x0)/j), myfirstode)
        eulersolutions.append(currentsolution)

        currentsolutionmod = euler_mod(i, eulermodsolutions[-1], ((xf-x0)/j), myfirstode)##euler modificado
        eulermodsolutions.append(currentsolutionmod)##euler modificado


    ys = odeint(myfirstode, y0, xs)
    ys = np.array(ys).flatten()#¿para que sirve?

    y_exact = exactsolution(xs)

    totaldifeuler.append(np.abs(eulersolutions-y_exact))
    totaldifYS.append(np.abs(ys-y_exact))
    totaldifeulermod.append(np.abs(eulermodsolutions-y_exact))

    totaleulermod.append(eulermodsolutions)
    totaleuler.append(eulersolutions)
    totalexact.append(y_exact)
    totalYS.append(ys)
    totalXS.append(xs)

    y1_difference.append(np.mean(np.abs(ys-y_exact)))
    yE_difference.append(np.mean(np.abs(eulersolutions-y_exact)))
    yEM_difference.append(np.mean(np.abs(eulermodsolutions-y_exact)))
    
    
#en la grafica correspondiente a nuestro metodo de euler encontramos que el
#error es acumulativo
fig = plt.figure(figsize(0,4))

ax0 = fig_add_subplot(121)
ax1 = fig_add_subplot(122)
ax2 = fig_add_subplot(123)

ax0.plot(totalXS[3], totalYS[3], "r")
ax0.plot(totalXS[3], totaleuler[3], "b")
ax0.plot(totalXS[3], totalexact[3], "g--")
ax0.plot(totalXS[3], totaleulermod[3])


ax1.semilogy(totalXS[3], totaldifeuler[3], "r")#la grafica en semilogy no
                                               #nos permite visualizar mejor el error
ax1.semilogy(totalXS[3], totaldifYS[3], "b")

ax1.semilogy(totalXS[3], totaldifeulermod[3], "g--")


ax2.plot(totalXS[3], y1_difference, "r")
ax2.plot(totalXS[3], yE_difference, "b")
ax2.plot(totalXS[3], yEM_difference, "g--")


plt.show()
