#include "listaImpDinamica.h"
#include "lista.h"


void crearLista(Lista* pl)
{
   *pl = NULL;

};


void vaciuarLista(Lista* pls);

int insertarListaOrd(Lista* pl, void* dato, size_t tamElem, Cmp cmp)
{
    while (cmp(dato, (*pl)->dato) > 0 && *pl)
       pl =  &(*pl)->sig;

    if(cmp(dato, (*pl)->dato) == 0 && *pl)
        return DUPLICADO;

    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* datoN = malloc(tamElem)

    if(!nue || !datoN)
    {
        free(nue);
        free(datoN);
        return SIN_MEM;
    }


    memcpy(datoN, dato, tamElem);
    nue->dato = datoN;
    nue->tamElem = tamElem;
    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}


int insertarOActualizarListaOrd(Lista * pl, void* dato, size_t tamElem, Cmp cmp, Actualizar act)
{
    while (cmp(dato, (*pl)->dato) > 0 && *pl)
       pl =  &(*pl)->sig;

    if(cmp(dato, (*pl)->dato) == 0 && *pl)
    {
        act((*pl)->dato, dato);
        return DUPLICADO;
    }

    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* datoN = malloc(tamElem)

    if(!nue || !datoN)
    {
        free(nue);
        free(datoN);
        return SIN_MEM;
    }


    memcpy(datoN, dato, tamElem);
    nue->dato = datoN;
    nue->tamElem = tamElem;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}


int insertarEnListaFinal(Lista * pl, void* dato, size_t tamElem)
{

}
int insertarEnListaPrincipio(Lista * pl, void* dato, size_t tamElem);
int insertarEnListaPosicion(Lista * pl, void* dato, size_t tamElem, unsigned pos);

int buscarEnListaOrd(Lista* pl, void* dato, size_t tamElem)
{
    Nodo* actual = pl;
    int comp;
    while(cmp(dato, actual->dato) < 0 && actual)
        actual = actual->sig;
    if(cmp(dato,actual->datp) == 0)
    {
        memcpy(dato, actual->dato, min(tamElem, actual->tamElem));
        return 1; //verdadero
    }
    return 0; //falso
}

int buscarEnListaNoOrd(Lista* pl, void* dato, size_t tamElem, Cmp cmp)
{
    Nodo* actual = pl;
    int comp;
    while(cmp(dato, actual->dato) != 0 && actual)
        actual = actual->sig;
    if(actual)
    {
        memcpy(dato, actual->dato, min(tamElem, actual->tamElem));
        return 1; //verdadero
    }
    return 0; //falso
}


int eliminarDeListaOrdPorClave(Lista * pl, void* dato, size_t tamElem);
{
    while(*pl && cmp(dato, (*pl)->dato) > 0)
        pl =  &(*pl)->sig;

    if(!*pl || cmp(dato,(*pl)->dato) > 0)
        return 0; //Falso
    
    Nodo* nae = *pl;
    *pl = nae->sig;

    memcpy(dato, nae->dato, min(tamElem), nae->tamElem));
    free(nae->dato);
    free(nae);

    return 1;
     

}


int eliminarDeListaPorCondicion(Lista* pl,Condicion condicion)
{
    int cantElim = 0;
    while(*pl)
    {
        if(condicion((*pl)->dato))
        {
            Nodo* nae = *pl;
            *pl = nae->sig;

            free(bae->dato);
            free(nae);
            cantElim++;
        }
        else
            pl = &(*pl)->sig;
    }
    return cantElim;

}

void recorrerLista(Lista* pl, Accion accion, void* datosAccion)
{
    while(*pl)
    {
        accion((*pl)->dato, datosAccion);
        pl = &(*pl)->sig;
    }
}

int eliminarDeListaDePosicion(Lista * pl, void* dato, size_t tamElem, unsigned pos);
int eliminarDeListaPrimero(Lista * pl, void* dato, size_t tamElem)
int eliminarDeListaUltimo(Lista * pl, void* dato, size_t tamElem)
int eleminarDeListaDuplicados(Lista* pl, Cmp cmp,Actualizar actualizar)
{
    int cantElim = 0;
    if(!*pl)
        return 0;
    Lista* pl2 = *pl;
    Nodo* nae;

    while(*pl2)
    {
        pl2 = &(*pl)->sig;

        while(*pl2 && cmp((*pl)->dato),(*pl2)->dato) == 0)
        {
            nae = *pl2;
            *pl2 = nae->sig;

            actualizar((*pl->dato), nae->dato);

            free(nae->dato);
            free(nae);
        }

        pl = &(*pl)->sig;
        
    }
    return cantElim;
}
int eleminarDeListaNoOrdenadaDuplicados(Lista* pl, Cmp cmp);
void ordenarListaAsc(Lista* pl, Cmp cmp);
void ordenarListaDesc(Lista* pl, Cmp cmp);