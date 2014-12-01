#include "heap.h"

bool Heap::Vertice::operator<(Heap::Vertice outro)
{
    if(this->p > outro.p)
        return true;
    return false;
}
Heap::Heap(Grafo::Vertice* vertices, int n)
{
    this->n = n;
    heap = new std::vector<Vertice>;

    heap->reserve(n);
    for(int c=0;c<n;c++)
    {
        heap->push_back({vertices[c].peso, c});
        std::make_heap(heap->begin(), heap->end());
    }
}

Heap::~Heap()
{
    if(heap)
        delete heap;
}

int Heap::RetirarMinimo()
{
    int minimo=-1;
    if(!heap->empty())
    {
        std::pop_heap(heap->begin(), heap->end());
        minimo = heap->back().v;
        heap->pop_back();
    }
    return minimo;
}
void Heap::AtualizarVertice(int v, int novo)
{
    for(std::vector<Vertice>::iterator it = heap->begin(); it!=heap->end(); it++)
    {
        if(it->v == v)
        {
            it->p = novo;
            std::make_heap(heap->begin(), heap->end());
            break;
        }
    }
}
bool Heap::Vazio()
{
    return heap->empty();
}

void Heap::ImprimirEstado()
{
    printf("VERTICE\t|PESO\n");
    for(std::vector<Vertice>::iterator it = heap->begin(); it!=heap->end(); it++)
    {
        if(it->p == INT_MAX)
            printf("%d\t| \u221E\n", it->v);
        else
            printf("%d\t| %d\n", it->v, it->p);
    }
}




