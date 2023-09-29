# Hola Bala

Simulacion de una bala bajo la fuerza de gravedad de la luna.

## Explicacion de codigo 

* Definición de la gravedad: Se establece la gravedad en gravity con una aceleración hacia arriba de -1.62 m/s².

* Creación del mundo: Se crea un mundo físico (b2World) utilizando la gravedad definida.

* Creación del cuerpo dinámico: Se define un cuerpo dinámico para representar la bala. Se establece su posición inicial en (0, 0).

* Definición de la forma de la bala: Se crea una forma rectangular (b2PolygonShape) para representar la bala con dimensiones de 0.2 unidades de ancho y 0.05 unidades de alto.

* Definición de las propiedades de la bala: Se configuran las propiedades físicas de la bala, como su densidad y coeficiente de fricción.

* Asignación de velocidad inicial: Se calculan las componentes de la velocidad inicial (vx y vy) en función del ángulo y la velocidad de la bala y se asignan al cuerpo.

* Simulación del mundo: Se realiza la simulación del mundo durante 60 iteraciones. En cada iteración, se llama a world.Step para avanzar la simulación en incrementos de tiempo (timeStep). Se imprime la posición del cuerpo en cada paso.

* Destrucción del cuerpo: Al finalizar la simulación, se destruye el cuerpo de la bala para liberar recursos.