# Importación de bibliotecas (seaborn comentado)
import matplotlib.pyplot as plt  # Para gráficos
import numpy as np  # Para manejo numérico
# import seaborn as sns  # Biblioteca alternativa de visualización (no usada)
# sns.set_context("poster")  # Configuración de seaborn (comentada)

# Lectura de datos desde archivo
# El archivo PAREJAS.txt debe tener 2 columnas:
# 1. Número de pareja (x)
# 2. Valor de la norma (y)
x, y = np.loadtxt("PAREJAS.txt", unpack=True)

# Configuración del gráfico
fig, ax = plt.subplots()  # Crea figura y ejes

# Graficado de la curva de normas:
# "-o" = línea continua con puntos marcados
ax.plot(x, y, "-o", label="NORMA")  

# Etiquetas de ejes (exactamente como las definiste):
ax.set_xlabel('Parejas')  # Eje X: Número de parejas
ax.set_ylabel('Norma')    # Eje Y: Valor de la norma

# Elementos adicionales:
ax.legend()  # Muestra leyenda con la etiqueta "NORMA"

# Guardado del gráfico:
fig.savefig('Norma.pdf')  # Guarda como PDF