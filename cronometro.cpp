#include "cronometro.h"

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: cronometro.cpp
**Descrição: Implementação do cabeçalho cronometro.h.
*/

/** \file cronometro.cpp
    \brief Implementação de cronometro.h e temporizador.

    \var clock_t chrono
    \brief Temporizador.
*/

static clock_t chrono;

void IniciarCronometro()
{
    chrono = clock();
}
float TerminarCronometro()
{
    chrono = clock() - chrono;
    return ((float) chrono/CLOCKS_PER_SEC);
}
