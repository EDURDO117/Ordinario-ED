#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Personas.h"

void Mostrar(struct Persona *Primero) {
    struct Persona *aux = Primero;

    while (aux != NULL) {
        printf("\nPERSONA\n");
        printf("Nombre: %s\n", aux->nombre);
        printf("Edad: %d\n", aux->edad);
        printf("Genero: %c\n", aux->genero);
        printf("Fecha: %s\n", aux->fn);

        if (aux->ptrAlum != NULL) {
            printf("\nALUMNO\n");
            printf("Matricula: %s\n", aux->ptrAlum->matricula);
            printf("Carrera: %s\n", aux->ptrAlum->carrera);
            printf("Semestre: %d\n", aux->ptrAlum->semestre);
            printf("Correo: %s\n", aux->ptrAlum->correo);
        } else {
            printf("No es alumno\n");
        }

        aux = aux->ptrSig;
    }
}

void mostrarCarreras(struct Persona *Primero) {
    char cb[20];
    struct Persona *aux = Primero;

    printf("Ingrese carrera (idssi, if, lb, lca, lat): ");
    scanf("%19s", cb);

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->carrera, cb) == 0) {
            printf("\nPERSONA\n");
            printf("Nombre: %s\n", aux->nombre);
            printf("Edad: %d\n", aux->edad);
            printf("Genero: %c\n", aux->genero);
            printf("Fecha: %s\n", aux->fn);

            printf("\nALUMNO\n");
            printf("Matricula: %s\n", aux->ptrAlum->matricula);
            printf("Carrera: %s\n", aux->ptrAlum->carrera);
            printf("Semestre: %d\n", aux->ptrAlum->semestre);
            printf("Correo: %s\n", aux->ptrAlum->correo);
        }

        aux = aux->ptrSig;
    }
}

void mostrarSemestres(struct Persona *Primero) {
    int sem;
    struct Persona *aux = Primero;

    printf("Ingrese semestre: ");
    scanf("%d", &sem);

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && aux->ptrAlum->semestre == sem) {
            printf("\nPERSONA\n");
            printf("Nombre: %s\n", aux->nombre);
            printf("Edad: %d\n", aux->edad);
            printf("Genero: %c\n", aux->genero);
            printf("Fecha: %s\n", aux->fn);

            printf("\nALUMNO\n");
            printf("Matricula: %s\n", aux->ptrAlum->matricula);
            printf("Carrera: %s\n", aux->ptrAlum->carrera);
            printf("Semestre: %d\n", aux->ptrAlum->semestre);
            printf("Correo: %s\n", aux->ptrAlum->correo);
        }

        aux = aux->ptrSig;
    }
}

void mostrarCarreraSemestre(struct Persona *Primero) {
    char car[20];
    int sem;
    struct Persona *aux = Primero;

    printf("Ingrese carrera: ");
    scanf("%19s", car);

    printf("Ingrese semestre: ");
    scanf("%d", &sem);

    while (aux != NULL) {
        if (aux->ptrAlum != NULL &&
            strcmp(aux->ptrAlum->carrera, car) == 0 &&
            aux->ptrAlum->semestre == sem) {
            printf("\nPERSONA\n");
            printf("Nombre: %s\n", aux->nombre);
            printf("Edad: %d\n", aux->edad);
            printf("Genero: %c\n", aux->genero);
            printf("Fecha: %s\n", aux->fn);

            printf("\nALUMNO\n");
            printf("Matricula: %s\n", aux->ptrAlum->matricula);
            printf("Carrera: %s\n", aux->ptrAlum->carrera);
            printf("Semestre: %d\n", aux->ptrAlum->semestre);
            printf("Correo: %s\n", aux->ptrAlum->correo);
        }

        aux = aux->ptrSig;
    }
}

void mostrarPorNombre(struct Persona *Primero, const char *nom) {
    struct Persona *aux = Primero;

    while (aux != NULL) {
        if (strcmp(aux->nombre, nom) == 0) {
            printf("\nPERSONA\n");
            printf("Nombre: %s\n", aux->nombre);
            printf("Edad: %d\n", aux->edad);
            printf("Genero: %c\n", aux->genero);
            printf("Fecha: %s\n", aux->fn);

            if (aux->ptrAlum != NULL) {
                printf("\n--- ALUMNO ---\n");
                printf("Matricula: %s\n", aux->ptrAlum->matricula);
                printf("Carrera: %s\n", aux->ptrAlum->carrera);
                printf("Semestre: %d\n", aux->ptrAlum->semestre);
                printf("Correo: %s\n", aux->ptrAlum->correo);
            }
        }

        aux = aux->ptrSig;
    }
}

void buscarMatricula(struct Persona *Primero, const char *mat) {
    struct Persona *aux = Primero;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, mat) == 0) {
            printf("\nPERSONA\n");
            printf("Nombre: %s\n", aux->nombre);
            printf("Edad: %d\n", aux->edad);
            printf("Genero: %c\n", aux->genero);
            printf("Fecha: %s\n", aux->fn);

            printf("\nALUMNO\n");
            printf("Matricula: %s\n", aux->ptrAlum->matricula);
            printf("Carrera: %s\n", aux->ptrAlum->carrera);
            printf("Semestre: %d\n", aux->ptrAlum->semestre);
            printf("Correo: %s\n", aux->ptrAlum->correo);
            return;
        }

        aux = aux->ptrSig;
    }

    printf("No se encontro ninguna persona con esa matricula.\n");
}

void mostrarCalificaciones(struct Persona *Primero) {
    char mat[10];
    struct Persona *aux = Primero;

    printf("Ingrese la matricula del alumno: ");
    scanf("%9s", mat);

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, mat) == 0) {
            printf("\nCALIFICACIONES DE %s\n", aux->nombre);
            printf("Matricula: %s\n", aux->ptrAlum->matricula);

            for (int i = 0; i < 5; i++) {
                printf("\nParcial %d\n", i + 1);
                for (int j = 0; j < 5; j++) {
                    printf("Materia %d: %.2f\n", j + 1, aux->ptrAlum->calif[i][j]);
                }
            }

            return;
        }

        aux = aux->ptrSig;
    }

    printf("No se encontro ninguna persona con esa matricula.\n");
}


#endif // MOSTRAR_H
