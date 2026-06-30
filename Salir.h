#include "Personas.h"

void salir(struct Persona **ptr){
    if (*ptr == NULL) {
        printf("No hay registros.\n");
    } else {
        BajasTodos(ptr);
    }
    printf("Saliendo del programa...\n");
}
