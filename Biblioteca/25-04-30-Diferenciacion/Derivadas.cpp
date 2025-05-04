#include "Derivadas.h"  // Incluye el archivo de cabecera con las declaraciones

/**
 * Calcula la derivada usando diferencia hacia adelante (forward difference)
 * @param x Punto donde se evalúa la derivada
 * @param h Tamaño del paso (incremento)
 * @return Aproximación de f'(x) usando diferencia hacia adelante
 * 
 * Fórmula: f'(x) ≈ [f(x+h) - f(x)] / h
 * Error: O(h) (lineal)
 */
double forward_diff(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

/**
 * Calcula la derivada usando diferencia central (central difference)
 * @param x Punto donde se evalúa la derivada
 * @param h Tamaño del paso (incremento)
 * @return Aproximación de f'(x) usando diferencia central
 * 
 * Fórmula: f'(x) ≈ [f(x+h) - f(x-h)] / (2h)
 * Error: O(h²) (cuadrático)
 */
double central_diff(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}