#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "grafo.h"
#include <vector>
#include <algorithm>

class Heap
{
private:
    struct Vertice
    {
        int p, v;
        bool operator<(Heap::Vertice outro);
    };
    std::vector<Vertice>* heap;

public:
    Heap(Grafo::Vertice* vertices, int n);
    ~Heap();

    void AtualizarVertice(int v, int novo);
    bool Vazio();

    int RetirarMinimo();
    void ImprimirEstado();
};
#endif // HEAP_H_INCLUDED
