//Estefania Garcia Beltran
//EXAMEN PARTE 1/3
//El codigo permitira tomar un numero entero, separar los digitos 
// y almacenarlos en un solo vector. El usuario puede ingresar
//los digitos a su eleccion para especificar la posicion y el valor
//que desea sumar en el vector.

#include<stdio.h>

//DEFINIR LAS FUNCIONES

int pasar_vector(int num, int vector[], int* tam){
    int i = 0;
    while (num > 0){
        vector[i] = num % 10;
        num /= 10;
        i++;
    }
    *tam = i;
}
//Funcion para sumar un valor en una posicion del vector

void sumale(int pos, int valor, int vector[], int tam){
    vector[pos] += valor;

    //se inicia el acarreo de numeros con un for
    //este primer for es para realizar el transporte de digitos en un vector
    
    for (int i = pos; i < tam; i++){
        if (vector[i] > 9){
            vector[i] -= 10;
            vector[i + 1] += 1;
        }else {
            break;
        }
    }

    //Si el ultimo digito tiene transporte, se incrementara el tamaño del vector
    //para eso se utilizara un if

    if (vector[tam] > 0){
        tam++;
    }

    //Se muestra el resultado

    printf("\nResultado: [");

    //el siguiente for recore el vector e imprime sus digitos separados
    //por comas, inica en la ultima posicion del vector y se mueve hacia
    //la primera posicion.
    
    for (int i = tam - 1; i >= 0; i--){
        printf("%d", vector[i]);
        if (i > 0){
            printf(",");
        }
    }
    printf("]\n");
}

int main(){
    int num;
    printf("\nIngresa el numero entero: ");
    scanf("%d", &num);
    int vector[10]; // tamaño maximo del vector, sera 10 digitos en el numero
    int tam;

    //Se pa el numero de un vector separando sus digitos
    pasar_vector(num, vector, &tam);

    //Se muestra el vector original
    printf("\nNumero original: [");
    
    for (int i = tam - 1; i >= 0; i--){
        printf("%d", vector[i]);
        if (i > 0){
            printf(",");
        }
    }
    printf("]\n");

    //Aplicacion de la funcion sumale

    int pos, valor;
    printf("\nIngresa la posicion donde quieres que se sume el valor: ");
    scanf("%d", &pos);
    printf("\nIngresa lel valor a sumar en la posicion: ");
    scanf("%d", &valor);

    sumale(pos, valor, vector, tam);

    return 0;
}