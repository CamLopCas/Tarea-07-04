#pragma once  // Directiva del preprocesador para evitar inclusiones múltiples

#include <cmath>  // Para funciones matemáticas estándar

// Definición de un alias para punteros a funciones que toman double y devuelven double
using fptr = double(double);

/**
 * Calcula la derivada numérica usando diferencia hacia adelante
 * @param x Punto donde se evalúa la derivada
 * @param h Tamaño del paso (incremento)
 * @return Aproximación de f'(x) usando [f(x+h)-f(x)]/h
 */
double forward_diff(double x, double h);

/**
 * Calcula la derivada numérica usando diferencia central
 * @param x Punto donde se evalúa la derivada
 * @param h Tamaño del paso (incremento)
 * @return Aproximación de f'(x) usando [f(x+h)-f(x-h)]/(2h)
 */
double central_diff(double x, double h);