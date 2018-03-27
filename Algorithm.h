#ifndef ALGORITHM_H_
#define ALGORITHM_H_


/*Ejecuta la ordenación de la burbuja al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void bubble( int *lista ,int N, Experiment*experiment);

/*Ejecuta la ordenación por inserción al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void insertion( int *lista, int N, Experiment*experiment);

/*Ejecuta la ordenación por selección al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void selection( int*lista, int N, Experiment*experiment);
   
   /*Ejecuta la ordenación por Shell al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void Shell(int *lista, int N, Experiment * experiment);
   
   /*Ejecuta la ordenación por montículo al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void heapshort( int *lista, int N, Experiment * experiment);
   
   /*Ejecuta la ordenación por quicksort al array lista de N elementos y guarda información en la estructura Experiment*/ 
   void quickshort(int *lista, int N,Experiment * experiment);
   
   #endif
