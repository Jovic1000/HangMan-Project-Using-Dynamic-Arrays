#pragma once
class Hangman
{
public:

private:
	char m_answer;
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
	char m_hangManEmpty[GRID_SIZE][GRID_SIZE];
};

const int GRID_SIZE = 7;