#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "revelado.h"
#include "validaciones.h"
#include "LinkedList.h"



/** \brief Reserva espacio en memoria para un revelado
 * \param void vacio
 * \return Revelado* un puntero al espacio reservado para cargar un revelado
 */
Revelado* revelado_new(void)
{
    return (Revelado*) malloc(sizeof(Revelado));
}

/** \brief Valida los elementos que contiene una revelado y los carga en una variable Revelado
 *
 * \param idStr char* id del revelado.
 * \param tipoStr char* tipo  de la revelado.
 * \param cantidadStr char* cantidad del revelado.
 * \param importeStr char* importe del revelado.
 * \return Revelado* pAuxRevelado, devuelve - NULL si puntero a idStr/tipoStr/cantidadStr/importeStr NULL,
 *                               devuelve - puntero si valido sus elementos.
 *
 */
Revelado* revelado_newParametros(char* idStr,char* fechaStr,char* tipoStr, char* cantidadStr, char* precioStr, char* cuitStr)
{
    Revelado* pRevelado = revelado_new();
    Revelado* retorno = NULL;

    if(pRevelado != NULL && idStr != NULL && fechaStr != NULL && tipoStr != NULL && cantidadStr != NULL && precioStr != NULL && cuitStr != NULL)
    {
        if(!revelado_setIdStr(pRevelado, idStr) &&
                !revelado_setFecha(pRevelado, fechaStr) &&
                !revelado_setTipo(pRevelado, tipoStr) &&
                !revelado_setCantidadStr(pRevelado, cantidadStr)&&
                !revelado_setPrecioStr(pRevelado, precioStr) &&
                !revelado_setCuit(pRevelado, cuitStr))
        {

            retorno = pRevelado;
        }
        else
        {
            revelado_delete(pRevelado);
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para una revelado.
 *
 * \param Revelado* this puntero a la revelado
 * \return int retorno -1 si this NULL,
 *                     0 si logro liberar el espacio reservado.
 *
 */
void revelado_delete(Revelado* this)
{
    if(this != NULL)
    {
        return free(this);
    }
}

/** \brief Valida el elemento id de la revelado y lo carga en la estructura Revelado
 *
 * \param this Revelado* puntero a la revelado
 * \param id int id del revelado
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 *
 */
int revelado_setId(Revelado* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0 )
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un revelado.
 *
 * \param this Revelado* puntero a revelado.
 * \param resultado int* id de Revelado
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 *
 */
int revelado_getId(Revelado* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int revelado_setFecha(Revelado* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL && validFecha(fecha))
    {
        strcpy(this->fecha,fecha);
        retorno = 0;
    }
    return retorno;
}

int revelado_getfecha(Revelado* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->fecha);
        retorno = 0;
    }
    return retorno;
}

int revelado_setTipo(Revelado* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL && validTipo(tipo))
    {
        strcpy(this->tipo,tipo);
        retorno = 0;
    }
    return retorno;
}

int revelado_getTipo(Revelado* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->tipo);
        retorno = 0;
    }
    return retorno;
}

int revelado_setCantidad(Revelado* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int revelado_getCantidad(Revelado* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int revelado_setPrecio(Revelado* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio >= 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

int revelado_getPrecio(Revelado* this,float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->precio;
        retorno = 0;
    }
    return retorno;
}

int revelado_setCuit(Revelado* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL && validCuit(cuit))
    {
        strcpy(this->cuit,cuit);
        retorno = 0;
    }
    return retorno;
}

int revelado_getCuit(Revelado* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->cuit);
        retorno = 0;
    }
    return retorno;
}

int revelado_setIdStr(Revelado* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && validNumber(id))//Validar que lo que recibe es un numero.
    {
        retorno = revelado_setId(this,atoi(id));
    }
    return retorno;
}

