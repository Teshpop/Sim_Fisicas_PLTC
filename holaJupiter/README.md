![Jupiter](https://i0.wp.com/www.intelligentliving.co/wp-content/uploads/2020/03/image_5608_2e-Jupiter.jpg?fit=1920%2C1182&ssl=1)

# Hola Jupiter

Simulacion de caida libre de una caja aplicando la fuerza de gravedad de jupiter.

## Explicacion del codigo 

Cambiamos la gravedad por la de jupiter para que asi nuestra caja se vea afectada por esta.

```c++
b2Vec2 gravity(0.0f, -24.79f);
```

Gracias a la modificacion de la densidad esta caja experimenta una mayor fuerza de la gravedad

```c++
fixtureDef.density = 30.0f;
```

## Resultados

Se puede observar que la caja cae de manera mucho mas rapida gracias a la gravedad de este planeta
acercandose aun mas a tocar el suelo gracias a la aceleracion

```c++
0.00 15.16 0.00
0.00 14.90 0.00
0.00 14.63 0.00
0.00 14.35 0.00
0.00 14.07 0.00
0.00 13.78 0.00
0.00 13.49 0.00
0.00 13.18 0.00
0.00 12.87 0.00
0.00 12.56 0.00
0.00 12.23 0.00
0.00 11.90 0.00
0.00 11.56 0.00
0.00 11.22 0.00
0.00 10.87 0.00
0.00 10.51 0.00
0.00 10.15 0.00
0.00 9.77 0.00
0.00 9.40 0.00
0.00 9.01 0.00
0.00 8.62 0.00
0.00 8.22 0.00
0.00 7.81 0.00
0.00 7.40 0.00
```