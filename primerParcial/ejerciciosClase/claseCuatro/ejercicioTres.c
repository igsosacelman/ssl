/*
    Haga un programa que permita ingresar las ordenadas al origen y pendientes de dos rectas:
    Y1 = a1 . X + b1
    Y2 = a2 . X + b2
    Y muestre como resultado la intersección de ambas rectas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float pendiente;
    float ordenada;
} Recta;

float interseccionRectas(Recta, Recta);
float funcionRecta(Recta,float);

int main (int argc, char* argv[]){
  Recta primerRecta, segundaRecta;
  printf("Ingrese los datos de la primer recta: \n");
  printf("Pendiente: ");
  scanf("%f", &primerRecta.pendiente);
  printf("Ordenada al origen: ");
  scanf("%f", &primerRecta.ordenada);
  printf("Pendiente: ");
  scanf("%f", &segundaRecta.pendiente);
  printf("Ordenada al origen: ");
  scanf("%f", &segundaRecta.ordenada);

  printf("Las rectas ingresadas son: \n");
  printf("1er recta: Y = %.1f . X + %.1f  \n", primerRecta.pendiente, primerRecta.ordenada);
  printf("2da recta: Y = %.1f . X + %.1f  \n", segundaRecta.pendiente, segundaRecta.ordenada);

  float interseccion = interseccionRectas(primerRecta, segundaRecta);

  printf("\nLa interseccion entre ambas rectas se da en el punto X = %.1f y Y = %.1f \n", interseccion, funcionRecta(primerRecta,interseccion) );

  return 0;
}
/*
    interseccion : 
        a1 . X + b1 = a2 . X + b2
    a1 . X - a2 . X = b2 - b1
                  X = b2 - b1 / a1 - a2
*/
float interseccionRectas(Recta r1, Recta r2){
    return (r2.ordenada - r1.ordenada) / (r1.pendiente - r2.pendiente); 
}

float funcionRecta(Recta r, float x){
    return (r.pendiente * x) + r.ordenada; 
}