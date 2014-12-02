#include "kruskal.h"

void Kruskal(Grafo* &grafo, bool verbose)
{
    if(grafo)
    {
        if(verbose)
            printf("Inicializando variaveis.\n");

        int atual=0;                  //Aresta atual;
        bool* vd=new bool[grafo->nv]; //Vértices que não devem ser descobertos por novas arestas.

        //Deletando a árvore geradora mínima do grafo, caso ela exista.
        if(grafo->a_agm)
        {
            delete grafo->a_agm;
            grafo->a_agm = NULL;
        }
        //Marcando o peso dos vértices como valor não calculado, e inicializando vd.
        for(int c=0;c<grafo->nv;c++)
        {
            vd[c] = false;
            grafo->v[c].peso = -1;
        }

        //Executando algoritmo...

        if(verbose)
            printf("Ordenando arestas de acordo com o peso.\n");
        //Ordenando arestas de acordo com o peso.
        qsort(grafo->a, grafo->na, sizeof(Grafo::Aresta), Grafo::Aresta::Comparador);

        if(verbose)
            printf("Processando arestas do grafo.\n");
        //Processando todas as arestas do grafo.
        while(atual < grafo->na)
        {
            if(verbose)
                printf("Verificando aresta %d->%d (%d). ", grafo->a[atual].origem, grafo->a[atual].destino, grafo->a[atual].peso);

            //Se o destino da aresta atual não foi descoberto.
            if(!vd[grafo->a[atual].destino])
            {
                //Marcar a origem da aresta atual como já descoberto, atribuir o seu valor como antecessor do vértice destino,
                //e adicionar aresta à Árvore Geradora Mínima do grafo.
                vd[grafo->a[atual].origem] = true;
                grafo->AdicionarArestaAGM(grafo->a[atual]);
                grafo->v[grafo->a[atual].destino].ant = grafo->a[atual].origem;

                if(verbose)
                    printf("Aresta e minima, e nao forma ciclo.\n"
                           "Adicionando aresta a arvore geradora minima.\n");
            }
            else
                printf("Aresta forma ciclo.\n");

            //Se a AGM já tem N_Vértices-1 arestas, finalizar o loop.
            if(grafo->a_agm->size() == grafo->nv-1)
                break;

            atual++;
        }

        if(verbose)
            printf("Arvore geradora minima criada com sucesso.\n");

        delete [] vd;
    }
}
