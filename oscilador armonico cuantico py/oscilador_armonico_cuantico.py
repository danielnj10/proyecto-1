import numpy as np
import matplotlib.pyplot as plt
from scipy.special import hermite
from scipy.special import factorial


m = 1.0  
omega = 1.0  
hbar = 1.0  


def wave_function(x, n):
    prefactor = 1.0 / (np.sqrt(2**n * factorial(n))) * (m * omega / (np.pi * hbar))**0.25
    hermite_term = hermite(n)(np.sqrt(m * omega / hbar) * x)
    gaussian_term = np.exp(-0.5 * m * omega * x**2 / hbar)
    return prefactor * hermite_term * gaussian_term


x = np.linspace(-5, 5, 1000)


for n in range(4):
    psi = wave_function(x, n)
    plt.plot(x, psi, label=f'n = {n}')

plt.title('Función de Onda del Oscilador Armónico Cuántico')
plt.xlabel('x')
plt.ylabel('Psi(x)')
plt.legend()
plt.grid()
plt.show()


for n in range(4):
    psi = wave_function(x, n)
    probability = psi**2
    plt.plot(x, probability, label=f'n = {n}')

plt.title('Probabilidad del Oscilador Armónico Cuántico')
plt.xlabel('x')
plt.ylabel('Probabilidad')
plt.legend()
plt.grid()
plt.show()
