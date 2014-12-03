/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: main.cpp
**Descrição: Interface e gerenciamento de recursos do programa.
*/

/** \mainpage notitle
    \section Projeto_e_Análise_de_Algoritmos_-_ECO027
    André Viana Sena de Souza - 25037

    Bem-vindo!

    >><a href="files.html" target="_blank"><b>LISTA DE ARQUIVOS</b></a>

    >><a href="../../Relatório.pdf" target="_blank"><b>RELATÓRIO</b></a>

    >><a href="http://github.com/zanv/YODA" target="_blank"><b>REPOSITÓRIO</b></a>
*/

/** \file main.cpp
    \brief Interface e gerenciamento de recursos do programa.

    \def GALAXIA_100txt Endereço do arquivo do grafo de 100 vértices.
    \def GALAXIA_50txt Endereço do arquivo do grafo de 50 vértices.
    \def GALAXIA_20txt Endereço do arquivo do grafo de 20 vértices.
    \def GALAXIA_10txt Endereço do arquivo do grafo de 10 vértices.
    \def GALAXIA_5txt Endereço do arquivo do grafo de 5 vértices.

    \enum GALAXIA
    \brief Utilizada para acessar os membros do vetor de grafos.

    \enum COMANDO_MENU
    \brief Descreve todos os possíveis comportamentos que os menus podem obter do usuário.

    \var CM_DESCONHECIDO
    \brief Comando desconhecido
    \var CM_SAIR
    \brief Sair do menu.
    \var CM_IMPRIMIR
    \brief Imprimir grafos.
    \var CM_CARREGAR
    \brief Carregar grafos.
    \var CM_DESCARREGAR
    \brief Descarregar grafos.

    \var CM_GALAXIA_100
    \brief Referência ao grafo Galáxia 100.
    \var CM_GALAXIA_10
    \brief Referência ao grafo Galáxia 10.
    \var CM_GALAXIA_20
    \brief Referência ao grafo Galáxia 20.
    \var CM_GALAXIA_50
    \brief Referência ao grafo Galáxia 50.
    \var CM_GALAXIA_5
    \brief Referência ao grafo Galáxia 5.
    \var CM_TODOS
    \brief Referência a todos os grafos.
    \var CM_TODOS_SEM_VERBOSE
    \brief Referência a todos os grafos, mas sem verbose.

    \var CM_AGM,
    \brief Executar algoritmo do Kruskal.
    \var CM_DIJKSTRA,
    \brief Executar algoritmo de Dijkstra.
    \var CM_CENTRO,
    \brief Calcular o centro da Árvore Geradora Mínima.

    \fn COMANDO_MENU MenuInicial();
    \brief Pergunta ao usuário se ele deseja carregar um grafo ou sair do programa.
    \return CM_SAIR
    \return CM_CARREGAR

    \fn COMANDO_MENU MenuCarregar();
    \brief Lista os arquivos e pede que o usuário escolha qual arquivo deve ser carregado.
    \return CM_GALAXIA_100,
    \return CM_GALAXIA_10,
    \return CM_GALAXIA_20,
    \return CM_GALAXIA_50,
    \return CM_GALAXIA_5,
    \return CM_TODOS,

    \fn COMANDO_MENU MenuPrincipal();
    \brief Oferece todas as opções disponíveis ao usuário.
    \details Tais como executar algoritmos, imprimir, carregar, ou descarregar grafos, e sair.
    \return CM_SAIR,
    \return CM_IMPRIMIR,
    \return CM_CARREGAR,
    \return CM_DESCARREGAR,
    \return CM_AGM,
    \return CM_DIJKSTRA,
    \return CM_CENTRO,

    \fn COMANDO_MENU MenuExecutar(const char*, const char*);
    \brief Menu com texto personalizável. Completa os diálogos a partir das strings dadas como parâmetro.
    \details Título do menu: "Deseja (TAREFA) qual(is) grafo(s)?".\n
             Opções: "N-(VERBO) no grafo N.".
    \return CM_GALAXIA_100,
    \return CM_GALAXIA_10,
    \return CM_GALAXIA_20,
    \return CM_GALAXIA_50,
    \return CM_GALAXIA_5,
    \return CM_TODOS,
    \return CM_TODOS_SEM_VERBOSE,

    \fn void ExecutarAlgoritmoKruskal(Grafo**&, COMANDO_MENU);
    \brief Executa o algoritmo de Kruskal no(s) grafo(s) especificado(s), se carregado(s).
    \details Por default, a variável verbose tem valor true.\n
    Esse valor só será alterado se o comando especificado for CM\_TODOS\_SEM\_VERBOSE.

    \fn void ExecutarAlgoritmoDijkstra(Grafo**&, COMANDO_MENU);
    \brief Executa o algoritmo de Dijkstra no(s) grafo(s) especificado(s), se carregado(s).
    \details Por default, a variável verbose tem valor true.\n
    Esse valor só será alterado se o comando especificado for CM\_TODOS\_SEM\_VERBOSE.

    \fn void ExecutarAlgoritmoCentro(Grafo**, COMANDO_MENU);
    \brief Calcula o centro da AGM no(s) grafo(s) especificado(s), se carregado(s).
    \details Por default, a variável verbose tem valor true.\n
    Esse valor só será alterado se o comando especificado for CM\_TODOS\_SEM\_VERBOSE.\n
    No final da execução do algoritmo, o resultado é sempre impresso.

    \fn void DescarregarGrafo(Grafo**&, COMANDO_MENU);
    \brief Descarrega o(s) grafo(s) especificado(s).
    \details Lê CM\_TODOS\_SEM\_VERBOSE como CM\_TODOS.
    \fn void CarregarGrafo(Grafo**&, COMANDO_MENU);
    \brief Carrega o(s) grafo(s) especificado(s).
    \details Lê CM\_TODOS\_SEM\_VERBOSE como CM\_TODOS.

    \fn void ImprimirGalaxias(Grafo**, COMANDO_MENU);
    \brief Chama a função ImprimirGrafo(Grafo*) para todos os grafos especificados, se carregados.
    \fn int main();
    \brief Instancia o vetor de ponteiros de Grafo e delega as operações selecionadas pelo usuário para os respectivos métodos.
*/

