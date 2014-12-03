#include "centro.h"

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: centro.cpp
**Descrição: Implementação do cabeçalho centro.h.
*/

/** \file centro.cpp
    \brief Implementação de centro.h
*/

Centro::Centro()
{
    c=NULL;
}
Centro::~Centro()
{
    if(c)
        delete c;
}
void Centro::AdicionarVertice(int v)
{
    if(!c)
        c=new std::vector<int>;
    c->push_back(v);
}
bool Centro::ProximoVertice(int* v)
{
    //Iterar pela próxima aresta do vector ou inicializar o iterador
    // se v == NULL.

    static int atual=-1;
    if(c && v)
    {
        atual++;
        if(atual>=c->size())
            return false;
        *v=c->at(atual);
        return true;
    }
    if(!v)
        atual=-1;
    return false;
}

void CriarMatrizAdj(Grafo* grafo, int* grau, int** matriz_adj)
{
    //Lê as arestas AGM do grafo e inicializa os valores do vetor de grau e da matriz de adjacências.
    //É necessário instanciar a matriz e o vetor antes de se chamar essa função.

    if(grafo)
    {
        Grafo::Aresta buff;

        for(int i=0; i<grafo->nv; i++)
            grau[i]=0;
        for(int i=0; i<grafo->nv; i++)
            for(int j=0; j<grafo->nv; j++)
                matriz_adj[i][j] = 0;

        grafo->ProximaArestaAGM(NULL);
        while(grafo->ProximaArestaAGM(&buff))
            matriz_adj[buff.origem][buff.destino] = 1;

        for(int i=0; i<grafo->nv; i++)
            for(int j=0; j<grafo->nv; j++)
            {
                if(matriz_adj[i][j])
                {
                    grau[i]++;
                    grau[j]++;
                }
            }
    }
}

int VerticeFolha(int** matriz_adj, int* grau, int n)
{
    //Procura por vértices folha na matriz de adjacências, retornando o primeiro encontrado.
    //Se nenhum vértice folha estiver presente, o retorno é -1.

    int atual=0;
    bool folha;

    while(atual < n)
    {
        folha=true;
        for(int i=0; i<n; i++)
        {
            if(matriz_adj[atual][i]>0)
                folha=false;
        }

        if(folha && grau[atual])
            return atual;
        atual++;
    }
    return -1;
}

Centro* DeterminarCentro(Grafo* grafo, bool verbose)
{
    //Elimina folhas da AGM do grafo sistematicamente.
    //Uma vez que um vértice se isola durante o processo,
    // é seguro assumir que este vértice é central, pois os grafos são direcionados.

    Centro* ret=new Centro;
    if(grafo && grafo->a_agm)
    {
        if(verbose)
            printf("Inicializando variáveis.\n");

        //Inicializando variáveis.
        int* grau;
        int** matriz_adj;
        bool* folhas;

        grau=new int[grafo->nv];
        folhas = new bool[grafo->nv];
        matriz_adj= new int*[grafo->nv];
        for(int c=0; c<grafo->nv; c++)
        {
            matriz_adj[c]=new int[grafo->nv];
            folhas[c] = false;
        }

        if(verbose)
            printf("Criando matriz de adjacencias.\n");

        //Atribuindo valor inicial à matriz de adjacências e vetor de grau,
        // através vértices da agm do grafo.
        CriarMatrizAdj(grafo, grau, matriz_adj);


        if(verbose)
        {
            printf("Matriz de adjacencias:\n");
            for(int i=0;i<grafo->nv;i++)
            {
                for(int j=0;j<grafo->nv;j++)
                    printf("%d ", matriz_adj[i][j]);
                printf("\n");
            }

            printf("Grau dos vertices:\n");
            for(int i=0;i<grafo->nv;i++)
                printf("%d = %d\n", i, grau[i]);
            printf("\n");

            printf("Processando vertices...\n");
        }

        //Procurando por vértices folha.
        int f=VerticeFolha(matriz_adj, grau, grafo->nv);

        //Enquanto existirem vértices folha
        while(f>-1)
        {
            if(verbose)
                printf("Vertice folha encontrado: %d.\n", f);

            if(verbose)
                printf("Eliminando vertice da arvore.\nAtualizando matriz de adjacencias e grau dos vertices.\n");

            //Marcar vértice atual como folha.
            folhas[f]=true;

            //Retirar vértice da matriz de adjacências, destruindo suas conexões.
            for(int c=0; c<grafo->nv; c++)
            {
                if(matriz_adj[f][c]>0)
                    matriz_adj[f][c]--;
                if(matriz_adj[c][f]>0)
                    matriz_adj[c][f]--;

                grau[c]=0;
            }

            //Recalcular grau dos vértices.
            for(int i=0; i<grafo->nv; i++)
                for(int j=0; j<grafo->nv; j++)
                {
                    if(matriz_adj[i][j]>0)
                    {
                        grau[i]++;
                        grau[j]++;
                    }
                }

            if(verbose)
                printf("Procurando por vertices isolados...\n");

            //Buscar vértices que tem grau zero, mas ainda não foram marcados como folha.
            for(int c=0;c<grafo->nv;c++)
            {
                if(!grau[c] && !folhas[c])
                {
                    if(verbose)
                        printf("Vertice isolado encontrado: %d.\nAdicionando %d a lista de vertices centrais.\n", c, c);

                    //Adicionar vértice isolado ao conjunto de vértices centrais e marcá-lo como folha.
                    ret->AdicionarVertice(c);
                    folhas[c]=true;
                }
            }
            if(verbose)
                printf("\n");

            //Buscar pelo próximo vértice folha e iterar novamente.
            f=VerticeFolha(matriz_adj, grau, grafo->nv);
        }
        return ret;
    }

    return NULL;
}
