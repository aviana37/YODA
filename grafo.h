#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <vector>

extern "C"{
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
}

struct Grafo
{
    struct Aresta
    {
        int origem,
            destino;

        int peso;
        static int Comparador(const void*, const void*);
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
    std::vector<Aresta>* a_agm;
    int nv;
    int na;

    Grafo();
    ~Grafo();

    void AdicionarArestaAGM(Aresta aresta);
    bool ProximaArestaAGM(Aresta* aresta);
};

Grafo* CarregarArquivo(const char*);

void ImprimirGrafo(Grafo*);

#endif // GRAFO_H_INCLUDED
