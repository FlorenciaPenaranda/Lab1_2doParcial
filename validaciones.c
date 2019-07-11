#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

/** \brief Solicita el ingreso de un string y valida su tamaño
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo int Tamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getString(char *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos)
{
    int ret=-1;
    char arrayAuxiliar[maximo];
    while(intentos>0)
    {
        printf(mensaje);
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
        //__fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( resultado != NULL && strlen(arrayAuxiliar) >= minimo && strlen(arrayAuxiliar) <= maximo && validarLetra(arrayAuxiliar)==0)
        {
            strncpy(resultado,arrayAuxiliar,maximo);
            ret=0;
            break;
        }
        else
        {
            printf(mensajeError);
        }
        intentos--;
    }
    return ret;
}

int validarLetra (char letras[])
{
    int ret=0;
    int i=0;
    int CantidadLetras;
    CantidadLetras=strlen(letras);
    while (i<CantidadLetras && ret==0)
    {
        if (isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

/** \brief Solicita el ingreso de un int y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int i;
    int buffer;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos>=0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            scanf("%d",&buffer);
            if(!isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n %s", mensajeError);
            }
        }
    }
    return retorno;
}

int isValidInt(int numero, int maximo, int minimo)
{
    int ret = -1;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 0;
    }
    return ret;
}

int validarNumero (char numeros[])
{
    int ret=0;
    int i=0;
    int CantidadNumeros;
    CantidadNumeros=strlen(numeros);
    while (i<CantidadNumeros && ret==0)
    {
        if (isdigit(numeros[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

/** \brief Solicita el ingreso de un float y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    float buffer;

    if(mensaje!= NULL && mensajeError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    int ret = -1;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 0;
    }
    return ret;
}

int validarFlotante(char* numeros)
{
    int ret = 1;
    if(numeros != NULL)
    {
        for(int i=0; numeros[i]!='\0'; i++)
        {
            if((numeros[i]<0 && numeros[i]>9) || numeros[i]!= '.')
            {
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Solicita el ingreso de un char y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getChar( char *resultado,char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos)
{
    int retorno = -1;
    char buffer;
    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush( stdin ); //LIMPIA BUFFER WINDOWS
            //__fpurge(stdin); //LIMPIA BUFFER LINUX
            scanf("%c", &buffer);
            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    int ret = 1;
    if(letra<=maximo && letra>=minimo)
    {
        ret = 0;
    }
    return ret;
}

int validNumber(char* numeros)
{
    int ret = 1;
    if(numeros != NULL)
    {
        for(int i=0; numeros[i]!='\0'; i++)
        {
            if(numeros[i]<'0' || numeros[i]>'9')
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int validFecha(char* fecha)
{
    int ret = 1;
    if(fecha != NULL)
    {
        for(int i=0; fecha[i]!='\0'; i++)
        {
            if((fecha[i]<'0' || fecha[i]>'9') && (fecha[i]!= '/'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int validCuit(char* cuit)
{
    int ret = 1;
    if(cuit != NULL)
    {
        for(int i=0; cuit[i]!='\0'; i++)
        {
            if((cuit[i]<'0' || cuit[i]>'9') && (cuit[i]!= '-'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int validTipo(char* tipo)
{
    int ret = 0;
    if(tipo != NULL)
    {
        if(!strcmp("4R_10x15", tipo) ||
                !strcmp(tipo, "5R_13x18")||
                !strcmp(tipo, "6R_15x20")||
                !strcmp(tipo, "8R_20x25")||
                !strcmp(tipo, "POLAROID_11x9")||
                !strcmp(tipo, "POLAROID_10x10"))
        {
            ret = 1;
        }
    }
    return ret;
}

int validFloat(char* numeros)
{
    int ret = 1;
    if(numeros != NULL)
    {
        for(int i=0; numeros[i]!='\0'; i++)
        {
            if((numeros[i]<'0' || numeros[i]>'9') && (numeros[i]!= '.'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}
