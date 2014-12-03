#include "heap.h"

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: heap.cpp
**Descrição: Implementação da classe Heap.
*/

/** \file heap.cpp
    \brief Implementação da classe Heap.
*/

bool Heap::Vertice::operator<(Heap::Vertice outro)
{
    //Retorna se o peso de this é MAIOR (não menor) que o de outro.
    return(this->p > outro.p);
}

Heap::Heap(Grafo::Vertice* vertices, int n)
{
    heap = new std::vector<Vertice>;

    //Reservar espaço no heap.
    heap->reserve(n);

    //Adicionar vértices e pesos ao heap.
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
        //Remover valor mínimo do heap.
        std::pop_heap(heap->begin(), heap->end());
        minimo = heap->back().v;
        heap->pop_back();
    }
    return minimo;
}
void Heap::AtualizarVertice(int v, int novo)
{
    //Procurar pelo vértice v
    for(std::vector<Vertice>::iterator it = heap->begin(); it!=heap->end(); it++)
    {
        if(it->v == v)
        {
            //Alterar o peso de v e reconstruir o heap.
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
    //Imprime colula a coluna o vértice e o seu peso, colocando o símbolo de Infinito caso
    //o peso tenha o mesmo valor que INT_MAX.

    printf("VERTICE\t|PESO\n");
    for(std::vector<Vertice>::iterator it = heap->begin(); it!=heap->end(); it++)
    {
        if(it->p == INT_MAX)
            printf("%d\t| \u221E\n", it->v);
        else
            printf("%d\t| %d\n", it->v, it->p);
    }
}




