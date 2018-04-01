#include <stddef.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "Cost.h"
#define EPS 0.01

float lin(float x, float y) {
  return y;
}

float quad(float x, float y) {
  return y/x;
}

float linlog(float x, float y) {
  return y/log(x);
}

float regrex(float * x, float * y, size_t n, float * b0, float * b1, trans_ptr trans) {
  float yT[n];

  for (size_t i = 0; i < n; i++)
      yT[i] = trans(x[i],y[i]);

  //Cálculo de las medias
  float meanX = 0, meanY = 0;
  for (size_t i = 0; i < n; i++) {
    meanY += yT[i];
    meanX += x[i];
  }
  meanX /= n; meanY /= n;

  //Cálculo de la pendiente de la recta de regresión
  float num = 0, denom = 0;
  for (size_t i = 0; i < n; i++) {
    num += (yT[i]-meanY)*(x[i]-meanX);
    denom += (x[i]-meanX)*(x[i]-meanX);
  }
  *b1 = num/denom;

  //Cálculo de la ordenada en el origen
  *b0 = meanY - *b1 * meanX;

  //Cálculo de los residuos
  float residue2 = 0;
  for (size_t i = 0; i < n; i++)
    residue2 += (*b0 + *b1 * x[i] - yT[i]) * (*b0 + *b1 * x[i] - yT[i]);
  return sqrt(residue2);
}

Cost identify(float * x, float * y, size_t n, trans_ptr * trans, size_t ntrans) {
    Cost cost;
    float b1[ntrans], b0[ntrans], res[ntrans];

    for (size_t i = 0; i < ntrans; i++) {
      res[i] = regrex(x,y,n,&b0[i],&b1[i],trans[i]);
      //printf("res=%.2f b0=%.2f b1=%.2f\n",res[i], b0[i], b1[i]);
    }
    //printf("\n");

    size_t less = 0;
    for (size_t i = 1; i < ntrans; i++)
      if (res[i] < res[less] && b1[i] >= EPS)
        less = i;

    cost.transform = trans[less];
    cost.coef = b1[less];
    return cost;
}

void costToString(Cost cost, char * c) {
  char type[10];
  if (cost.transform == lin) {
    strcpy(type,"O(n)");
  } else if (cost.transform == quad) {
    strcpy(type,"O(n^2)");
  } else if (cost.transform == linlog) {
    strcpy(type,"O(n log n)");
  }

  sprintf(c,"%.2f %s", cost.coef, type);
}

void costIdentification(Experiment * experiment, size_t n, char * mov_str, char * comp_str, char * nanos_str) {
  trans_ptr transformations[NTRANS] = TRANS;

  float comp_f[n], move_f[n], nanos_f[n], number_f[n];

  for (size_t i = 0; i < n; i++) {
    comp_f[i] = experiment[i].comparations;
    move_f[i] = experiment[i].movements;
    nanos_f[i] = nanos(&experiment[i]);
    number_f[i] = experiment[i].elements;
  }

  Cost comp_cost = identify(number_f, comp_f, n, transformations, NTRANS);
  Cost mov_cost = identify(number_f, move_f, n, transformations, NTRANS);
  Cost nanos_cost = identify(number_f, nanos_f, n, transformations, NTRANS);

  costToString(comp_cost, comp_str);
  costToString(mov_cost, mov_str);
  costToString(nanos_cost, nanos_str);
}
