#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "revelado.h"
#include "parser.h"

int main()
{
    LinkedList* listaRevelado = ll_newLinkedList();



    controller_loadFromText("data.csv", listaRevelado);
    controller_ListRevelado(listaRevelado);

    controller_saveAsText("informes.csv", listaRevelado);
    return 0;
}
