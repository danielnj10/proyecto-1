import matplotlib.pyplot as plt
import numpy as np


data = np.loadtxt('funcion_de_onda.txt')
r = data[:, 0]
u = data[:, 1]


plt.plot(r, u, label='Función de onda')
plt.xlabel('r')
plt.ylabel('u')
plt.legend()
plt.show()
