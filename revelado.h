#ifndef REVELADO_H_INCLUDED
#define REVELADO_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char fecha[128];
    char tipo[128];
    int cantidad;
    float precio;
    char cuit[128];

}Revelado;

Revelado* revelado_new(void);
Revelado* revelado_newParametros(char* idStr,char* fechaStr,char* tipoStr, char* cantidadStr, char* precioStr, char* cuitStr);
void revelado_delete(Revelado* this);

int revelado_setId(Revelado* this,int id);
int revelado_getId(Revelado* this,int* id);

int revelado_setFecha(Revelado* this,char* fecha);
int revelado_getfecha(Revelado* this,char* resultado);

int revelado_setTipo(Revelado* this,char* tipo);
int revelado_getTipo(Revelado* this,char* resultado);

int revelado_setCantidad(Revelado* this,int cantidad);
int revelado_getCantidad(Revelado* this,int* cantidad);

int revelado_setPrecio(Revelado* this,float precio);
int revelado_getPrecio(Revelado* this,float* resultado);

int revelado_setCuit(Revelado* this,char* cuit);
int revelado_getCuit(Revelado* this,char* resultado);

int revelado_setIdStr(Revelado* this, char* id);
int revelado_getIdStr(Revelado* this, char* resultado);

int revelado_setCantidadStr(Revelado* this, char* cantidad);
int revelado_getCantidadStr(Revelado* this, char* resultado);

int revelado_setPrecioStr(Revelado* this, char* precio);
int revelado_getPrecioStr(Revelado* this, char* resultado);

int revelado_fotosTotal (LinkedList* pArrayListRevelado, int* fotosReveladasTotales);
int revelado_ventasMayores150 (void* this);
int revelado_ventasMayores300 (void* this);
int revelado_cantidadPolariod (void* this);
int revelado_fotosPolariod (LinkedList* pArrayListRevelado, int* fotosReveladasPolaroid);

#endif // REVELADO_H_INCLUDED

