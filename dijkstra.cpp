#include "dijkstra.h"

void Dijkstra(Grafo* &grafo, bool verbose)
{
    if(grafo)
    {
        if(verbose)
            printf("Inicializando variaveis.\n");

        Heap* heap;
        int u, v;
        Grafo::Aresta buff;

        for(int c=0; c<grafo->nv; c++)
        {
            grafo->v[c].peso = INT_MAX;
            grafo->v[c].ant = -1;
        }

        if(grafo->a_agm)
        {
            delete grafo->a_agm;
            grafo->a_agm;
        }

        if(verbose)
            printf("Construindo heap. ");

        grafo->v[0].peso = 0;
        heap = new Heap(grafo->v, grafo->nv);

        if(verbose)
        {
            printf("Pronto.\n");
            printf("HEAP INICIAL:\n");
            heap->ImprimirEstado();
            printf("\n");
        }

        while(!heap->Vazio())
        {
            u=heap->RetirarMinimo();

            if(verbose)
                printf("Verificando arestas de %d:\n", u);

            grafo->v[u].ProximaArestaAdj(NULL);
            while(grafo->v[u].ProximaArestaAdj(&buff))
            {
                v=buff.destino;
                if(verbose)
                    printf("Comparando aresta %d -> %d.\n", u, v);

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

                    grafo->v[v].ant = u;
                    grafo->v[v].peso = grafo->v[u].peso + buff.peso;
                    heap->AtualizarVertice(v, grafo->v[u].peso + buff.peso);

                    int inc=0;
                    Grafo::Aresta e;
                    grafo->ProximaArestaAGM(NULL);
                    while(grafo->ProximaArestaAGM(&e))
                    {
                        if(e.destino == buff.destino)
                        {
                            if(verbose)
                                printf("Removendo aresta %d -> %d da arvore geradora minima.\n", e.origem, e.destino);
                            grafo->a_agm->at(inc).origem = u;
                            break;
                        }
                        inc++;
                    }

                    if(verbose)
                        printf("Adicionando aresta %d -> %d a arvore geradora minima.\n", buff.origem, buff.destino);
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
