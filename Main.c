#include <stdio.h>
#include <string.h>
#include "Personas.h"
#include "menu.h"
#include "altas.h"
#include "Bajas.h"
#include "mostrar.h"
#include "MODIFICAR.h"

int main(){

    int op, op2, op3;
    char nombre[50];
    char matricula[10];

    struct Persona *Primero = NULL;
    struct Persona *Ultimo = NULL;

    do{

        op = menuPrincipal();

        switch(op){

            case 1:

                do{

                    op2 = menuAltas();

                    switch(op2){

                        case 1:
                            Altas(&Primero, &Ultimo);
                            break;

                        case 2:
                            AltasVarias(&Primero, &Ultimo);
                            break;

                        case 3:
                            printf("\nRegresando...\n");
                            break;

                        default:
                            printf("\nOpcion invalida.\n");
                    }

                }while(op2 != 3);

                break;

            case 2:

                do{

                    op2 = menuBajas();

                    switch(op2){

                        case 1:
                            Bajas1(&Primero, &Ultimo);
                            break;

                        case 2:
                            BajasVarias(&Primero, &Ultimo);
                            break;

                        case 3:
                            BajasTodos(&Primero, &Ultimo);
                            break;

                        case 4:
                            printf("\nRegresando...\n");
                            break;

                        default:
                            printf("\nOpcion invalida.\n");
                    }

                }while(op2 != 4);

                break;

            case 3:

                do{

                    op3 = menuMostrar();

                    switch(op3){

                        case 1:
                            Mostrar(Primero);
                            break;

                        case 2:
                            mostrarCarreras(Primero);
                            break;

                        case 3:
                            mostrarSemestres(Primero);
                            break;

                        case 4:
                            mostrarCarreraSemestre(Primero);
                            break;

                        case 5:
                            printf("Nombre a buscar: ");
                            fgets(nombre, 50, stdin);
                            nombre[strcspn(nombre, "\n")] = '\0';
                            mostrarPorNombre(Primero, nombre);
                            op3 = 8;
                            break;

                        case 6:
                            printf("Matricula a buscar: ");
                            fgets(matricula, 10, stdin);
                            matricula[strcspn(matricula, "\n")] = '\0';
                            buscarMatricula(Primero, matricula);
                            op3 = 8;
                            break;

                        case 7:
                            printf("Matricula del alumno: ");
                            fgets(matricula, 10, stdin);
                            matricula[strcspn(matricula, "\n")] = '\0';
                            mostrarCalificaciones(Primero);
                            break;

                        case 8:
                            printf("\nRegresando...\n");
                            break;

                        default:
                            printf("\nOpcion invalida.\n");
                    }

                }while(op3 != 8);

                break;

            case 4:
               modificar(&Primero, &Ultimo);
                break;

            case 5:
                printf("\nGracias por usar el programa.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(op != 5);

    return 0;
}