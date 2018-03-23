#ifndef COST_H_
#define COST_H_

#include <stddef.h>

typedef float(*trans_ptr)(float,float);

typedef struct {
  trans_ptr transform;
  float coef;
} Cost;

float lin(float x, float y);
float quad(float x, float y);
float linlog(float x, float y);

#define TRANS (trans_ptr []) {lin,quad,linlog}
#define NTRANS 3

float regrex(float * x, float * y, unsigned int n, float * b0, float * b1, trans_ptr trans);

Cost identify(float * x, float * y, unsigned int n, trans_ptr * trans, unsigned int ntrans);

void costToString(Cost cost, char * c);

#endif
