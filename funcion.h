#ifndef FUNCION_H
#define FUNCION_H

#include <stddef.h>

#define MAX_LIBROS 10

typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[15];
} Libro;

// Declaraciones de funciones
void eliminarSaltoLinea(char *cadena);
void registrarLibro(Libro *libros, int *contador);
void mostrarLibros(Libro *libros, int contador);
void buscarLibro(Libro *libros, int contador);
void actualizarEstado(Libro *libros, int contador);
void eliminarLibro(Libro *libros, int *contador);
void mostrarMenu();
int leerOpcionMenu();

#endif // FUNCION_H