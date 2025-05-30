#pragma once
#include "dice.h"
class	MyGame
{
private:
	// Atributos
	char board[30]; //Tablero
	int playerPositions[2]; // Arreglo con posicion de cada jugador
	dice dado; // Objeto dado
	int currentPlayer; // Número para identificar el turno del jugador
	int turnLimit; // Limite de turnos
	int turnCount; // Contador para turno
	void initializeBoard(); // Función para inicializar el tablero
	void processTurn(); // Función para procesar el turno 
	bool gameStatus; // Booleano para saber si el juego ya acabó o sigue 

public:
	MyGame(); //Constructos
	// Métodos
	void start(); // Para empezar el juego
	void printInstructions(); // Para tener las instrucciones del juego
};

