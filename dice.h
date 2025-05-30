#pragma once
#include <iostream>
#include <random>
class dice
{
private:
	// Atributos
	int lim_inf;
	int lim_sup;
	std::mt19937 gen;  // Generador de n�meros aleatorios
	std::uniform_int_distribution<> distrib;  // Distribuci�n para generar n�meros entre lim_inf y lim_sup

public:
	// Constructor
	dice();

	// M�todos
	int roll();
};

