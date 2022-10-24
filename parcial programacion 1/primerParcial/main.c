#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

int aplicarAumento(precio);
int ordenar(eVacuna unaLista[], int tam);
void mostrarVacuna(eVacuna vacuna, int tam);
int mostrarVacunas(eVacuna unaLista[], int tam);


int main()
{
    eVacuna lista[3] =
    {
    {001, "Pfizer", 'm', 90.00}, {002, "Sputnik", 'c', 95.00},
    {001, "Tetanos", 'h', 93.00}
    };

    mostrarVacunas(lista, 3);
    ordenar(lista, 3);
    printf("\n");
    mostrarVacunas(lista, 3);


    int precioBananas = 100;
    float precioAumentoBananas;

    precioAumentoBananas = aplicarAumento(precioBananas);
    printf("%.2f", precioAumentoBananas);

    return 0;
}

int aplicarAumento(precio)
{
    int valorPorcen = 5;
    float valorAAumentar;
    float nuevoPrecio;

    valorAAumentar = (float) precio * valorPorcen / 100;
    nuevoPrecio = precio + valorAAumentar;

    return nuevoPrecio;
}


int ordenar(eVacuna unaLista[], int tam)
{
    int todoOk = 0;
    eVacuna aux;
    if(unaLista != NULL && tam > 0)
    {
        for (int i = 0; i < tam -1; i++)
        {
            for (int j = 0 + 1; j < tam; j++)
            {
                if(unaLista[i].tipo != unaLista[j].tipo)
                {
                    if(unaLista[i].tipo > unaLista[j].tipo)
                    {
                            aux = unaLista[i];
                            unaLista[i] = unaLista[j];
                            unaLista[j] = aux;
                    } else
                        {
                            if(unaLista[i].id < unaLista[j].id)
                            {
                                aux = unaLista[i];
                                unaLista[i] = unaLista[j];
                                unaLista[j] = aux;
                            }
                }
                }
                else
                {
                    if(unaLista[i].tipo == unaLista[j].tipo)
                    {
                        if(unaLista[i].efectividad > unaLista[j].efectividad)
                        {
                            aux = unaLista[i];
                            unaLista[i] = unaLista[j];
                            unaLista[j] = aux;
                        } else
                        {
                            if(unaLista[i].efectividad < unaLista[j].efectividad)
                            {
                            aux = unaLista[i];
                            unaLista[i] = unaLista[j];
                            unaLista[j] = aux;
                            }

                        }
                    }
                }
            }
        }
    todoOk = 1;
    }
    return todoOk;
}

void mostrarVacuna(eVacuna vacuna, int tam)
{

    printf("%04d    ", vacuna.id);
    printf("%8s  ", vacuna.nombre);
    printf("%c  ", vacuna.tipo);
    printf("  %.2f    \n", vacuna.efectividad);
}

int mostrarVacunas(eVacuna unaLista[], int tam)
{
    int todoOk = 0;
    if(unaLista != NULL && tam > 0)
    {
        printf("***** LISTA DE VACUNAS *****\n");
        printf("****************************\n");
        printf("ID  VACUNA TIPO EFEC\n");
        for (int i = 0; i < tam; i++)
        {
                mostrarVacuna(unaLista[i], tam);

        }

        todoOk = 1;
    }

    return todoOk;

}
