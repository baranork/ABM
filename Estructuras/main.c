#include <stdio.h>
#include <stdlib.h>
#define T 3

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

void mostrarEmpleado(eEmpleado);
void cargarEmpleados(eEmpleado[], int);
void mostrarListaEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
int buscarUno(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);
int mostrarMenu(void);

int main()
{

    eEmpleado lista[T];
    inicializarEmpleados(lista, T);
    mostrarMenu;


    cargarEmpleados(lista, T);
    mostrarListaEmpleados(lista, T);

    return 0;
}

int mostrarMenu(void)
{
    printf("1. Cargar Empleado\n2.Buscar empleados\n3.Mostrar lista de empleados\n4.Borrar empleado\n");

}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++){
        lista[i].estado = 0;
    }
}
void cargarEmpleados(eEmpleado lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f", &lista[i].sueldoBruto);
        lista[i].sueldoNeto = lista[i].sueldoBruto*0.85;
    }
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
   printf("%d-%s-%c-%f-%f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<T; i++){
        mostrarEmpleado(lista[i]);
    }
}
