#include <stdio.h>
#include <stdlib.h>
#include "Personas.h"

void Bajas1(struct Persona **Primero, struct Persona **Ultimo){

    struct Persona *ptraux;

    if(*Primero == NULL){
        printf("\nNo existen registros.\n");
        return;
    }

    ptraux = *Primero;
    *Primero = ptraux->ptrSig;

    if(*Primero == NULL){
        *Ultimo = NULL;
    }

    if(ptraux->ptrAlum != NULL){
        free(ptraux->ptrAlum);
    }

    free(ptraux->nombre);
    free(ptraux);

    printf("\nBaja realizada con exito.\n");
}

void BajasVarias(struct Persona **Primero, struct Persona **Ultimo){

    int n;

    if(*Primero == NULL){
        printf("\nNo existen registros.\n");
        return;
    }

    printf("\n¿Cuantas personas desea dar de baja?: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        if(*Primero == NULL){
            printf("\nYa no existen mas registros.\n");
            break;
        }

        Bajas1(Primero,Ultimo);
    }
}

void BajasTodos(struct Persona **Primero, struct Persona **Ultimo){

    struct Persona *ptraux;

    if(*Primero == NULL){
        printf("\nNo existen registros.\n");
        return;
    }

    while(*Primero != NULL){

        ptraux = *Primero;
        *Primero = ptraux->ptrSig;

        if(ptraux->ptrAlum != NULL){
            free(ptraux->ptrAlum);
        }

        free(ptraux->nombre);
        free(ptraux);
    }

    *Ultimo = NULL;

    printf("\nTodos los registros fueron eliminados correctamente.\n");
}
