#include "Benchmark.h"
#include "Algorithm.h"

/*ALGORIMO DE LA BURBUJA*/

   void bubble( int *lista ,int N, Experiment*experiment){ /* datos se pasa por dirección, N es el número de elementos, Experimento *exp es puntero a la estructura Experimento */

         startCount(experiment); /* inicializamos la cuenta de tiempo relativo*/

         int i, j;
   
            for(i=0;i<N-1;i++){
               for(j=N-1;j>i;j--){    /* me voy al último elemento*/
                  if (compare(lista[j] < lista[j-1], experiment)){   /*comparamos y actualizamos el contador correspondiente*/
                  swap(&lista[j], &lista[j-1], experiment);/*Intercambiamos si es necesiario y actualizamos el contador correspondiente*/
               
                  }
               }
      
            }   
            endCount(experiment); /*finalizamos la medición del tiempo*/

      }
      
      
/*ALGORITMO DE INSERCIÓN*/
   void insertion( int *lista, int N, Experiment*experiment){ /* paso por dirección primer elemento de lista, N es el número de elementos, Experimento*exp puntero a estructura*/
 
   startCount(experiment);
  
      int i,j,aux;
         for(i=1; i<N;i++){
            aux= lista[i]; /* Guardo en aux el valor del elemento con clave i*/
            experiment -> movements++; /* aumento el contador de movimientos*/
            for(j=i-1;j>=0; j--){
                  if (compare(lista[j] > aux, experiment)){ /*Si el elemento con clave j (el anterior a i) es mayor que aux*/
                  lista[j+1]=lista[j]; /*En el elemento con clave j guardo el de clave j+1 (el siguiente)*/
                  experiment -> movements++;
                 
               }
               else{
                  break; /*en caso de que no sea mayor sacame del bucle j*/
               
               }
            }
            lista[j+1]=aux;
            experiment -> movements++;/*actualizo el valor de los movimientos*/
         }
         
           
       endCount(experiment); 
  
   
   }
   
   /*ALGORITMO DE SELECCIÓN*/
   
   void selection( int*lista, int N, Experiment*experiment){  
      startCount(experiment);/*Comienzo de la cuenta del tiempo*/
      int i,j,menor;
      for(i=0;i<N-1;i++){
         menor=i;
            for(j=i+1;j<N;j++){
            if (compare(lista[j] < lista[menor], experiment)){/*Comparación y actualización contador de comparaciones*/
               menor=j;
            }
            }
          if(menor!=i){
          swap(&lista[i], &lista[menor], experiment);/*Intercambio de números y actualización del contador de movimientos*/
            
          } 
      } 
     endCount(experiment);/*Finaliza la medida de tiempo relativo*/
   }
   
   
   /* ORDENACIÓN POR EL MÉTODO SHELL*/
   
     void Shell(int *lista, int N, Experiment * experiment){
      startCount(experiment);/*Comienzo de la cuenta del tiempo*/
      int i,j,aux,paso=1,k,h;
       
      /*En primer lugar se calcula el paso sabiendo que 2^k0 < N+1*/
      while(2*paso-1< N){ /*cálculo del paso inicial */
         paso=paso*2;          
      }
      /* lo combinaremos con el método de inserción*/
       
         for(h=paso;h>0;h=((h-1)/2)){ /*definimos h como el valor del salto para cada iteración*/
            for(k=0;k<h;k++){ 
               for(i=h+k; i<N;i+=h){
                  aux = lista[i];
                  experiment-> movements++; /* actualizo el número de movimientos*/
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
         endCount(experiment);/*Finaliza la medida de tiempo relativo*/
  
   
   }
   
   
   /*ORDENACIÓN POR EL MÉTODO DEL MONTÍCULO*/



   static void criba(int izq, int dcha, int *lista,Experiment * experiment){
      int i, doble,aux;
      aux=lista[izq];
      experiment-> movements++; /*Suma un movimiento */
      
      for(i=izq; doble= 2*i+1,doble<=dcha; i =doble){
        if(compare((doble<dcha && lista[doble] < lista[doble +1]),experiment)){/*Devuelve al if la expresión y aumenta el contador comparaciones*/
        
        /*caso de que sean dos comparaciones las que contar usar esto: */
        /* if((experiment->comparations+=2),(doble<dcha && lista[doble] < lista[doble +1]))*/
        
           doble++;
        }
        if(compare(aux<lista[doble],experiment)){
           lista[i]=lista[doble];
           experiment-> movements++; /*Suma un movimiento*/
        }
           else{
              break;
           }
      }
      lista[i]=aux;
      experiment-> movements++; /*Suma un movimiento*/
   }
   
   
   void heapsort( int *lista, int N, Experiment * experiment){
      startCount(experiment);/*Comienzo de la cuenta del tiempo*/
      int i;
      for(i=N/2 -1;i>=0;i--){
         criba(i,N-1,lista,experiment);
      }
      for(i=N-2;i>=0;i--){
         swap(lista[0],lista[i+1],experiment); /* intercambia los valores y suma tres movimientos*/
         criba(0,i,lista,experiment);
      }
      endCount(experiment);/*Finaliza la medida de tiempo relativo*/
   }
   
   
   /*ORDENACIÓN POR QUICKSORT*/
   
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
            swap(lista[i],lista[j],experiment);
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
     void quicksort(int *lista, int N,Experiment * experiment){ /* función para pasarle a quicksort la tabla a ordenar*/
      startCount(experiment);/*Comienzo de la cuenta del tiempo*/
      int first, last;
      first = 0;
      last = N-1;
      qs(lista,first, last, experiment);
      endCount(experiment);/*Finaliza la medida de tiempo relativo*/
   
   }
