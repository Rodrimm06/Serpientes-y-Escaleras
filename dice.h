#pragma once
#include <iostream>
#include <random>
class dice
{
private:
	// Atributos
	int lim_inf;
	int lim_sup;
	std::mt19937 gen;  // Generador de números aleatorios
	std::uniform_int_distribution<> distrib;  // Distribución para generar números entre lim_inf y lim_sup

public:
	// Constructor
	dice();

	// Métodos
	int roll();
};

