/*Algoritmo de ordenación método de Selección*/

void selection( int*lista, int N, Experimento*exp){
   int i,j,menor,aux;
   for(i=0;i<N-1;i++){
      menor=i;
        for(j=i+1;j<N;j++){
        if(lista[j]<lista[menor]){
           menor=j;
        }
   }
      if(menor!=i){
      aux=lista[i];
      lista[i]=lista[menor];
      lista[menor]=aux;
      
      } 
}
}

/* EJEMPLO DE PRUEBA DEL ALGORITMO*/

/* #include <stdio.h>

void selection( int*lista, int N){
   int i,j,menor,aux;
   for(i=0;i<N-1;i++){
      menor=i;
        for(j=i+1;j<N;j++){
        if(lista[j]<lista[menor]){
           menor=j;
        }
   }
      if(menor!=i){
      aux=lista[i];
      lista[i]=lista[menor];
      lista[menor]=aux;
      
      } 
}
}

int main(){
   int A[100] ={88,
 30,100, 19, 24, 94, 79, 86, 60, 96,  2, 26, 46, 18,  8, 98, 45, 80, 32, 71, 23, 14, 75, 82, 54, 72, 34, 73, 56,  3, 31, 55, 67, 90, 12, 91, 69, 36, 11, 48, 59, 83,13, 76, 93, 92, 25, 28, 15, 47, 63, 49,  5, 37, 53, 97, 16, 38, 66, 21, 77, 52, 84, 65, 17, 51, 22, 74, 29, 89, 42, 62, 39, 87, 35, 68, 40,  7, 41, 85, 44,  1, 95,99,  4, 57, 43, 27, 61, 10, 70, 33, 64, 58,  6, 50, 81, 78, 20,  9};
   int k;
   selection(A,100);
   for(k=0;k<100;k++){
  int a=A[k];
      printf("%i\n",a);
   }
   
   } */
