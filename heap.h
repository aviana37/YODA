#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: heap.h
**Descrição: Classe mínimo para o algoritmo de Dijkstra.
*/

/** \file heap.h
    \brief Definição da classe Heap para o Algoritmo de Dijkstra().

    \class Heap
    \brief Classe utilizada na implementação do Algoritmo de Dijkstra.
    \details Implementação de um heap mínimo indireto.

    \struct Heap::Vertice
    \brief Armazena o endereço do vértice e seu peso.

    \var Heap::Vertice::p
    \brief Peso do vértice.

    \var Heap::Vertice::v
    \brief Indexador do vértice.

    \fn Heap::Vertice::operator<(Heap::Vertice)
    \brief Faz com que Vértices sejam ordenados pelo peso.
    \note O macro std::MAKE\_HEAP foi projetado para criar um heap máximo,
        e não mínimo. Logo, este operador retorna true somente quando a>b,
        para que seja possível criar um heap mínimo através do macro.

    \var Heap::heap
    \brief O vetor base do heap.
    \details Ordenado através do macro std::MAKE_HEAP.

    \fn Heap::Heap(Grafo::Vertice, int)
    \brief Lê o vetor de vértices de um grafo e constroi o heap.

    \fn Heap::~Heap()
    \brief Destroi o heap.

    \fn Heap::AtualizarVertice(int, int)
    \brief Atualiza o peso do vértice v para novo e reconstroi o heap.

    \fn Heap::Vazio()
    \return True se o heap está vazio.
    \return False se o heap tem componentes.

    \fn Heap::RetirarMinimo()
    \brief Remove vértice mínimo do heap.
    \return O indexador do vértice mínimo.

    \fn Heap::ImprimirEstado()
    \brief Imprime o estado atual do heap, na ordem do vetor, em colunas Vértice e Peso.
*/

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