#include "grafo.h"
#include "kruskal.h"
#include "dijkstra.h"
#include "centro.h"
#include "cronometro.h"

#define GALAXIA_100txt "UNIVERSO/galaxia_100.txt"
#define GALAXIA_10txt  "UNIVERSO/galaxia_10.txt"
#define GALAXIA_20txt  "UNIVERSO/galaxia_20.txt"
#define GALAXIA_50txt  "UNIVERSO/galaxia_50.txt"
#define GALAXIA_5txt   "UNIVERSO/galaxia_5.txt"

enum GALAXIA
{
    GALAXIA_5,
    GALAXIA_10,
    GALAXIA_20,
    GALAXIA_50,
    GALAXIA_100,
};

enum COMANDO_MENU
{
    CM_DESCONHECIDO,
    CM_SAIR,

    CM_IMPRIMIR,
    CM_CARREGAR,
    CM_DESCARREGAR,

    CM_GALAXIA_100,
    CM_GALAXIA_10,
    CM_GALAXIA_20,
    CM_GALAXIA_50,
    CM_GALAXIA_5,
    CM_TODOS,
    CM_TODOS_SEM_VERBOSE,

    CM_AGM,
    CM_DIJKSTRA,
    CM_CENTRO,
};

//Protótipos em ordem de implementação.
COMANDO_MENU MenuInicial();
COMANDO_MENU MenuCarregar();
COMANDO_MENU MenuPrincipal();
COMANDO_MENU MenuExecutar(const char*, const char*);

void ExecutarAlgoritmoKruskal(Grafo**&, COMANDO_MENU);
void ExecutarAlgoritmoDijkstra(Grafo**&, COMANDO_MENU);
void ExecutarAlgoritmoCentro(Grafo**, COMANDO_MENU);
void DescarregarGrafo(Grafo**&, COMANDO_MENU);
void CarregarGrafo(Grafo**&, COMANDO_MENU);

void ImprimirGalaxias(Grafo**, COMANDO_MENU);
int main();


/*
**IMPLEMENTAÇÕES
*/

