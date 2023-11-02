#include <stdio.h>
#include <math.h>

#define MAX_N 5   // Número máximo de funciones propias a calcular
#define L 10.0    // Longitud del intervalo
#define H 0.01    // Tamaño del paso

double potential(double x) {
    // Potencial del oscilador armónico cuántico
    return 0.5 * x * x;
}

void numerov(double* psi, double* E, int n) {
    double x, k1, k2, k3, k4;
    double h = H;
    double l = L;
    
    // Inicializamos los valores iniciales
    double x0 = 0.0;
    double psi0 = 1.0;
    double psi1 = 1.0 - h * h * (E[n] - potential(x0)) * psi0 / 2.0;
    psi[0] = psi0;
    psi[1] = psi1;
    
    for (int i = 2; i < (int)(l / h); i++) {
        x = x0 + i * h;
        k1 = h * h * (E[n] - potential(x - h/2.0)) * psi[i - 1] / 2.0;
        k2 = h * h * (E[n] - potential(x - h/2.0)) * (psi[i - 1] - k1/2.0) / 2.0;
        k3 = h * h * (E[n] - potential(x)) * (psi[i - 1] - k2/2.0) / 2.0;
        k4 = h * h * (E[n] - potential(x)) * (psi[i - 1] - k3);
        
        psi[i] = psi[i - 2] + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    }
}

int main() {
    int n_values[MAX_N] = {0, 1, 2, 3, 4};  // Valores de n para las funciones propias
    double energy[MAX_N];
    double psi[(int)(L / H)];
    
    FILE *dataFile = fopen("data.txt", "w");
    
    for (int i = 0; i < MAX_N; i++) {
        energy[i] = (i + 0.5);  // Energía inicial
        
        numerov(psi, energy, i);
        
        // Escribir los datos en un archivo
        for (int j = 0; j < (int)(L / H); j++) {
            double x = j * H;
            fprintf(dataFile, "%lf %lf\n", x, psi[j]);
        }
        fprintf(dataFile, "\n");
    }
    
    fclose(dataFile);
    
    

    return 0;
}
