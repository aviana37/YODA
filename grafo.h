#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: grafo.h
**Descrição: Define o elementos do módulo grafo.
    Responsável pelo tipo de dados grafo e
     todas operações básicas relacionadas à ele,
     como manipulação de vértices,
     arestas, leitura de arquivos,
     e impressão dos seus componentes.
*/

/** \file grafo.h
    \brief Cabeçalho do módulo grafo.
    \details Responsável pelo tipo de dados grafo e
     todas operações básicas relacionadas à ele,
     como manipulação de vértices,
     arestas, leitura de arquivos,
     e impressão dos seus componentes.

    \struct Grafo::Aresta
    \brief Aresta do grafo.
    \details Define os vértices origem, destino, e distância entre eles através da variável peso.

    \var Grafo::Aresta::origem
    Vértice inicial.

    \var Grafo::Aresta::destino
    Vértice final.

    \var Grafo::Aresta::peso
    Peso da aresta, também conhecido como distância entre planetas.

    \fn int Grafo::Aresta::Comparador(const void* a, const void* b)
    \brief Função comparadora, útil durante o Algoritmo de Kruskal.
    \details estático utilizado como parâmetro no uso da função qsort no algoritmo de Kruskal.
        No algoritmo é necessário ordenar um vetor de arestas em ordem crescente.
        Esta função compara as arestas por peso para que o método qsort funcione corretamente.
    \return 0 se a.peso==b.peso.
    \return 1 se a.peso>b.peso.
    \return -1 se a.peso<b.peso.


    \struct Grafo::Vertice
    \brief Vértice do grafo.
    \details Armazena o peso do vértice, seu antecessor, suas arestas adjacentes,
     e a quantidade de tropas estacionadas no planeta.

    \var Grafo::Vertice::ant
    \brief Vértice anterior à este, segundo a AGM.
    \details Se seu valor é -1, ele não tem vértice antecessor ou não foi calculado ainda.

    \var Grafo::Vertice::adj
    \brief Conteiner dinâmico para arestas adjacentes.

    \var Grafo::Vertice::peso
    \brief Peso do vértice.
    \details Recebe valor durante o algoritmo de Dijkstra.
     Se seu valor é -1, significa que seu peso não foi calculado ainda.

    \var Grafo::Vertice::tropas
    \brief Armazena a quantidade de tropas que o planeta tem em sua guarnição.

    \fn void Grafo::Vertice::AdicionarArestaAdj(Grafo::Aresta)
    \brief Adiciona uma aresta à lista de arestas adjacentes.
    \details Instancia adj* caso esteja nulo.

    \fn bool Grafo::Vertice::ProximaArestaAdj(Grafo::Aresta*)
    \brief Itera pelas arestas adjacentes do vértice.
    \details Quando o parâmetro é não-nulo,
     ele passa a apontar para a próxima aresta adjacente na lista.
     \note Chamadas com parâmetro NULL inicializam o iterador interno.
     \return True enquanto for possível fazer atribuições.
     \return False se a lista chegar ao final.

    \struct Grafo
    \brief Estrutura de dados Grafo.
    \details O tipo grafo define a estrutura base utilizada no programa.
     Nele estão contidas as arestas e vértices do grafo, e também métodos para acesso às arestas da AGM.

    \var Grafo::v
    \brief Vértices do Grafo.

    \var Grafo::a
    \brief Arestas do Grafo.

    \var Grafo::a_agm
    \brief Conteiner dinâmico para arestas da AGM do grafo.
    \details Recomenda-se utilizar os métodos auxiliares para adicionar e iterar pelas arestas.

    \var Grafo::nv
    \brief Número de vértices do grafo.

    \var Grafo::na
    \brief Número de arestas do grafo.

    \fn Grafo::Grafo()
    \brief Inicializa as variáveis internas do grafo.

    \fn Grafo::~Grafo()
    \brief Destroi as variáveis internas do grafo se instanciadas.

    \fn Grafo::AdicionarArestaAGM(Grafo::Aresta)
    \brief Adiciona uma aresta à árvore geradora mínima do grafo.

    \fn Grafo::ProximaArestaAGM(Grafo::Aresta*)
    \brief Itera pelas arestas da AGM.
    \details Quando o parâmetro é não-nulo,
     ele passa a apontar para a próxima aresta adjacente na lista.
    \note Chamadas com parâmetro NULL inicializam o iterador interno.
     \return True enquanto for possível fazer atribuições.
     \return False se a lista chegar ao final.

    \fn Grafo* CarregarArquivo(const char*)
    \brief Carrega um grafo a partir de um endereço do arquivo.
    \return NULL se o arquivo não puder ser aberto.
    \return Grafo* se o grafo for carregado.

    \fn void ImprimirGrafo(Grafo*)
    \brief Imprime os vértices, arestas, e arestas AGM do grafo em colunas.
*/

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