COMANDO_MENU MenuInicial()
{
    int e;
    while(true)
    {
        printf("Selecione uma das opcoes abaixo:\n"
               "1-Carregar grafo.\n"
               "2-Sair.\n>> ");

        scanf("%d", &e);

        switch(e)
        {
        case 1:
            return CM_CARREGAR;
        case 2:
            return CM_SAIR;
        default:
            printf("Entrada nao reconhecida. Por favor, tente novamente.\n\n");
        }
    }
}
COMANDO_MENU MenuCarregar()
{
    int e;
    while(true)
    {
        printf("Deseja carregar os grafos a partir de qual(is) arquivo(s)?\n"
               "1-Carregar todos arquivos.\n"
               "2-Carregar arquivo \"%s\".\n"
               "3-Carregar arquivo \"%s\".\n"
               "4-Carregar arquivo \"%s\".\n"
               "5-Carregar arquivo \"%s\".\n"
               "6-Carregar arquivo \"%s\".\n"
               "7-Voltar.\n>> ",
               GALAXIA_5txt, GALAXIA_10txt, GALAXIA_20txt, GALAXIA_50txt, GALAXIA_100txt);

        scanf("%d", &e);

        switch(e)
        {
        case 1:
            return CM_TODOS;
        case 2:
            return CM_GALAXIA_5;
        case 3:
            return CM_GALAXIA_10;
        case 4:
            return CM_GALAXIA_20;
        case 5:
            return CM_GALAXIA_50;
        case 6:
            return CM_GALAXIA_100;
        case 7:
            return CM_SAIR;
        default:
            printf("Entrada nao reconhecida. Por favor, tente novamente.\n\n");
        }
    }
}

COMANDO_MENU MenuPrincipal()
{
    int e;
    while(true)
    {
        printf("--MENU_PRINCIPAL--\n"
               "1-Executar o algoritmo de Kruskal.\n"
               "2-Determinar os planetas no centro da Arvore Geradora Minima.\n"
               "3-Executar o algoritmo de Dijkstra.\n"
               "4-Imprimir grafo.\n"
               "5-Carregar grafo.\n"
               "6-Descarregar grafo.\n"
               "7-Sair.\n>> ");

        scanf("%d", &e);
        switch(e)
        {
        case 1:
            return CM_AGM;
        case 2:
            return CM_CENTRO;
        case 3:
            return CM_DIJKSTRA;
        case 4:
            return CM_IMPRIMIR;
        case 5:
            return CM_CARREGAR;
        case 6:
            return CM_DESCARREGAR;
        case 7:
            return CM_SAIR;
        default:
            printf("Entrada nao reconhecida. Por favor, tente novamente.\n\n");
        }
    }
}

