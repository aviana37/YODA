#include "dijkstra.h"

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: dijkstra.h
**Descrição: Implementação do algoritmo de Dijkstra.
*/

/**
    \file dijkstra.cpp
    \brief Implementação do algoritmo de Dijkstra.
*/

void Dijkstra(Grafo* &grafo, bool verbose)
{
    if(grafo)
    {
        if(verbose)
            printf("Inicializando variaveis.\n");

        //Inicializando variáveis.
        Heap* heap;
        int u, v;
        Grafo::Aresta buff;

        for(int c=0; c<grafo->nv; c++)
        {
            grafo->v[c].peso = INT_MAX;
            grafo->v[c].ant = -1;
        }

        //Removendo a AGM do grafo caso ela exista.
        if(grafo->a_agm)
        {
            delete grafo->a_agm;
            grafo->a_agm = NULL;
        }

        if(verbose)
            printf("Construindo heap. ");

        //Atribuindo peso zero à raiz.
        grafo->v[0].peso = 0;

        //Construindo heap.
        heap = new Heap(grafo->v, grafo->nv);

        if(verbose)
        {
            printf("Pronto.\n");
            printf("HEAP INICIAL:\n");
            heap->ImprimirEstado();
            printf("\n");
        }

        //Enquanto o heap não estiver vazio.
        while(!heap->Vazio())
        {
            //Retirar vértice mínimo.
            u=heap->RetirarMinimo();

            if(verbose)
                printf("Verificando arestas de %d:\n", u);

            //Processar arestas do vértice mínimo.
            grafo->v[u].ProximaArestaAdj(NULL);
            while(grafo->v[u].ProximaArestaAdj(&buff))
            {
                v=buff.destino;
                if(verbose)
                    printf("Comparando aresta %d -> %d.\n", u, v);

                //Se o peso de algum dos vértices adjacentes ao vértice mínimo for maior que o peso do
                // vértice mínimo + o peso da aresta
                if(grafo->v[v].peso > (grafo->v[u].peso + buff.peso))
                {
                    if(verbose)
                    {
                        if(grafo->v[v].peso != INT_MAX)
                            printf("O vertice %d (%d) tem peso maior que %d + %d.\n", v, grafo->v[v].peso,
                                   grafo->v[u].peso, buff.peso);
                        else
                            printf("O vertice %d (\u221E) tem peso maior que %d + %d.\n", v, grafo->v[u].peso, buff.peso);
                        printf("Vertice %d recebe peso %d.\n", v, grafo->v[u].peso + buff.peso);
                    }

                    //O vértice adjacente é descoberto pelo vértice mínimo na AGM.
                    grafo->v[v].ant = u;

                    //O vértice adjacente recebe peso igual ao peso do vértice mínimo mais o da aresta ligando os dois.
                    grafo->v[v].peso = grafo->v[u].peso + buff.peso;

                    //O vértice adjacente tem seu peso atualizado no heap, e o heap se reconstroi.
                    heap->AtualizarVertice(v, grafo->v[u].peso + buff.peso);


                    //Caso alguma aresta antiga da AGM tenha conflito com nova, é feita uma substituição.
                    int inc=0;
                    bool sub=false;
                    Grafo::Aresta e;
                    grafo->ProximaArestaAGM(NULL);
                    while(grafo->ProximaArestaAGM(&e))
                    {
                        if(e.destino == buff.destino)
                        {
                            if(verbose)
                                printf("Removendo aresta %d -> %d da arvore geradora minima.\n", e.origem, e.destino);
                            grafo->a_agm->at(inc).origem = u;
                            sub=true;
                            break;
                        }
                        inc++;
                    }

                    if(verbose)
                        printf("Adicionando aresta %d -> %d a arvore geradora minima.\n", buff.origem, buff.destino);

                    //Se nenhuma aresta foi substituída, adicionar a nova aresta à AGM.
                    if(!sub)
                        grafo->AdicionarArestaAGM(buff);


                    if(verbose)
                    {
                        printf("Heap atualizado:\n");
                        heap->ImprimirEstado();
                        printf("\n");
                    }
                }
                else if(verbose)
                    printf("Nada a ser feito.\n");
            }
            if(verbose)
                printf("\n");
        }
        delete heap;
    }
}
