#ifndef MODIFICAR_H
#define MODIFICAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Personas.h"
#include "menu.h"

static struct Persona *buscarPersonaPorNombre(struct Persona *inicio, const char *nombre) {
    struct Persona *actual = inicio;

    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return actual;
        }
        actual = actual->ptrSig;
    }

    return NULL;
}

static void modificarCalificacionesAlumno(struct Persona *persona) {
    int opcion;
    int parcial;
    int materia;
    float nuevaCalificacion;

    if (persona == NULL || persona->ptrAlum == NULL) {
        printf("\nLa persona no es alumno.\n");
        return;
    }

    do {
        opcion = menuCalificaciones();

        switch (opcion) {
            case 1:
                printf("\nIngrese el parcial a modificar (1-5): ");
                scanf("%d", &parcial);

                if (parcial < 1 || parcial > 5) {
                    printf("\nParcial invalido.\n");
                    break;
                }

                for (materia = 0; materia < 5; materia++) {
                    printf("Ingrese la nueva calificacion para la materia %d en el parcial %d: ", materia + 1, parcial);
                    scanf("%f", &nuevaCalificacion);
                    persona->ptrAlum->calif[parcial - 1][materia] = nuevaCalificacion;
                }

                printf("\nCalificaciones del parcial %d actualizadas.\n", parcial);
                break;

            case 2:
                printf("\nIngrese la materia a modificar (1-5): ");
                scanf("%d", &materia);

                if (materia < 1 || materia > 5) {
                    printf("\nMateria invalida.\n");
                    break;
                }

                for (parcial = 0; parcial < 5; parcial++) {
                    printf("Ingrese la nueva calificacion para el parcial %d en la materia %d: ", parcial + 1, materia);
                    scanf("%f", &nuevaCalificacion);
                    persona->ptrAlum->calif[parcial][materia - 1] = nuevaCalificacion;
                }

                printf("\nCalificaciones de la materia %d actualizadas.\n", materia);
                break;

            case 3:
                printf("\nSaliendo de modificaciones de calificaciones.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while (opcion != 3);
}

static void modificarDatosPersona(struct Persona *persona) {
    int opcion;
    char nuevoTexto[50];
    int nuevaEdad;
    char nuevoGenero;
    char nuevaFecha[9];

    if (persona == NULL) {
        printf("\nPersona no encontrada.\n");
        return;
    }

    do {
        printf("\n--- Datos de la persona ---\n");
        printf("1. Nombre\n");
        printf("2. Edad\n");
        printf("3. Genero\n");
        printf("4. Fecha de nacimiento\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese el nuevo nombre: ");
                scanf(" %49[^\n]", nuevoTexto);
                free(persona->nombre);
                persona->nombre = (char *)malloc(strlen(nuevoTexto) + 1);
                strcpy(persona->nombre, nuevoTexto);
                break;

            case 2:
                printf("\nIngrese la nueva edad: ");
                scanf("%d", &nuevaEdad);
                persona->edad = nuevaEdad;
                break;

            case 3:
                printf("\nIngrese el nuevo genero (M/F): ");
                scanf(" %c", &nuevoGenero);
                persona->genero = nuevoGenero;
                break;

            case 4:
                printf("\nIngrese la nueva fecha de nacimiento (ddmmaaaa): ");
                scanf("%8s", nuevaFecha);
                strcpy(persona->fn, nuevaFecha);
                break;

            case 5:
                printf("\nSaliendo de datos de la persona.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while (opcion != 5);
}

static void modificarDatosAlumno(struct Persona *persona) {
    int opcion;
    char nuevoTexto[30];
    int nuevoSemestre;

    if (persona == NULL || persona->ptrAlum == NULL) {
        printf("\nLa persona no es alumno.\n");
        return;
    }

    do {
        printf("\n--- Datos del alumno ---\n");
        printf("1. Matricula\n");
        printf("2. Carrera\n");
        printf("3. Semestre\n");
        printf("4. Correo\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese la nueva matricula: ");
                scanf("%29s", nuevoTexto);
                strcpy(persona->ptrAlum->matricula, nuevoTexto);
                break;

            case 2:
                printf("\nIngrese la nueva carrera: ");
                scanf("%19s", nuevoTexto);
                strcpy(persona->ptrAlum->carrera, nuevoTexto);
                break;

            case 3:
                printf("\nIngrese el nuevo semestre: ");
                scanf("%d", &nuevoSemestre);
                persona->ptrAlum->semestre = nuevoSemestre;
                break;

            case 4:
                printf("\nIngrese el nuevo correo: ");
                scanf("%22s", nuevoTexto);
                strcpy(persona->ptrAlum->correo, nuevoTexto);
                break;

            case 5:
                printf("\nSaliendo de datos del alumno.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while (opcion != 5);
}

void modificar(struct Persona **frente, struct Persona **final) {
        int modopc;
        int datoop;
        char nombre[50];
        struct Persona *persona;

        (void)final;

        do{
                modopc = menuModificar();

                switch(modopc){
                        case 1:
                                printf("\nIngrese el nombre del alumno a buscar: ");
                                scanf(" %49[^\n]", nombre);
                                persona = buscarPersonaPorNombre(*frente, nombre);

                                if (persona == NULL) {
                                        printf("\nNo se encontro la persona.\n");
                                } else {
                                        modificarCalificacionesAlumno(persona);
                                }
                                break;
                        case 2:
                                printf("\nIngrese el nombre de la persona a modificar: ");
                                scanf(" %49[^\n]", nombre);
                                persona = buscarPersonaPorNombre(*frente, nombre);

                                if (persona == NULL) {
                                        printf("\nNo se encontro la persona.\n");
                                } else {
                                        datoop = menuDatos();

                                        switch(datoop){
                                                case 1:
                                                        modificarDatosPersona(persona);
                                                        break;
                                                case 2:
                                                        modificarDatosAlumno(persona);
                                                        break;
                                                case 3:
                                                        printf("\nSaliendo de modificar datos.\n");
                                                        break;
                                                default:
                                                        printf("\nOpcion invalida.\n");
                                                        break;
                                        }
                                }
                                break;
                        case 3:
                                printf("\nSaliendo de modificar\n");
                                break;
                        default:
                                printf("\nOpcion invalida\n");
                                break;
                }

        } while (modopc != 3);
        
}

#endif // MODIFICAR_H
