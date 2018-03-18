/* Algoritmo de ordenación por Insercción directa*/

   void insercion( int *lista, int N, Experimento*exp){ /* paso por dirección primer elemento de lista, N es el número de elementos, Experimento*exp puntero a estructura*/
      int i,j,aux;
         for(i=1; i<N;i++){
            aux= lista[i]; /* Guardo en aux el valor del elemento con clave i*/
            
            for(j=i-1;j>=0; j--){
                  if(lista[j]>aux){ /*Si el elemento con clave j (el anterior a i) es mayor que aux*/
                  lista[j+1]=lista[j]; /*En el elemento con clave j guardo el de clave j+1 (el siguiente)*/
                 
               }
               else{
                  break; /*en caso de que no sea mayor sacame del bucle j*/
               
               }
            }
            lista[j+1]=aux;
            
         }  
       
  
   
   }
   
   
   /*EJEMPLO DE PRUEBA POR SEPARADO*/
   
  /* #include <stdio.h>
   
   void insercion( int *lista, int N){ 
      int i,j,aux;
         for(i=1; i<N;i++){
            aux= lista[i];
            
            for(j=i-1;j>=0; j--){
                  if(lista[j]>aux){
                  lista[j+1]=lista[j];
                 
               }
               else{
                  break; 
               
               }
            }
            lista[j+1]=aux;
            
         }  
       
  
   
   }
   
   int main(){
   int A[100] ={88,
 30,100, 19, 24, 94, 79, 86, 60, 96,  2, 26, 46, 18,  8, 98, 45, 80, 32, 71, 23, 14, 75, 82, 54, 72, 34, 73, 56,  3, 31, 55, 67, 90, 12, 91, 69, 36, 11, 48, 59, 83,13, 76, 93, 92, 25, 28, 15, 47, 63, 49,  5, 37, 53, 97, 16, 38, 66, 21, 77, 52, 84, 65, 17, 51, 22, 74, 29, 89, 42, 62, 39, 87, 35, 68, 40,  7, 41, 85, 44,  1, 95,99,  4, 57, 43, 27, 61, 10, 70, 33, 64, 58,  6, 50, 81, 78, 20,  9};
   int k;
   insercion(A,100);
   for(k=0;k<100;k++){
  int a=A[k];
      printf("%i\n",a);
   }
   
   }*/
