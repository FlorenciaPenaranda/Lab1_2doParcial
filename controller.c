#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "revelado.h"
#include "parser.h"
#include "validaciones.h"

/** \brief Carga los datos de las entregas desde el archivo data (modo texto).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListRevelados LinkedList* puntero al array de entregas.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListRevelados es NULL,
                    0 si logra cargar los datos.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListRevelados)
{
    int ret = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListRevelados != NULL)
    {
        pFileAux = fopen(path, "r");
        if(pFileAux != NULL)
        {
            if(!parser_ReveladoFromText(pFileAux, pArrayListRevelados))
            {
                printf("\tCARGA EXITOSA!\n");
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Listar entregas
 *
 * \param pArrayListRevelados LinkedList* puntero al array de entregas.
 * \return int ret -1 si no puede mostar toda la lista de los entregas,
                    0 si logra mostar toda la lista de los entregas.
 *
 */
int controller_ListRevelado(LinkedList* pArrayListRevelados)
{
    int ret = -1;
    Revelado * pRevelado = NULL;
    int bufferId;
    char bufferFecha[400];
    char bufferTipo[400];
    int bufferCantidad;
    float bufferPrecio;
    char bufferCuit[400];

    for(int i=0; i<ll_len(pArrayListRevelados); i++)
    {
        pRevelado = ll_get(pArrayListRevelados, i);//guardar en un puntero a empleado
        if(pRevelado != NULL)
        {
            if(!revelado_getId(pRevelado, &bufferId) &&
                    !revelado_getfecha(pRevelado, bufferFecha) &&
                    !revelado_getTipo(pRevelado, bufferTipo) &&
                    !revelado_getCantidad(pRevelado, &bufferCantidad) &&
                    !revelado_getPrecio(pRevelado, &bufferPrecio) &&
                    !revelado_getCuit(pRevelado, bufferCuit))
            {
                printf("ID:%d FECHA:%s TIPO:%s CANTIDAD:%d PRECIO:%.2f CUIT:%s\n", bufferId,bufferFecha, bufferTipo, bufferCantidad, bufferPrecio, bufferCuit);
                ret = 0;
            }
        }

    }
    return ret;
}
/** \brief Guarda los datos de las entregas en el archivo informes.txt (modo texto).
 *
 * \param path char* puntero al archivo a guardar
 * \param pArrayListRevelados LinkedList* puntero al array de entregas.
 * \return int ret -1 si el puntero si no puede guardar los datos,
 *                  0 si logra guardar los datos.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListRevelado)
{
    int ret = -1;
    FILE* pFileAux = NULL;
    int cantidadTotalFotos;
    LinkedList* ventasMayoes150 = ll_newLinkedList();
    int cantidadVentasMayores150;
    LinkedList* ventasMayoes300 = ll_newLinkedList();
    int cantidadVentasMayores300;

    int cantFotosPolariod;
    int ventasPolriod;


    if(path != NULL && pArrayListRevelado != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            revelado_fotosTotal(pArrayListRevelado, &cantidadTotalFotos);
            revelado_fotosPolariod(pArrayListRevelado, &cantFotosPolariod);


            ventasMayoes150 = ll_filter(pArrayListRevelado, revelado_ventasMayores150);
            cantidadVentasMayores150 = ll_len(ventasMayoes150);

            ventasMayoes300 = ll_filter(pArrayListRevelado, revelado_ventasMayores300);
            cantidadVentasMayores300 = ll_len(ventasMayoes300);

            ventasPolriod = ll_count(pArrayListRevelado, revelado_cantidadPolariod);



            fprintf(pFileAux,"\t\tINFORME DE VENTAS REVELADO-DIGITAL\n\n");
            fprintf(pFileAux,"- Cantidad total fotos reveladas: %d\n", cantidadTotalFotos );
            fprintf(pFileAux,"- Cantidad de ventas mayores a los $ 150: %d \n", cantidadVentasMayores150);
            fprintf(pFileAux,"- Cantidad de ventas mayores a los $ 300: %d \n", cantidadVentasMayores300);
            fprintf(pFileAux,"- cantidad de ventas polariod: %.d\n", ventasPolriod);
            fprintf(pFileAux,"- cantidad de fotos polariod: %.d\n", cantFotosPolariod);


        }
        fclose(pFileAux);
    }

    return ret;
}
