![Luna](https://static.ct10000.com/uploads/20221009/60177fb24bdb05c9ad043c220f2a54eb.png)

# Hola Luna

Simulacion de caida libre de una caja aplicando de la fuerza de la gravedad de la luna.

## Explicacion del codigo

El codigo de *Hola Mundo* puede ser reutilizado ya que vamos a utilizar los mismos objetos
que habiamos creado (el suelo y la caja), la unica modificacion importante que vamos a realizar 
es el cambio de la gravedad. 

```c++
b2Vec2 gravity(0.0f, -1.623f);
```

Hacemos el cambio de esta poniendo el de la luna (1.623) y con esto queda nuestro programa.

## Resultados 

Se puede notar una diferencia en nuestros resultados ya que el cubo esta callendo de 
forma mucho mas lenta aun gracias a ala gravedad de la luna.

Al ser un tiempo algo corto en nuestro bucle nuestra caja no llega a tocar ni a acercarce 
a nuestro suelo por su velocidad de caida.

```c++
0.00 19.57 0.00
0.00 19.55 0.00
0.00 19.53 0.00
0.00 19.51 0.00
0.00 19.49 0.00
0.00 19.47 0.00
0.00 19.45 0.00
0.00 19.43 0.00
0.00 19.40 0.00
0.00 19.38 0.00
0.00 19.35 0.00
0.00 19.33 0.00
0.00 19.31 0.00
0.00 19.28 0.00
0.00 19.25 0.00
0.00 19.23 0.00
0.00 19.20 0.00
0.00 19.17 0.00
```