int revelado_getIdStr(Revelado* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        revelado_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int revelado_setCantidadStr(Revelado* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL && validNumber(cantidad))//Validar que lo que recibe es un numero.
    {
        retorno = revelado_setCantidad(this,atoi(cantidad));
    }
    return retorno;
}

int revelado_getCantidadStr(Revelado* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        revelado_getCantidad(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int revelado_setPrecioStr(Revelado* this, char* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL && validFloat(precio))//Validar que lo que recibe es un numero.
    {
        retorno = revelado_setPrecio(this,atof(precio));
    }
    return retorno;
}

int revelado_getPrecioStr(Revelado* this, char* resultado)
{
    int retorno = -1;
    float bufferFloat; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        revelado_getPrecio(this, &bufferFloat);
        sprintf(resultado, "%f", bufferFloat);
        retorno = 0;
    }
    return retorno;
}

int revelado_fotosTotal (LinkedList* pArrayListRevelado, int* fotosReveladasTotales)
{
    int ret = -1;
    int i = 0;
    Revelado* pAuxRevelado;
    int auxFotos;
    int acumFotos = 0;

    if(pArrayListRevelado != NULL)
    {
        for(i=0; i<=ll_len(pArrayListRevelado); i++)
        {
            pAuxRevelado = ll_get(pArrayListRevelado, i);
            if(pAuxRevelado != NULL)
            {
                if(!revelado_getCantidad(pAuxRevelado, &auxFotos))
                {
                    acumFotos += auxFotos;
                    ret = 0;
                }
            }
        }
        *fotosReveladasTotales = acumFotos;
    }
    return ret;
}

int revelado_ventasMayores150 (void* this)
{
    int ret = 0;
    float auxPrecio;
    int auxCantidad;
    float auxVenta;

    if(this!= NULL)
    {
        revelado_getCantidad((Revelado*)this, &auxCantidad);
        revelado_getPrecio((Revelado*)this, &auxPrecio);
        auxVenta = (float)auxCantidad * auxPrecio;
        if(auxVenta >= 150)
        {
            ret=1;
        }
    }
    return ret;
}

int revelado_ventasMayores300 (void* this)
{
    int ret = 0;
    float auxPrecio;
    int auxCantidad;
    float auxVenta;

    if(this!= NULL)
    {
        revelado_getCantidad((Revelado*)this, &auxCantidad);
        revelado_getPrecio((Revelado*)this, &auxPrecio);
        auxVenta = (float)auxCantidad * auxPrecio;
        if(auxVenta >= 300)
        {
            ret=1;
        }
    }
    return ret;
}


int revelado_cantidadPolariod (void* this)
{
    int ret = 0;
    char auxRevelado[50];

    if(this!= NULL)
    {
        revelado_getTipo((Revelado*)this, auxRevelado);
        if(!strcmp("POLAROID_11x9", auxRevelado) || !strcmp("POLAROID_10x10", auxRevelado))
        {
            ret = 1;
        }
    }
    return ret;
}

int revelado_fotosPolariod (LinkedList* pArrayListRevelado, int* fotosReveladasPolaroid)
{
    int ret = -1;
    int i = 0;
    Revelado* pAuxRevelado;
    int auxFotos;
    int acumFotos = 0;
    char auxRevelado[50];

    if(pArrayListRevelado != NULL)
    {
        for(i=0; i<=ll_len(pArrayListRevelado); i++)
        {
            pAuxRevelado = ll_get(pArrayListRevelado, i);
            if(pAuxRevelado != NULL)
            {
                revelado_getTipo(pAuxRevelado, auxRevelado);
                if(!strcmp("POLAROID_11x9", auxRevelado) || !strcmp("POLAROID_10x10", auxRevelado))
                {
                    revelado_getCantidad(pAuxRevelado, &auxFotos);
                    acumFotos += auxFotos;
                    ret = 0;
                }
            }
        }
        *fotosReveladasPolaroid = acumFotos;
    }
    return ret;
}

