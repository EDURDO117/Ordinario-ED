#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Personas.h"


struct Persona *nuevaPersona(){

    struct Persona *p;
    char nombre[50];

    p = (struct Persona *)malloc(sizeof(struct Persona));

    if(p == NULL){
        printf("No se pudo reservar memoria.\n");
        return NULL;
    }

    p->nombre = (char *)malloc(50*sizeof(char));

    if(p->nombre == NULL){
        free(p);
        return NULL;
    }

    printf("\nNombre: ");
    scanf(" ");
    fgets(nombre,50,stdin);

    nombre[strcspn(nombre,"\n")] = '\0';
    strcpy(p->nombre,nombre);

    printf("Edad: ");
    scanf("%d",&p->edad);

    printf("Genero (M/F): ");
    scanf(" %c",&p->genero);

    printf("Fecha de nacimiento (ddmmaaaa): ");
    scanf("%8s",p->fn);

    p->ptrAlum = NULL;
    p->ptrSig = NULL;

    return p;
}

struct Alumno *nuevoAlumno(){

    struct Alumno *A;

    A = (struct Alumno *)malloc(sizeof(struct Alumno));

    if(A == NULL){
        printf("No se pudo reservar memoria.\n");
        return NULL;
    }

    printf("Matricula: ");
    scanf("%9s",A->matricula);

    printf("opciones de carrera: \n");
    printf("IDSSI(Ingenieria en software)\n");
    printf("IF (Ingenieria Forestal)\n");
    printf("LB(Licenciatura en Biologia)\n");
    printf("LCA(Licenciatura en ciencias ambientales)\n");
    printf("LAT(Licenciatura en administracion turistica)\n");
    printf("al escribir la opcion use la abrebiacion tal cual\n");
    printf("Carrera: \n");
    scanf("%19s", A->carrera);
   
    printf("Semestre: ");
    scanf("%d", &A->semestre);

    printf("Correo: ");
    scanf("%22s",A->correo);

    printf("\nCaptura de calificaciones\n");

    for(int i=0;i<5;i++){

        printf("\nMateria %d\n",i+1);

        for(int j=0;j<5;j++){

            printf("Calificacion %d: ",j+1);
            scanf("%f",&A->calif[i][j]);

        }
    }

    return A;
}

int Altas(struct Persona **Primero, struct Persona **Ultimo){

    struct Persona *P;
    struct Alumno *A;
    int esAlumno;

    P = nuevaPersona();

    if(P == NULL)
        return 0;

    printf("\n¿Es alumno? (1=Si 0=No): ");
    scanf("%d",&esAlumno);

    if(esAlumno){

        A = nuevoAlumno();

        if(A == NULL){

            free(P->nombre);
            free(P);

            return 0;
        }

        P->ptrAlum = A;
    }

    if(*Primero == NULL){

        *Primero = P;
        *Ultimo = P;

    }else{

        (*Ultimo)->ptrSig = P;
        *Ultimo = P;

    }

    printf("\nRegistro agregado correctamente.\n");

    return 1;
}

void AltasVarias(struct Persona **Primero, struct Persona **Ultimo){

    int n;

    printf("\n¿Cuantas personas desea registrar?: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        printf("\n========== Persona %d ==========\n",i+1);

        if(!Altas(Primero,Ultimo)){

            printf("No fue posible registrar la persona.\n");

        }

    }

}