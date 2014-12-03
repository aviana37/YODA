#ifndef CENTRO_H_INCLUDED
#define CENTRO_H_INCLUDED

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: centro.h
**Descrição: Cabeçalho do módulo cálculo do centro.
*/

/** \file centro.h
    \brief Definição do algoritmo de cálculo do centro da AGM.

    \struct Centro
    \brief Conteiner dinâmico para vértices centrais da AGM.
    \var Centro::c
    \brief Variável base do conteiner Centro.

    \fn Centro::Centro()
    \brief Inicializa o conteiner interno.

    \fn Centro::~Centro()
    \brief Destroi o conteiner interno se instanciado.

    \fn void Centro::AdicionarVertice(int)
    \brief Adiciona um vértice à lista de vértices do centro.

    \fn bool Centro::ProximoVertice(int*)
    \brief Itera pelos vértices do centro.
    \details Quando o parâmetro é não-nulo,
     ele passa a apontar para a próxima aresta adjacente na lista.
     \note Chamadas com parâmetro NULL inicializam o iterador interno.
     \return True enquanto for possível fazer atribuições.
     \return False se a lista chegar ao final.


    \fn void CriarMatrizAdj(Grafo*, int*, int**)
    \brief Atualiza os valores da matriz de adjacências e do vetor de grau dos vértices
    \details Através da leitura dos vértices da árvore geradora mínima do grafo.
    \note Os parâmetros grau e matriz\_adj devem ser instanciados antes da chamada deste método.

    \fn int VerticeFolha(int**, int)
    \brief Procura por vértices folha na matriz de adjacências.
    \return Retorna o primeiro vértice folha que for encontrado na matriz de adjacências.
    \return -1 caso não exista nenhum vértice folha.

    \fn Centro* DeterminarCentro(Grafo*, bool)
    \brief Calcula o centro da AGM de um grafo.
    \return Ponteiro de struct Centro preenchido com os vértices centrais do grafo.
    \details Se verbose ter valor false,
     as mensagens de progressão do algoritmo não são imprimidas.
*/

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
