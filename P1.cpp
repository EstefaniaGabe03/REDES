//Estefania Garcia Beltran & Chat GPT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//"validarIP" valida una direccion IP verificando que tenga el formato
//correcto con 4 numeros separados por puntos y que cada numero este en el
//rango valido de 0 - 255
int validarIP(const char* ip) {
    int numeros[4];
    int cont_num = sscanf(ip, "%d.%d.%d.%d", &numeros[0], &numeros[1], &numeros[2], &numeros[3]);
    
    if (cont_num != 4) {
        return 0;
    }
    
    for (int i = 0; i < 4; i++) {
        if (numeros[i] < 0 || numeros[i] > 255) {
            return 0;
        }
    }
    
    return 1;
}
//"calcularBroadcast calcula el broadcast correspondiente a una direccion IP
//Resta cada octeto de la direccion IP
void calcularBroadcast(const char* ip, char* broadcast) {
    int numeros[4];
    sscanf(ip, "%d.%d.%d.%d", &numeros[0], &numeros[1], &numeros[2], &numeros[3]);
    
    for (int i = 0; i < 4; i++) {
        numeros[i] = 255 - numeros[i];
    }
    
    sprintf(broadcast, "%d.%d.%d.%d", numeros[0], numeros[1], numeros[2], numeros[3]);
}
//"printBinaryIP" imprime la direccion IP en formato binario
void printBinaryIP(const char* ip) {
    int numeros[4];
    sscanf(ip, "%d.%d.%d.%d", &numeros[0], &numeros[1], &numeros[2], &numeros[3]);
    
    for (int i = 0; i < 4; i++) {
        unsigned int mask = 1 << 7;
        
        while (mask > 0) {
            if (numeros[i] & mask) {
                printf("1");
            } else {
                printf("0");
            }
            
            mask >>= 1;
        }
        
        if (i < 3) {
            printf(".");
        }
    }
    
    printf("\n");
}

int main() {
    char ip[20];
    printf("Ingrese una dirección IP: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; 
    
    if (!validarIP(ip)) {
        printf("La dirección IP ingresada es invalida.\n");
        return 1;
    }
    
    char broadcast[20];
    calcularBroadcast(ip, broadcast);
    
    printf("Dirección de Broadcast: %s\n", broadcast);
    printf("Dirección IP en binario: ");
    printBinaryIP(ip);
    
    return 0;
}

//La funcion main es la funcion principal del programa, el cual solicita al usuario
//que ingrese una direccion IP y luego realiza las siguientes acciones:
//Este programa permite al usuario ingresar una direccion IP, la valida, calcula el
//el broadcast correspondiente y muestra tanto el broadcast como la direccion IP en formato binario.

//ERROR: en la parte del calculo del Broadcast no lo calcula de forma correcta, el cual no le halle solucion
