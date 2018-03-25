#ifndef COST_H_
#define COST_H_

#include <stddef.h>
#include "Benchmark.h"

typedef float(*trans_ptr)(float,float);

typedef struct {
  trans_ptr transform;
  float coef;
} Cost;

float lin(float x, float y);
float quad(float x, float y);
float linlog(float x, float y);

#define TRANS {lin,quad,linlog}
#define NTRANS 3

float regrex(float * x, float * y, size_t n, float * b0, float * b1, trans_ptr trans);

Cost identify(float * x, float * y, size_t n, trans_ptr * trans, size_t ntrans);

void costToString(Cost cost, char * c);

void costIdentification(Experiment * experiment, size_t n, char * mov_str, char * comp_str, char * nanos_str);

#endif
