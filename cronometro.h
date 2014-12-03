#ifndef CRONOMETRO_H_INCLUDED
#define CRONOMETRO_H_INCLUDED

/*André Viana Sena de Souza - 25037
**Projeto e Análise de Algoritmos - ECO027
**Projeto #4 - YODA - 03/12/2014
**Arquivo: cronometro.h
**Descrição: Define o elementos do módulo cronômetro.
    Métodos para contagem de tempo.
*/

/** \file cronometro.h
    \brief Métodos para contagem de tempo.

    \fn void IniciarCronometro()
    \brief Inicializa o temporizador.

    \fn float TerminarCronometro()
    \return Retorna quantos segundos se passaram desde a última inicialização do cronômetro.
*/

#include <time.h>

void IniciarCronometro();
float TerminarCronometro();

#endif // CRONOMETRO_H_INCLUDED
