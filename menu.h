#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "Personas.h"

int menuPrincipal(void){
    int op;
    printf("\n---MENU---\n");
    printf("[1].....Dar de alta\n");
    printf("[2].....Dar de baja\n");
    printf("[3].....Mostrar\n");
    printf("[4].....Funciones Especiales\n");
    printf("[5].....salir\n");
    printf("Elija una opcion: \n");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

int menuAltas(void){
    int opc;
    printf("\n---MENU ALTAS---\n");
    printf("[1].....Dar de alta a una persona\n");
    printf("[2].....Dar de alta varias personas\n");
    printf("[3].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d", &opc);
    while (getchar() != '\n');
    return opc;
}

int menuBajas(void){
    int op;
    printf("\n---MENU BAJAS---\n");
    printf("[1].....Dar de baja a una persona\n");
    printf("[2].....Dar de baja a varias personas\n");
    printf("[3].....Dar de baja a todos\n");
    printf("[4].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}
int menuMostrar(void){
    int op;
    printf("\n---MENU MOSTRAR---\n");
    printf("[1].....Todas las personas\n");
    printf("[2].....Por carrera\n");
    printf("[3].....Por semestre\n");
    printf("[4].....Por Carrera y semestre\n");
    printf("[5].....Por nombre\n");
    printf("[6].....Por Matricula\n");
    printf("[7].....Calificaciones\n");
    printf("[8].....Regresar\n");
    printf("Elija una opcion: \n");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

int menuModificar(void){
    int op;
    printf("\n---MENU MODIFICAR---\n");
    printf("[1].....Calificaciones de un alumno\n");
    printf("[2].....Datos\n");
    printf("[3].....Salir\n");
    printf("Elija una opcion: \n");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

int menuCalificaciones(void){
    int op;
    printf("\n---MODIFICAR CALIFICACIONES---\n");
    printf("[1].....Parcial (todas las calificaciones de un parcial)\n");
    printf("[2].....Materia (todos los parciales de una materia)\n");
    printf("[3].....Salir\n");
    printf("Elija una opcion: \n");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

int menuDatos(void){
    int op;
    printf("\n---MODIFICAR DATOS---\n");
    printf("[1].....Datos de la persona\n");
    printf("[2].....Datos del alumno\n");
    printf("[3].....Salir\n");
    printf("Elija una opcion: \n");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

#endif
