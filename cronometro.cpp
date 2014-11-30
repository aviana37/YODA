#include "cronometro.h"

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
