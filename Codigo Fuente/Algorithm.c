/********************************
* ARCHIVO:		Algorithm.c
*
* AUTOR:	Alejandro Redondo
*********************************/
/* LIBRERIAS:
 * Algorithm.h incluye la arquitectura de las funciones
 * Benchmark.h incluye la estructura Experiment dónde se almacenan
 * los contadores de número de comparaciones, intercambios...
 * Además en esta libreria están definidas:
 * startCount: inicializa la cuenta de tiempo
 * endCount: finaliza la cuenta de tiempo
 * swap: intercambia dos valores y actualiza el contador intercambios
 * compare: compara dos valores y actualiza el contador comparaciones
 */
 

/* NOTAS:
 * en ciertas funciones para actualizar el valor de los contadores
 * se accede directamente a la estructura y no a través de swap o compare
 * experiment -> movements++ 
 */
 
#include "Algorithm.h"

/*ALGORITMO DE LA BURBUJA*/

/* Función: bubble
 * Ejecuta el algoritmo de la burbuja
 * lista: array de datos a ordenar
 * N: número de elementos a ordenar
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
*/ 

   void bubble( int *lista ,int N, Experiment*experiment){ 
         startCount(experiment); 

         int i, j;

            for(i=0;i<N-1;i++){
               for(j=N-1;j>i;j--){    
                  if (compare(lista[j] < lista[j-1], experiment)){   
                  swap(&lista[j], &lista[j-1], experiment);
               
                  }
               }
      
            }   
            endCount(experiment); 

      }
      
/*ALGORITMO POR MÉTODO DE INSERCIÓN*/    

/* Función: insertion
 * Ejecuta el algoritmo de ordenación por el método de inserción
 * lista: array de datos a ordenar
 * N: número de elementos a ordenar
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
*/ 
   void insertion( int *lista, int N, Experiment*experiment){ 
         startCount(experiment);
  
         int i,j,aux;
            for(i=1; i<N;i++){
               aux= lista[i]; 
               experiment -> movements++; 
               for(j=i-1;j>=0; j--){
                     if (compare(lista[j] > aux, experiment)){ 
                     lista[j+1]=lista[j]; 
                     experiment -> movements++;
                 
                  }
                  else{
                     break; 
               
                  }
               }
               lista[j+1]=aux;
               experiment -> movements++;
            }
         
           
       endCount(experiment); 
  
   
   }
/*ALGORITMO POR MÉTODO DE SELECCIÓN*/

/* Función: selection
 * Ejecuta el algoritmo de ordenación por el método de selección
 * lista: array de datos a ordenar
 * N: número de elementos a ordenar
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
*/ 
   
   void selection( int*lista, int N, Experiment*experiment){  
      startCount(experiment);
      int i,j,menor;
      for(i=0;i<N-1;i++){
         menor=i;
            for(j=i+1;j<N;j++){
            if (compare(lista[j] < lista[menor], experiment)){
               menor=j;
            }
            }
          if(menor!=i){
          swap(&lista[i], &lista[menor], experiment);
            
          } 
      } 
     endCount(experiment);
   }
   
/*ALGORITMO POR MÉTODO DE SHELL*/
   
/* Función: Shell
 * Ejecuta el algoritmo de ordenación por el método de Shell
 * lista: array de datos a ordenar
 * N: número de elementos a ordenar
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
 * En primer lugar se calcula el paso sabiendo que 2^k0 < N+1
*/
   
     void shell(int *lista, int N, Experiment * experiment){
      startCount(experiment);
      int i,j,aux,paso=1,k,h;
       
      
      while(2*paso-1< N){ 
         paso=paso*2;          
      }
            
         for(h=paso;h>0;h=((h-1)/2)){ /*definimos h como el valor del salto para cada iteración*/
            for(k=0;k<h;k++){
               for(i=h+k; i<N;i+=h){
                  aux = lista[i];
                  experiment-> movements++; 
                  for(j=i-h;j>=0; j-=h){
                     if(compare(lista[j]>aux, experiment)){
                     lista[j+h]=lista[j];
                     experiment-> movements++;
                     }
                     else{
                        break;
                     }
                  }
                  lista[j+h]=aux;
                  experiment-> movements++;

               }
            }
         }
         endCount(experiment);
  
   
   }
    
/*ALGORIMTO DEL MONTÍCULO*/

/* Función: criba
 * realiza la criba del método del montículo ordenando el vector
*/
  
   static void criba(int izq, int dcha, int *lista,Experiment * experiment){
	  
      int i, doble,aux;
      aux=lista[izq];
      experiment-> movements++; 
      
      for(i=izq; doble= 2*i+1,doble<=dcha; i =doble){
        if(compare((doble<dcha && lista[doble] < lista[doble +1]),experiment)){
           doble++;
        }
        if(compare(aux<lista[doble],experiment)){
           lista[i]=lista[doble];
           experiment-> movements++; 
        }
           else{
              break;
           }
      }
      lista[i]=aux;
      experiment-> movements++; 
   }
   
/* Función: heapsort
 * Ejecuta el algoritmo de ordenación por el método del montículo
 * lista: array de datos a ordenar
 * N: número de elementos a ordenar
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
*/  

   void heapsort( int *lista, int N, Experiment * experiment){
      startCount(experiment);
      int i;
      for(i=N/2 -1;i>=0;i--){
         criba(i,N-1,lista,experiment);
      }
      for(i=N-2;i>=0;i--){
         swap(&lista[0],&lista[i+1],experiment); 
         criba(0,i,lista,experiment);
      }
      endCount(experiment);
   }

/*ALGORITMO POR MÉTODO DE QUICKSORT*/

/* Función: qs
 * Realiza la ordenación por el método quicksort
 * lista: array de datos a ordenar
 * first: primer elemento de la tabla
 * last último elemento de la tabla
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
*/  
      
   static void qs(int *lista, int first, int last,Experiment * experiment){
      int i= first, j = last, pivote;
      pivote=lista[(first + last)/2];
      do{
         while(compare((lista[i]<pivote && i< last),experiment)){
            i++;
         }
         while(compare((lista[j] > pivote && j > first), experiment)){
            j--;
         }
         if(i<=j){
            swap(&lista[i],&lista[j],experiment);
            i++; j--;
         }
       }   while(i<=j);
       if(first<j){
          qs(lista,first,j,experiment);
       }
       if(i<last){
          qs(lista,i,last,experiment);
       }
   }
/* Función: quicksort
 * Prepara los argumentos de la función qs y se los pasa a esta
 * lista: array de datos a ordenar
 * N: número de elementos a ordenar
 * Experiment: puntero a la estructura donde se guardan los parámetros medidos
*/  
     void quicksort(int *lista, int N,Experiment * experiment){ 
        startCount(experiment);
        int first, last;
        first = 0;
        last = N-1;
        qs(lista,first, last, experiment);
        endCount(experiment);
   
   }
