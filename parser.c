
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "revelado.h"

/** \brief Parsea los datos de las ventas desde el archivo (modo texto).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListRevelado LinkedList* puntero al array de revelados.
* \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListRevelado es NULL,
                   0 si logro parsear el archivo.
 *
 */
int parser_ReveladoFromText(FILE* pFile, LinkedList* pArrayListRevelado)
{
    int ret = -1;
    char bufferId[400];
    char bufferFecha[400];
    char bufferTipo[400];
    char BufferCantidad[400];
    char bufferPrecio[400];
    char bufferCuit[400];
    Revelado* pAuxRevelado;

    if(pFile != NULL && pArrayListRevelado != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFecha,bufferTipo,BufferCantidad,bufferPrecio,bufferCuit);
            pAuxRevelado = revelado_newParametros(bufferId,bufferFecha,bufferTipo,BufferCantidad,bufferPrecio,bufferCuit);
            if(pAuxRevelado != NULL)
            {
                ll_add(pArrayListRevelado, pAuxRevelado);
                ret = 0;
            }
        }
        fclose(pFile);
    }
    return ret;
}
