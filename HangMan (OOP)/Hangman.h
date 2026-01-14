#pragma once
#include <iostream>

const int GRID_SIZE = 7;

class Hangman
{
public:
	
	Hangman();

	void intro();
	void makeGuess();
	void Cheat();
	void GenerateAnswer();
	void buildHangMan();
	void StartGame();
	void CheckGuess();


private:
	
	bool m_isGameOver;
	bool m_validInput;

	int m_answerLength;
	int m_hangManProgress;
	
	std::string m_answer;
	std::string m_playerInput;
	std::string m_guessProgress;

	
	char m_hangManFull[GRID_SIZE][GRID_SIZE] =
	{
		'/', '-', '-', '-', '\\', '~', '~',
		'|', '~', '~', '~', '0', '~', '~',
		'|', '~', '~', '/', '|', '\\', '~',
		'|', '~', '~', '/', '~', '\\', '~',
		'|', '~', '~', '~', '~', '~', '~',
		'|', '~', '~', '~', '~', '~', '~',
		'|', '~', '~', '~', '~', '~', '~'
	};
	char m_hangManEmpty[GRID_SIZE][GRID_SIZE] =
	{
		'~', '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~',
		'~', '~', '~', '~', '~', '~', '~',
	};
	

};

