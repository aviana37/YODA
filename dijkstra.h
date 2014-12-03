#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: dijkstra.h
**Descrição: Cabeçalho do algoritmo de Dijkstra.
*/

/**
    \file dijkstra.h
    \brief Definição do algoritmo de Dijkstra.

    \fn void Dijkstra(Grafo* &grafo, bool verbose)
    \brief Implementação do algoritmo.
    \details Se verbose ter valor false,
     as mensagens de progressão do algoritmo não são imprimidas.
*/

#include "grafo.h"
#include "heap.h"

void Dijkstra(Grafo* &grafo, bool verbose);

#endif // DIJKSTRA_H_INCLUDED
