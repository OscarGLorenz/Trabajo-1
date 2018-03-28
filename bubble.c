/*Algoritmo de ordenación- método de la burbuja*/

/*ALGORIMO ADAPTADO AL BENCHMARK*/

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

/*ALGORITMO SIN ADAPTAR AL BENCHMARK*/

/*
void bubble( int *lista ,int N, Experimento*exp){ 

      int i, j, aux;
   
         for(i=0;i<N-1;i++){
            for(j=N-1;j>i;j--){    
               if(lista[j]<lista[j-1]){   
               aux=lista[j];
               lista[j]=lista[j-1];
               lista[j-1]=aux;
               }
            }
      
         }   

   }/*
   

/*PRUEBA DEL ALGORITMO*/
/* #include <stdio.h>

   void bubble( int *lilsta ,int N){ 

      int i, j, aux;
   
         for(i=0;i<N-1;i++){
            for(j=N-1;j>i;j--){
               if(lista[j]<lista[j-1]){
               aux=lista[j];
               lista[j]=lista[j-1];
               lista[j-1]=aux;
               }
            }
      
         }   

   }
   
   int main(){
   int A[6] ={1, 8, 5, 2, 9, 7};
   int k;
   bubble(A,6);
   for(k=0;k<6;k++){
  int a=A[k];
      printf("%i\n",a);
   }
   
   }*/
