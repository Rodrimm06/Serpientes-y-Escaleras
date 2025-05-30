#include "MyGame.h"
// Constructor
MyGame::MyGame() :currentPlayer(0), turnLimit(20), turnCount(1), gameStatus(true) {
	playerPositions[0] = 1;
	playerPositions[1] = 1;
	initializeBoard(); // Se crea el tablero 
	
}

// Funcion para inicializar el tablero
void MyGame::initializeBoard(){
	// For para recorrer el arreglo y llenarlo de casillas normales
	for (int i = 0; i < 30; i++) {
		board[i] = 'N';
	}
	// Se crean las escaleras y serpientes
	board[5] = 'S';
	board[12] = 'S';
	board[23] = 'S';
	board[7] = 'L';
	board[16] = 'L';
	board[21] = 'L';

}

void MyGame::processTurn(){
	// Condicionales para saber que turno es
	if (turnCount % 2 == 0) {
		currentPlayer = 0;
	}
	else {
		currentPlayer = 1;
	}
	// Se llama al dado  y se guarda el valor el una variable
	int value = dado.roll();
	// Se guarda la posicion anterior
	int lastPosition = playerPositions[currentPlayer];
	//Se mueve al jugador
	playerPositions[currentPlayer] = playerPositions[currentPlayer] + value;
	// Condicional para saber si el jugador ganó
	if (playerPositions[currentPlayer] >= 30) {
		playerPositions[currentPlayer] = 30;
		// Se cambia el estatus del juego paara acabar el ciclo
		gameStatus = false;
		// Se mandan los mensajes finales
		std::cout << turnCount << " " << currentPlayer + 1 << " " << lastPosition << " " << value << " " << "N " << playerPositions[currentPlayer] << std::endl;
		std::cout << "--GAME OVER--" << std::endl;
		std::cout << "Player #" << currentPlayer + 1 << " is the winner!!!" << std::endl;
	}
	if (board[playerPositions[currentPlayer]] == 'N') {
		// Se detecta el tipo de casilla del jugador y se mandan los mensajes
		playerPositions[currentPlayer] = playerPositions[currentPlayer];
		std::cout << turnCount << " " << currentPlayer + 1 << " " << lastPosition << " " << value << " " << "N " << playerPositions[currentPlayer] << std::endl;
	}
	else if (board[playerPositions[currentPlayer]] == 'S') {
		// Se detecta el tipo de casilla, se restan tres casilllas y se mandan los mensajes correspondientes
		playerPositions[currentPlayer] = playerPositions[currentPlayer] - 3; 
		std::cout << turnCount << " " << currentPlayer + 1 << " " << lastPosition << " " << value << " " << "S " << playerPositions[currentPlayer] << std::endl;
	}
	else if (board[playerPositions[currentPlayer]] == 'L') {
		// Se detecta el tipo de casilla, se suman tres casilllas y se mandan los mensajes correspondientes
		playerPositions[currentPlayer] = playerPositions[currentPlayer] + 3;
		std::cout << turnCount << " " << currentPlayer + 1 << " " << lastPosition << " " << value << " " << "L " << playerPositions[currentPlayer] << std::endl;
	}
	turnCount++; // Se registra el turno
	
}

// Instrucciones
void MyGame::printInstructions() {
	// Se imprimen las instrucciones iniciales
	std::cout << "Press C to continue next turn, or E to end the game: " << std::endl;
	std::cout << "The output you will recive is:"<<std::endl<<"Turn, Player #, Last Position, Dice Value, Initial of the tpye of box(N, S, L), New Position>"<<std::endl;
}

// Iniciar el juego
void MyGame::start() {
	printInstructions(); // Se imprimen las instrucciones una sola vez
	while (turnCount <= turnLimit && gameStatus == true) {
		char response;
		std::cin >> response;
		if (response == 'C') {
			processTurn();
		}
		else if (response == 'E') {
			gameStatus = false;
			std::cout << "--GAME OVER--" << std::endl;
			std::cout << "Thanks for playing!!!" << std::endl;
		}
		else {
			std::cout << "Invalid option, please press C to continue next turn or E to end the game" << std::endl;
		}
	}
	if (turnCount >= turnLimit) {
		gameStatus = false;
		std::cout << "--GAME OVER--" << std::endl;
		std::cout << "The maximum number of turns has been reached..." << std::endl;
	}
}