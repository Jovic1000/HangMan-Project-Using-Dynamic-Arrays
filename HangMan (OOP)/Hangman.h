#pragma once
#include <iostream>


class Hangman
{
public:
	
	Hangman();

	void GenerateAnswer();


private:
	
	std::string m_answer;
	char* m_playerInput;
	char m_guessProgress;
	char m_hangManFull[GRID_SIZE][GRID_SIZE] =
	{
		'/', '-', '-', '-', '¬', '~', '~',
		'|', '~', '~', '~', '0', '~', '~',
		'|', '~', '~', '/', '|', '\\', '~',
		'|', '~', '/', '~', '|', '~', '\\',
		'|', '~', '~', '~', '|', '~', '~',
		'|', '~', '~', '~', 'X', '~', '~',
		'|', '_', '_', '/', '~', '\\', '~'
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

const int GRID_SIZE = 7;