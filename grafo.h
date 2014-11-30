#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <vector>

extern "C"{
#include <stdio.h>
#include <stddef.h>
}

struct Grafo
{
    struct Aresta
    {
        int origem,
            destino;

        int peso;
        int Comparador(const void*, const void*);
    };
    struct Vertice
    {
        int peso;
        int ant;
        std::vector<Aresta>* adj;

        void AdicionarArestaAdj(Aresta a_adj);
        bool ProximaArestaAdj(Aresta* a_adj);

        Vertice();
        ~Vertice();

        int tropas;
    };

    Vertice* v;
    Aresta* a;
    int nv;
    int na;


//  Grafo(int n_vertices, int* peso_vertices, int n_arestas, Aresta* arestas);
    Grafo();
    ~Grafo();
};

Grafo* CarregarArquivo(const char*);

void ImprimirGrafo(Grafo*);
void ImprimirCentro(Grafo*);


#endif // GRAFO_H_INCLUDED
