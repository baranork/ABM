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
void mostrarMenu(eEmpleado[], int);

int main()
{

    eEmpleado lista[T];
    inicializarEmpleados(lista, T);
    mostrarMenu(lista, T);





    return 0;
}

void mostrarMenu(eEmpleado lista[], int tam)
{
    int opcion;
    char seguir = 's';
    do
    {
        fflush(stdin);
        system("cls");
        printf("1. Cargar Empleado\n2.Buscar empleados\n3.Mostrar lista de empleados\n4.Borrar empleado\n5.Salir\nSeleccione una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarEmpleados(lista, tam);
            system("pause");
            system("cls");
            break;
        case 2:

            system("pause");
            system("cls");
            break;
        case 3:
            mostrarListaEmpleados(lista, T);
            system("pause");
            system("cls");
            break;
        case 4:
            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            break;
        default:

            break;
        }

    }
    while(seguir == 's');

}


void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = 0;
    }
}
void cargarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int indice;

    indice = buscarLibre(lista, tam);

    if(indice== -1){
        printf("No se puedo cargar el empleado. Espacio insuficiente");
    }
    else{
        printf("Ingrese legajo: ");
        scanf("%d", &lista[indice].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[indice].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[indice].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f", &lista[indice].sueldoBruto);
        lista[indice].sueldoNeto = lista[indice].sueldoBruto*0.85;
    }


}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d-%s-%c-%f-%f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mostrarEmpleado(lista[i]);
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int flag = 0;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 0){
            flag = 1;
            indice = i;
            break;
        }
    }

    return indice;
}
