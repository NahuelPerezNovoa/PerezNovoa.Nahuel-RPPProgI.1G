#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char procesador[50];
    char marca[50];
    float precio;
} Notebook;

float calcularIVA(float precio);
int reemplazarCaracter(char cadena[], char caracterA, char caracterB);
void(Notebook* pArrayList, int criterio);

int main()
{
    float precio = 150;
    char cadena[20]="Cadena de prueba";
    Notebook arrayNotebooks[5] = {1,"xlz50","Intel",154},{2,"zzz2","AMD",487},{3,"awr53","Sony",777},{4,"asfj","Intel",654},{5,"casd","AMD",555};

    printf("El monto de IVA es: $%.2f\n",calcularIVA(precio));
    printf("Cadena original: %s\n",cadena);
    printf("La nueva cadena es: %s, y se reemplazaron %d carcteres\n",cadena,reemplazarCaracter(cadena,'a','o'));
    for(int i=0;i<5;i++)
    {
        printf("%d  %10s   %10s   $%.2f\n",arrayNotebooks[i].id,arrayNotebooks[i].procesador,arrayNotebooks[i].marca,arrayNotebooks[i].precio);
    }
    return 0;
}

float calcularIVA(float precio)
{
    return (precio*0.21);
}

int reemplazarCaracter(char cadena[], char caracterA, char caracterB)
{
    int len = strlen(cadena);
    int contador=0;

    for(int i=0; i<len; i++)
    {
        if(cadena[i]==caracterA)
        {
            cadena[i]=caracterB;
            contador++;
        }
    }
    return contador;
}

void(Notebook* pArrayList, int tam, int criterio)
{
    float rdo;
    Notebook aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam-1; j++)
        {
            if((strcmp(pArrayList[i].marca,pArrayList[j].marca)<0 && criterio==1)|| (strcmp(pArrayList[i].marca,pArrayList[j].marca)>0 && criterio==0)
        {
            aux=pArrayList[i];
                pArrayList[i]= pArrayList[j];
                pArrayList[j] = aux;
            }
            else if(strcmp(pArrayList[i].marca,pArrayList[j].marca)==0)
        {
            if(pArrayList[i].precio<pArrayList[j].precio && criterio==1)|| (pArrayList[i].precio>pArrayList[j].precio) && criterio==0)
                {
                    aux=pArrayList[i];
                    pArrayList[i]= pArrayList[j];
                    pArrayList[j] = aux;
                }

            }
        }
    }
}
