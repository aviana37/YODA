#ifndef CENTRO_H_INCLUDED
#define CENTRO_H_INCLUDED

#include "grafo.h"
#include <vector>

struct Centro
{
    std::vector<int>* c;

    Centro();
    ~Centro();

    void AdicionarVertice(int);
    bool ProximoVertice(int*);
};

void CriarMatrizAdj(Grafo* grafo, int* grau, int** matriz_adj);
int VerticeFolha(int** matriz_adj, int n);
Centro* DeterminarCentro(Grafo* grafo, bool verbose);

#endif // CENTRO_H_INCLUDED
