#include <stdio.h>
#include "Benchmark.h"
#include <math.h>

float regrex(float * x, float * y, unsigned int n, float * b0, float * b1) {
  //Cálculo de las medias
  float meanX = 0, meanY = 0;
  for (unsigned int i = 0; i < n; i++) {
    meanY += y[i];
    meanX += x[i];
  }
  meanX /= n; meanY /= n;

  //Cálculo de la pendiente de la recta de regresión
  float num = 0, denom = 0;
  for (unsigned int i = 0; i < n; i++) {
    num += (y[i]-meanY)*(x[i]-meanX);
    denom += (x[i]-meanX)*(x[i]-meanX);
  }
  *b1 = num/denom;

  //Cálculo de la ordenada en el origen
  *b0 = meanY - *b1 * meanX;

  //Cálculo de los residuos
  float residue2 = 0;
  for (unsigned int i = 0; i < n; i++)
    residue2 += (*b0 + *b1 * x[i] - y[i]) * (*b0 + *b1 * x[i] - y[i]);
  return sqrt(residue2);
}

void complejidad(float * x, float * y, size_t n) {
  float b1, b0, res, y2[n];

  printf("RESIDUO   COSTE\n");

  //Lineal
  res =  regrex(x, y, n, &b0, &b1);
  printf("%.2f     (%+.2f%+.2f)O(n)\n", res, b0, b1);

  //Cuadrático
  for (size_t i = 0; i < n; i++)
    y2[i] = y[i]/x[i];
  res =  regrex(x, y2, n, &b0, &b1);
  printf("%.2f     (%+.2f%+.2f)O(n^2)\n", res, b0, b1);

  //Logaritmico
  for (size_t i = 0; i < n; i++)
    y2[i] = y[i]/log(x[i]);
  res =  regrex(x, y2, n, &b0, &b1);
  printf("%.2f     (%+.2f%+.2f)O(n^2)\n", res, b0, b1);


}

int main(int argc, char const *argv[]) {
  float x[] = {2,3,4,5,6};
  float y[] = {4,9,16,25,36};

  complejidad(x,y,5);
  return 0;
}
