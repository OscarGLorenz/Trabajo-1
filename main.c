#define DEBUG

#include "Benchmark.h"
#include "Datacreator.h"
#include "Algorithm.h"
#include <stdio.h>

size_t nelements[] = {10, 100, 1000, 10000};
int num_nelement = 4;

algorithm_ptr algorithms[] = {bubble,insertion,selection,shell,heapsort, quicksort};
char algorithms_str[][30] = {"Burbuja", "Inserción", "Selección", "Shell", "Heapsort", "Quicksort"};
int num_algorithm = 6;

dataType types[] = {INCREASING, DECREASING, RANDOM, REPEATED};
char types_str[][30] = {"Creciente", "Decreciente", "Aleatorio", "Repetidos"};
int num_types = 4;

int main () {

  char ****  data = calculateTable(nelements,num_nelement,
                                    algorithms,num_algorithm,types,num_types);
                                    
  printf("Movements Comparations Time Memory\n");

  for (int i = 0; i < num_algorithm; i++) {
    printf("\t%s:\n", algorithms_str[i]);
    for (int j = 0; j < num_types; j++) {
      printf("%s:\t%s\t%s\t%s\t%s\n", types_str[j],
        data[i][j][0],  data[i][j][1], data[i][j][2], data[i][j][3]);
    }
  }

  freeTable(data, num_algorithm, num_types, 4);
  return(0);
}
