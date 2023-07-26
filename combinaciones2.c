//Escrito por Estefania con ayuda de ChatGPT
//El codigo genera combinaciones binarias posibles
//de un numero dado de bits, hace uso de la recursividad.
#include <stdio.h>

void combinaciones(int n, int bits[], int indice) {
    if (indice == n) {
        // imprime la combinacion binaria
        for (int i = 0; i < n; i++) {
            printf("%d", bits[i]);
        }
        printf("\n");
        return;
    }

    //Aqui se define la funcion "combinaciones", la cual es la
    //principal para generar las funciones.
    combinaciones(n, bits, indice+ 1);

    bits[indice] = 1; //Se almacenaran los bits de la combinacion.
    combinaciones(n, bits, indice + 1);
}

int main() {
    int n;
    printf("Agrega el numero de bits: ");
    scanf("%d", &n);

    int bits[n];
    combinaciones(n, bits, 0);

    return 0;
}
