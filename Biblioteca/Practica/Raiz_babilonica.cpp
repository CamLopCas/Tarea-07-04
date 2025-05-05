#include <iostream>
#include <cmath> // Para std::fabs (valor absoluto para floats)

using namespace std;

/**
 * Calcula la raíz cuadrada usando el método babilónico
 * @param S Número al que se le calculará la raíz
 * @param iteraciones Número de repeticiones del algoritmo
 * @return Aproximación de la raíz cuadrada de S
 */
double raiz_babilonica(double S, int iteraciones) {
    // Estimación inicial (puede ser S/2.0 o cualquier valor positivo)
    double x = S / 2.0;
    
    // Algoritmo babilónico (se repite 'iteraciones' veces)
    for (int i = 0; i < iteraciones; ++i) {
        x = (x + S / x) / 2.0; // Fórmula de actualización
    }
    
    return x;
}

int main() {
    double numero;
    int iteraciones;
    
    // Entrada de datos
    cout << "Ingrese el número para calcular su raíz cuadrada: ";
    cin >> numero;
    
    cout << "Ingrese el número de iteraciones: ";
    cin >> iteraciones;
    
    // Configuración de formato de salida
    cout.setf(ios::scientific); // Notación científica
    cout.precision(15);         // 15 dígitos decimales
    
    // Cálculo y muestra de resultados
    double resultado = raiz_babilonica(numero, iteraciones);
    cout << "La raíz cuadrada aproximada es: " << resultado << endl;
    
    // Comparación con el valor exacto (opcional)
    cout << "Valor exacto (sqrt): " << sqrt(numero) << endl;
    
    return 0;
}