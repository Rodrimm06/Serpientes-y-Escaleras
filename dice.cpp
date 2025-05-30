#include "dice.h"
#include <random>

// Constructor
dice::dice() : lim_inf(1), lim_sup(6), gen(std::random_device{}()), distrib(lim_inf, lim_sup) {
    // Inicializa el generador y la distribuci�n una sola vez en el constructor
}

// M�todo que genera un n�mero aleatorio entre lim_inf y lim_sup
int dice::roll() {
    return distrib(gen);  // Genera el n�mero aleatorio usando el generador y la distribuci�n
}
