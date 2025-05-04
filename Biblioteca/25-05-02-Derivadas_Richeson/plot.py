# Importación de bibliotecas (comentadas las líneas de seaborn)
import matplotlib.pyplot as plt  # Para creación de gráficos
import numpy as np  # Para manejo de arrays numéricos
# import seaborn as sns  # (Opción alternativa de visualización)
# sns.set_context("poster")  # (Configuración comentada de seaborn)

# Lectura de datos desde archivo
# El archivo debe tener 8 columnas en este orden exacto:
# x, h, forward_result, central_result, error_forward, error_central, 
# error_forward_richardson, error_central_richardson
x, h, fr, cr, fe, ce, rfe, rce = np.loadtxt("derivatives.txt", unpack=True)

# Configuración inicial del gráfico
fig, ax = plt.subplots()  # Crea figura y ejes

# Graficado de las curvas de error (sin cambios en estilos o parámetros):
ax.plot(h, fe, '-o', label='error forward')  # Error diferencia hacia adelante
ax.plot(h, ce, '-s', label='error central')  # Error diferencia central
ax.plot(h, rfe, '-*', label='error richardson forward')  # Error Richardson (forward)
ax.plot(h, rce, '-*', label='error richardson central')  # Error Richardson (central)

# Configuración de escalas logarítmicas (conservando tus parámetros):
ax.set_xscale('log')  # Eje X en escala logarítmica
ax.set_yscale('log')  # Eje Y en escala logarítmica

# Etiquetas de ejes (exactamente como las definiste):
ax.set_xlabel('$h$')  # Etiqueta del eje X (formato LaTeX)
ax.set_ylabel('error')  # Etiqueta del eje Y

# Leyenda y guardado (sin modificaciones):
ax.legend()  # Muestra leyenda con las etiquetas definidas
fig.savefig('deriv.pdf')  # Guarda la figura en PDF