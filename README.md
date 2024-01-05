# ECC--Cifrado-de-curva-eliptica
ECC se utiliza en algoritmos criptográficos como ElGamal, ECDSA (Algoritmo de Firma Digital de Curva Elíptica), y más.
La seguridad de ECC radica en la dificultad de resolver problemas matemáticos difíciles relacionados con las curvas elípticas.

Conceptos Básicos:
Ecuación de la Curva Elíptica:
La forma general de la ecuación de una curva elíptica sobre un cuerpo finito es: y^2=x^3+a.x+b
a y b son parámetros específicos de la curva.
Puntos (x, y) que satisfacen la ecuación forman la curva elíptica.
Punto Infinito:
Toda curva elíptica tiene un "punto en el infinito" que sirve como elemento neutro para la suma de puntos.
Operación de Suma de Puntos:
La suma de dos puntos (x1,y1) y (x2,y2) en la curva elíptica da como resultado un tercer punto (x3,y3).
La operación de suma está definida por reglas específicas dependiendo de la curva.

Generación de Claves:
La seguridad de ECC se basa en la dificultad del problema del logaritmo discreto elíptico.
Generar claves implica seleccionar un punto base G en la curva y multiplicarlo por una clave privada para obtener una clave pública (P=d⋅G).
Operación de Multiplicación Escalar:
La multiplicación escalar implica multiplicar un punto en la curva por un número entero (Q=k⋅P).
Este proceso se usa en la generación de claves y en operaciones criptográficas.
