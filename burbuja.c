/*Algoritmo de ordenación- método de la burbuja*/


void burbuja( int *lista ,int N, Experimento*exp){ /* datos se pasa por dirección, N es el número de elementos, Experimento *exp es puntero a la estructura Experimento */

      int i, j, aux;
   
         for(i=0;i<N-1;i++){
            for(j=N-1;j>i;j--){    /* me voy al último elemento*/
               if(lista[j]<lista[j-1]){   /* lo comparo con el anterior y si es necesario lo cambio*/
               aux=lista[j];
               lista[j]=lista[j-1];
               lista[j-1]=aux;
               }
            }
      
         }   

   }
   

/*PRUEBA DEL ALGORITMO*/
/* #include <stdio.h>

   void burbuja( int *lilsta ,int N){ 

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
   burbuja(A,6);
   for(k=0;k<6;k++){
  int a=A[k];
      printf("%i\n",a);
   }
   
   }*/