COMANDO_MENU MenuExecutar(const char* tarefa, const char* verbo)
{
    int e;
    while(true)
    {
        printf("Deseja %s qual(is) grafo(s)?\n"
               "1-%s todos os grafos.\n"
               "2-%s todos os grafos SEM VERBOSE.\n"
               "3-%s somente no grafo Galaxia 5.\n"
               "4-%s somente no grafo Galaxia 10.\n"
               "5-%s somente no grafo Galaxia 20.\n"
               "6-%s somente no grafo Galaxia 50.\n"
               "7-%s somente no grafo Galaxia 100.\n"
               "8-Voltar.\n>> ", tarefa, verbo, verbo,
               verbo, verbo, verbo, verbo, verbo);

        scanf("%d", &e);
        switch(e)
        {
        case 1:
            return CM_TODOS;
        case 2:
            return CM_TODOS_SEM_VERBOSE;
        case 3:
            return CM_GALAXIA_5;
        case 4:
            return CM_GALAXIA_10;
        case 5:
            return CM_GALAXIA_20;
        case 6:
            return CM_GALAXIA_50;
        case 7:
            return CM_GALAXIA_100;
        case 8:
            return CM_SAIR;
        default:
            printf("Entrada nao reconhecida. Por favor, tente novamente.\n\n");
        }
    }
}
void ExecutarAlgoritmoKruskal(Grafo** &g, COMANDO_MENU qual)
{
    //Faz a chamada da execução do algoritmo de Kruskal de acordo com o comando especificado.
    if(!g)
    {
        printf("Nenhum grafo esta carregado.\n");
        return;
    }

    bool verbose=true;
    if(qual==CM_TODOS_SEM_VERBOSE)
    {
        verbose=false;
        qual = CM_TODOS;
    }

    if(qual == CM_TODOS || qual == CM_GALAXIA_5)
    {
        if(g[GALAXIA_5])
        {
            printf("Executando algoritmo de Kruskal no grafo Galaxia 5.\n");
            IniciarCronometro();
            Kruskal(g[GALAXIA_5], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 5 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_10)
    {
        if(g[GALAXIA_10])
        {
            printf("Executando algoritmo de Kruskal no grafo Galaxia 10.\n");
            IniciarCronometro();
            Kruskal(g[GALAXIA_10], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 10 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_20)
    {
        if(g[GALAXIA_20])
        {
            printf("Executando algoritmo de Kruskal no grafo Galaxia 20.\n");
            IniciarCronometro();
            Kruskal(g[GALAXIA_20], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 20 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_50)
    {
        if(g[GALAXIA_50])
        {
            printf("Executando algoritmo de Kruskal no grafo Galaxia 50.\n");
            IniciarCronometro();
            Kruskal(g[GALAXIA_50], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 50 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_100)
    {
        if(g[GALAXIA_100])
        {
            printf("Executando algoritmo de Kruskal no grafo Galaxia 100.\n");
            IniciarCronometro();
            Kruskal(g[GALAXIA_100], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 100 nao esta carregado.\n");
    }
}
void ExecutarAlgoritmoDijkstra(Grafo** &g, COMANDO_MENU qual)
{
    //Faz a chamada da execução do algoritmo de Dijkstra de acordo com o comando especificado.
    if(!g)
    {
        printf("Nenhum grafo esta carregado.\n");
        return;
    }

    bool verbose=true;
    if(qual==CM_TODOS_SEM_VERBOSE)
    {
        verbose=false;
        qual = CM_TODOS;
    }

    if(qual == CM_TODOS || qual == CM_GALAXIA_5)
    {
        if(g[GALAXIA_5])
        {
            printf("Executando algoritmo de Dijkstra no grafo Galaxia 5.\n");
            IniciarCronometro();
            Dijkstra(g[GALAXIA_5], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 5 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_10)
    {
        if(g[GALAXIA_10])
        {
            printf("Executando algoritmo de Dijkstra no grafo Galaxia 10.\n");
            IniciarCronometro();
            Dijkstra(g[GALAXIA_10], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 10 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_20)
    {
        if(g[GALAXIA_20])
        {
            printf("Executando algoritmo de Dijkstra no grafo Galaxia 20.\n");
            IniciarCronometro();
            Dijkstra(g[GALAXIA_20], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 20 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_50)
    {
        if(g[GALAXIA_50])
        {
            printf("Executando algoritmo de Dijkstra no grafo Galaxia 50.\n");
            IniciarCronometro();
            Dijkstra(g[GALAXIA_50], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 50 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_100)
    {
        if(g[GALAXIA_100])
        {
            printf("Executando algoritmo de Dijkstra no grafo Galaxia 100.\n");
            IniciarCronometro();
            Dijkstra(g[GALAXIA_100], verbose);
            printf("Pronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
        }
        else
            printf("Grafo Galaxia 100 nao esta carregado.\n");
    }
}
void ExecutarAlgoritmoCentro(Grafo** g, COMANDO_MENU qual)
{
    if(!g)
    {
        printf("Nenhum grafo esta carregado.\n");
        return;
    }

    bool verbose=true;
    if(qual==CM_TODOS_SEM_VERBOSE)
    {
        verbose=false;
        qual = CM_TODOS;
    }

    if(qual == CM_TODOS || qual == CM_GALAXIA_5)
    {
        if(g[GALAXIA_5])
        {
            if(g[GALAXIA_5]->a_agm)
            {
                printf("Determinando centro da AGM do grafo Galaxia 5.\n");
                Centro* c;
                int e;

                IniciarCronometro();

                c=DeterminarCentro(g[GALAXIA_5], verbose);
                printf("Vertices centrais: ");
                while(c->ProximoVertice(&e))
                    printf("%d ", e);

                printf("\nPronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
                delete c;
            }
            else
                printf("E necessario calcular a AGM deste grafo atraves dos algoritmos de Kruskal ou Dijkstra para ser possivel determinar o centro da Arvore Geradora Minima.\n");
        }
        else
            printf("Grafo Galaxia 5 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_10)
    {
        if(g[GALAXIA_10])
        {
            if(g[GALAXIA_10]->a_agm)
            {
                printf("Determinando centro da AGM do grafo Galaxia 10.\n");
                Centro* c;
                int e;

                IniciarCronometro();

                c=DeterminarCentro(g[GALAXIA_10], verbose);
                printf("Vertices centrais: ");
                while(c->ProximoVertice(&e))
                    printf("%d ", e);

                printf("\nPronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
                delete c;
            }
            else
                printf("E necessario calcular a AGM deste grafo atraves dos algoritmos de Kruskal ou Dijkstra para ser possivel determinar o centro da Arvore Geradora Minima.\n");
        }
        else
            printf("Grafo Galaxia 10 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_20)
    {
        if(g[GALAXIA_20])
        {
            if(g[GALAXIA_20]->a_agm)
            {
                printf("Determinando centro da AGM do grafo Galaxia 20.\n");
                Centro* c;
                int e;

                IniciarCronometro();

                c=DeterminarCentro(g[GALAXIA_20], verbose);
                printf("Vertices centrais: ");
                while(c->ProximoVertice(&e))
                    printf("%d ", e);

                printf("\nPronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
                delete c;
            }
            else
                printf("E necessario calcular a AGM deste grafo atraves dos algoritmos de Kruskal ou Dijkstra para ser possivel determinar o centro da Arvore Geradora Minima.\n");
        }
        else
            printf("Grafo Galaxia 20 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_50)
    {
        if(g[GALAXIA_50])
        {
            if(g[GALAXIA_50]->a_agm)
            {
                printf("Determinando centro da AGM do grafo Galaxia 50.\n");
                Centro* c;
                int e;

                IniciarCronometro();

                c=DeterminarCentro(g[GALAXIA_50], verbose);
                printf("Vertices centrais: ");
                while(c->ProximoVertice(&e))
                    printf("%d ", e);

                printf("\nPronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
                delete c;
            }
            else
                printf("E necessario calcular a AGM deste grafo atraves dos algoritmos de Kruskal ou Dijkstra para ser possivel determinar o centro da Arvore Geradora Minima.\n");
        }
        else
            printf("Grafo Galaxia 50 nao esta carregado.\n");
    }
    if(qual == CM_TODOS || qual == CM_GALAXIA_100)
    {
        if(g[GALAXIA_100])
        {
            if(g[GALAXIA_100]->a_agm)
            {
                printf("Determinando centro da AGM do grafo Galaxia 100.\n");
                Centro* c;
                int e;

                IniciarCronometro();

                c=DeterminarCentro(g[GALAXIA_100], verbose);
                printf("Vertices centrais: ");
                while(c->ProximoVertice(&e))
                    printf("%d ", e);

                printf("\nPronto.\nTempo de execucao: %.3fs.\n\n", TerminarCronometro());
                delete c;
            }
            else
                printf("E necessario calcular a AGM deste grafo atraves dos algoritmos de Kruskal ou Dijkstra para ser possivel determinar o centro da Arvore Geradora Minima.\n");
        }
        else
            printf("Grafo Galaxia 100 nao esta carregado.\n");
    }
}
void DescarregarGrafo(Grafo** &g, COMANDO_MENU qual)
{
    //Descarregar a galáxia especificada, ou todas.
    if(!g)
    {
        printf("Nenhum grafo esta carregado.\n");
        return;
    }

    if(qual==CM_TODOS_SEM_VERBOSE)
        qual = CM_TODOS;

    if(qual==CM_GALAXIA_5 || qual==CM_TODOS)
    {
        if(g[GALAXIA_5])
        {
            printf("Descarregando grafo Galaxia 5... ");
            delete g[GALAXIA_5];
            g[GALAXIA_5] = NULL;
            printf("Pronto.\n");
        }
        else
            printf("Grafo Galaxia 5 nao esta carregado.\n");
    }
    if(qual==CM_GALAXIA_10 || qual==CM_TODOS)
    {
        if(g[GALAXIA_10])
        {
            printf("Descarregando grafo Galaxia 10... ");
            delete g[GALAXIA_10];
            g[GALAXIA_10] = NULL;
            printf("Pronto.\n");
        }
        else
            printf("Grafo Galaxia 10 nao esta carregado.\n");
    }
    if(qual==CM_GALAXIA_20 || qual==CM_TODOS)
    {
        if(g[GALAXIA_20])
        {
            printf("Descarregando grafo Galaxia 20... ");
            delete g[GALAXIA_20];
            g[GALAXIA_20] = NULL;
            printf("Pronto.\n");
        }
        else
            printf("Grafo Galaxia 20 nao esta carregado.\n");
    }
    if(qual==CM_GALAXIA_50 || qual==CM_TODOS)
    {
        if(g[GALAXIA_50])
        {
            printf("Descarregando grafo Galaxia 50... ");
            delete g[GALAXIA_50];
            g[GALAXIA_50] = NULL;
            printf("Pronto.\n");
        }
        else
            printf("Grafo Galaxia 50 nao esta carregado.\n");
    }
    if(qual==CM_GALAXIA_100 || qual==CM_TODOS)
    {
        if(g[GALAXIA_100])
        {
            printf("Descarregando grafo Galaxia 100... ");
            delete g[GALAXIA_100];
            g[GALAXIA_100] = NULL;
            printf("Pronto.\n");
        }
        else
            printf("Grafo Galaxia 100 nao esta carregado.\n");
    }

    //Se não existir mais nenhum grafo instanciado, deletar o ponteiro do vetor.
    if(!g[GALAXIA_5] && !g[GALAXIA_10] && !g[GALAXIA_20] &&
            !g[GALAXIA_50] && !g[GALAXIA_100])
    {
        delete [] g;
        g = NULL;
    }

}

void CarregarGrafo(Grafo** &grafo, COMANDO_MENU qual)
{
    if(qual==CM_TODOS_SEM_VERBOSE)
        qual = CM_TODOS;

    if(qual==CM_GALAXIA_5 || qual==CM_TODOS)
    {
        if(!grafo)
        {
            grafo = new Grafo*[5];
            for(int c=0; c<5; c++)
                grafo[c]=NULL;

            printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_5txt);
            grafo[GALAXIA_5] = CarregarArquivo(GALAXIA_5txt);

            if(grafo[GALAXIA_5])
                printf("Arquivo carregado com sucesso.\n");
            else
            {
                printf("Arquivo nao pode ser carregado.\n");
                delete [] grafo;
                grafo = NULL;
            }
        }
        else
        {
            if(grafo[GALAXIA_5])
                printf("O grafo Galaxia 5 ja foi carregado.\n");
            else
            {
                printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_5txt);
                grafo[GALAXIA_5] = CarregarArquivo(GALAXIA_5txt);

                if(grafo[GALAXIA_5])
                    printf("Arquivo carregado com sucesso.\n");
                else printf("Arquivo nao pode ser carregado.\n");
            }
        }
    }

    if(qual==CM_GALAXIA_10 || qual==CM_TODOS)
    {
        if(!grafo)
        {
            grafo = new Grafo*[5];
            for(int c=0; c<5; c++)
                grafo[c]=NULL;

            printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_10txt);
            grafo[GALAXIA_10] = CarregarArquivo(GALAXIA_10txt);

            if(grafo[GALAXIA_10])
                printf("Arquivo carregado com sucesso.\n");
            else
            {
                printf("Arquivo nao pode ser carregado.\n");
                delete [] grafo;
                grafo = NULL;
            }
        }
        else
        {
            if(grafo[GALAXIA_10])
                printf("O grafo Galaxia 10 ja foi carregado.\n");
            else
            {
                printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_10txt);
                grafo[GALAXIA_10] = CarregarArquivo(GALAXIA_10txt);

                if(grafo[GALAXIA_10])
                    printf("Arquivo carregado com sucesso.\n");
                else printf("Arquivo nao pode ser carregado.\n");
            }
        }
    }

    if(qual==CM_GALAXIA_20 || qual==CM_TODOS)
    {
        if(!grafo)
        {
            grafo = new Grafo*[5];
            for(int c=0; c<5; c++)
                grafo[c]=NULL;

            printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_20txt);
            grafo[GALAXIA_20] = CarregarArquivo(GALAXIA_20txt);

            if(grafo[GALAXIA_20])
                printf("Arquivo carregado com sucesso.\n");
            else
            {
                printf("Arquivo nao pode ser carregado.\n");
                delete [] grafo;
                grafo = NULL;
            }
        }
        else
        {
            if(grafo[GALAXIA_20])
                printf("O grafo Galaxia 20 ja foi carregado.\n");
            else
            {
                printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_20txt);
                grafo[GALAXIA_20] = CarregarArquivo(GALAXIA_20txt);

                if(grafo[GALAXIA_20])
                    printf("Arquivo carregado com sucesso.\n");
                else printf("Arquivo nao pode ser carregado.\n");
            }
        }
    }

    if(qual==CM_GALAXIA_50 || qual==CM_TODOS)
    {
        if(!grafo)
        {
            grafo = new Grafo*[5];
            for(int c=0; c<5; c++)
                grafo[c]=NULL;

            printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_50txt);
            grafo[GALAXIA_50] = CarregarArquivo(GALAXIA_50txt);

            if(grafo[GALAXIA_50])
                printf("Arquivo carregado com sucesso.\n");
            else
            {
                printf("Arquivo nao pode ser carregado.\n");
                delete [] grafo;
                grafo = NULL;
            }
        }
        else
        {
            if(grafo[GALAXIA_50])
                printf("O grafo Galaxia 50 ja foi carregado.\n");
            else
            {
                printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_50txt);
                grafo[GALAXIA_50] = CarregarArquivo(GALAXIA_50txt);

                if(grafo[GALAXIA_50])
                    printf("Arquivo carregado com sucesso.\n");
                else printf("Arquivo nao pode ser carregado.\n");
            }
        }
    }

    if(qual==CM_GALAXIA_100 || qual==CM_TODOS)
    {
        if(!grafo)
        {
            grafo = new Grafo*[5];
            for(int c=0; c<5; c++)
                grafo[c]=NULL;

            printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_100txt);
            grafo[GALAXIA_100] = CarregarArquivo(GALAXIA_100txt);

            if(grafo[GALAXIA_100])
                printf("Arquivo carregado com sucesso.\n");
            else
            {
                printf("Arquivo nao pode ser carregado.\n");
                delete [] grafo;
                grafo = NULL;
            }
        }
        else
        {
            if(grafo[GALAXIA_100])
                printf("O grafo Galaxia 100 ja foi carregado.\n");
            else
            {
                printf("Carregando grafo a partir do arquivo \"%s\".\n", GALAXIA_100txt);
                grafo[GALAXIA_100] = CarregarArquivo(GALAXIA_100txt);

                if(grafo[GALAXIA_100])
                    printf("Arquivo carregado com sucesso.\n");
                else printf("Arquivo nao pode ser carregado.\n");
            }
        }
    }
}

void ImprimirGalaxias(Grafo** g, COMANDO_MENU c)
{
    if(c==CM_TODOS_SEM_VERBOSE)
        c = CM_TODOS;

    if(g)
    {
        if(c==CM_GALAXIA_5 || c==CM_TODOS)
        {
            printf("Imprimindo grafo Galaxia 5...\n");
            if(g[GALAXIA_5])
                ImprimirGrafo(g[GALAXIA_5]);
            else printf("Nada a ser imprimido.\n");
            printf("Pronto.\n");
        }
        if(c==CM_GALAXIA_10 || c==CM_TODOS)
        {
            printf("Imprimindo grafo Galaxia 10...\n");
            if(g[GALAXIA_10])
                ImprimirGrafo(g[GALAXIA_10]);
            else printf("Nada a ser imprimido.\n");
            printf("Pronto.\n");
        }
        if(c==CM_GALAXIA_20 || c==CM_TODOS)
        {
            printf("Imprimindo grafo Galaxia 20...\n");
            if(g[GALAXIA_20])
                ImprimirGrafo(g[GALAXIA_20]);
            else printf("Nada a ser imprimido.\n");
            printf("Pronto.\n");
        }
        if(c==CM_GALAXIA_50 || c==CM_TODOS)
        {
            printf("Imprimindo grafo Galaxia 50...\n");
            if(g[GALAXIA_50])
                ImprimirGrafo(g[GALAXIA_50]);
            else printf("Nada a ser imprimido.\n");
            printf("Pronto.\n");
        }
        if(c==CM_GALAXIA_100 || c==CM_TODOS)
        {
            printf("Imprimindo grafo Galaxia 100...\n");
            if(g[GALAXIA_100])
                ImprimirGrafo(g[GALAXIA_100]);
            else printf("Nada a ser imprimido.\n");
            printf("Pronto.\n");
        }
    }
}


int main()
{
    //Inicializando variáveis do programa.
    COMANDO_MENU c=CM_DESCONHECIDO;
    Grafo** grafo = NULL;
    bool* agm = new bool[5];
    for(int d=0; d<5; d++)
        agm[d]=false;

    //Imprimindo cabeçalho de apresentação.
    printf("Projeto #4 - YODA\n"
           "25037 - Andre Viana\n\n");

    //Enquanto não for efetuado um comando de saída do programa.
    while(c!=CM_SAIR)
    {
        //Se nenhum grafo estiver carregado.
        if(!grafo)
        {
            c=MenuInicial();

            if(c==CM_CARREGAR)
            {
                printf("\n");
                c=MenuCarregar();

                if(c!=CM_SAIR)
                {
                    CarregarGrafo(grafo, c);
                    printf("\n");
                }
                else
                    c=CM_DESCONHECIDO;
            }
        }

        //Ou se existir pelo menos um grafo carregado.
        else
        {
            c=MenuPrincipal();

            switch(c)
            {
            case CM_AGM:
                c=MenuExecutar("executar o algoritmo de Kruskal em", "Calcular");
                if(c!=CM_SAIR)
                {
                    ExecutarAlgoritmoKruskal(grafo, c);
                    printf("\n");
                }
                else c=CM_DESCONHECIDO;
                break;

            case CM_CENTRO:
                c=MenuExecutar("determinar o centro da Arvore Geradora Minima de", "Calcular");
                if(c!=CM_SAIR)
                {
                    ExecutarAlgoritmoCentro(grafo, c);
                    printf("\n");
                }
                else c=CM_DESCONHECIDO;
                break;

            case CM_DIJKSTRA:
                c=MenuExecutar("executar o algoritmo de Dijkstra em", "Calcular");
                if(c!=CM_SAIR)
                {
                    ExecutarAlgoritmoDijkstra(grafo, c);
                    printf("\n");
                }
                else c=CM_DESCONHECIDO;
                break;

            case CM_IMPRIMIR:
                c=MenuExecutar("imprimir", "Imprimir");
                if(c!=CM_SAIR)
                {
                    ImprimirGalaxias(grafo, c);
                    printf("\n");
                }
                else c=CM_DESCONHECIDO;
                break;

            case CM_CARREGAR:
                c=MenuCarregar();
                if(c!=CM_SAIR)
                {
                    CarregarGrafo(grafo, c);
                    printf("\n");
                }
                else c=CM_DESCONHECIDO;
                break;

            case CM_DESCARREGAR:
                c=MenuExecutar("descarregar", "Descarregar");
                if(c!=CM_SAIR)
                {
                    DescarregarGrafo(grafo, c);
                    printf("\n");
                }
                else
                    c=CM_DESCONHECIDO;
                break;
            }
        }
    }

    //Destruir grafos existentes e sair.
    if(grafo)
    {
        printf("Descarregando grafos... ");

        //Iterar por todos grafos, deletando os que estão instanciados.
        for(int c=0; c<5; c++)
        {
            if(grafo[c])
                delete grafo[c];
        }

        //Desalocando o vetor.
        delete [] grafo;

        printf("Pronto.\n");
    }

    //Retornar código de sucesso.
    return 0;
}
