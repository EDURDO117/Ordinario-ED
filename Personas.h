#ifndef Personas_H
#define Personas_H

struct Persona{
    char *nombre;
    int edad;
    char genero;
    char fn[9];
    struct Alumno *ptrAlum;
    struct Persona *ptrSig;
};

struct Alumno{
    char matricula[10];
    char carrera[20];
    int semestre;
    char correo[23];
    float calif [5][5];
};
#endif //Personas_H
