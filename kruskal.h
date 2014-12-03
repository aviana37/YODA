#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: kruskal.h
**Descrição: Cabeçalho do algoritmo de Kruskal.
*/

/** \file kruskal.h
    \brief Definição do algoritmo de Kruskal.

    \fn void Kruskal(Grafo* &grafo, bool verbose)
    \brief Implementação do algoritmo de Kruskal.
    \details Se verbose ter valor false,
     as mensagens de progressão do algoritmo não são imprimidas.
*/

extern "C"{
#include <stdlib.h>
}
#include "grafo.h"

void Kruskal(Grafo* &grafo, bool verbose);

#endif // KRUSKAL_H_INCLUDED
