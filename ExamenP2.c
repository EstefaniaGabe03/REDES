//Estefania Garcia Beltran
//EXAMEN PARTE 2/3
//Este programa debe encontrar todas las combinaciones de dos elementos
//de un vector que sumen un numero objetivo. Principalmente 
//utilizando dos ciclos for.

#include<stdio.h>

//SumaFinder --> busca la suma de dos componentes del vector que den como resultado el numero N

void SumaFinder(int N, int vector[], int tam){
    int encontrado = 0;

    //Recorrer el vector en busca de las combinaciones

    for (int i = 0; i < tam; i++){
        for (int j = i +1; j < tam; j++){
            if (vector[i] + vector[j] == N){
                printf("[%d] y [%d]\n", i, j);
                encontrado = 1;
            }
        }
    }
    if (!encontrado){
        printf("NO se encontraron combinaciones que sumen %d.\n", N);
    }
}
int main() {
    int tam;
    printf("\nIngrese el tamaño del vector: ");
    scanf("%d", &tam);

    int vector[tam];
    printf("\nIngrese %d valores para el vector:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vector[i]);
    }

    int N;
    printf("\nIngrese el valor de N: ");
    scanf("%d", &N);

    printf("\nCombinaciones %d: \n", N);
    SumaFinder(N, vector, tam);

    return 0;
}
