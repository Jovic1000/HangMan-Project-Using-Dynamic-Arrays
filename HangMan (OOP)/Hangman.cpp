#include "Hangman.h"
#include <fstream>
#include <string>

Hangman::Hangman() : m_answerLength(0), m_answer(""), m_guessProgress(""), m_playerInput(""), m_hangManProgress(0), m_isGameOver(false), m_validInput(false)
{

}

void Hangman::intro()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "----WELCOM_TO_HANGMAN!----" << std::endl;
	std::cout << "---------RUELS:-----------" << std::endl;
	std::cout << "- You Can Only Input One Letter At A Time!" << std::endl;
	std::cout << "- There Are 5 Parts To The Hangman" << std::endl;
	std::cout << "- If You Try To Input More Then One Or Guess Wrong, You Get More Progress On The Hangman!" << std::endl;
	std::cout << "- The Game Is Over When You Get All The Pieces Of Your Hang Man On The Grid!" << std::endl;
	std::cout << "- You Win The Game If You Get All The Letter Correct!" << std::endl;
	std::cout << "- HAVE FUN!" << std::endl;
	std::cout << "--------------------------" << std::endl;
	
}

void Hangman::makeGuess()
{
	// variables
	std::string playerInput;
	

	
	std::cout << "--------------------------" << std::endl;
	std::cout << "!Please Input Your Guess!" << std::endl;
	std::cout << "--------------------------" << std::endl;
	
	std::cin >> playerInput;


	int length = playerInput.length();

	if (length == 1)
	{
		
		m_validInput = true;
		m_playerInput = tolower(playerInput[0]);
	}

	else if (playerInput == "cheat" || playerInput == "CHEAT" || playerInput == "Cheat")
	{
		Cheat();
	}

	else
	{

		std::cout << "--------------------------" << std::endl;
		std::cout << "!This Is Not A Valid Input!" << std::endl;
		std::cout << "--------------------------" << std::endl;

		m_hangManProgress++;
	}
	
	
	


}




void Hangman::Cheat()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Answer:" << m_answer << std::endl;
	std::cout << "--------------------------" << std::endl;
}




void Hangman::GenerateAnswer()
{
	// Variables
	int size = 0;
	int answerLength;
	std::string copyText;
	int pickAnswer;

	// Pointer Variables
	std::string* answerList = nullptr;

	


	// opens answerFile and increases size to the size of the in answer file
	{
		//scope file
		std::fstream answerFile("AnswerList.txt");

		while (getline(answerFile, copyText))
		{
			size++;
		}
	}
	

	answerList = new std::string[size];

	 
	//Re-opens answerFile copys a line from answerFile and sets it to answerList
	{
		// scope variable
		int index = 0;

		//scope file
		std::fstream answerFile("AnswerList.txt");


		while (getline(answerFile, copyText))
		{
			if (index < size)
			{
				answerList[index] = copyText;
				index++;
			}
		}
	}



	// TEST outputs the contents of answerlist to console
	/*for (int i = 0; i < size; i++)
	{
		std::cout << answerList[i] << std::endl;
	}*/
	

	pickAnswer = rand() % size;
	m_answer = answerList[pickAnswer];

	answerLength = m_answer.length();
	m_answerLength = answerLength;

	for (int i = 0; i < answerLength; i++)
	{
		m_guessProgress = m_guessProgress + "_ ";
	}

	delete[] answerList;
	
}




void Hangman::buildHangMan()
{
	char grid[GRID_SIZE][GRID_SIZE];

	//progress 0
	if (m_hangManProgress == 0)
	{
		std::cout << "------HANGMAN------" << std::endl;
		for (int i = 0; i < GRID_SIZE; i++)
		{
			for (int j = 0; j < GRID_SIZE; j++)
			{
				grid[i][j] = m_hangManEmpty[i][j];
			}
		}
	}

	//progress 1
	else if (m_hangManProgress == 1)
	{
		std::cout << "------HANGMAN------" << std::endl;

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[i][0] = m_hangManFull[i][0];
		}


		for (int i = 0; i < GRID_SIZE; i++)
		{
			for (int j = 1; j < GRID_SIZE; j++)
			{
				grid[i][j] = m_hangManEmpty[i][j];
			}
		}
	}

	//progress 2
	else if (m_hangManProgress == 2)
	{
		std::cout << "------HANGMAN------" << std::endl;

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[i][0] = m_hangManFull[i][0];
		}

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[0][i] = m_hangManFull[0][i];
		}



		for (int i = 1; i < GRID_SIZE; i++)
		{
			for (int j = 1; j < GRID_SIZE; j++)
			{
				grid[i][j] = m_hangManEmpty[i][j];
			}
		}
	}

	//progress 3
	else if (m_hangManProgress == 3)
	{
		std::cout << "------HANGMAN------" << std::endl;

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[i][0] = m_hangManFull[i][0];
		}

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[0][i] = m_hangManFull[0][i];
		}

		for (int i = 1; i < GRID_SIZE; i++)
		{
			for (int j = 1; j < GRID_SIZE; j++)
			{
				grid[i][j] = m_hangManEmpty[i][j];
			}
		}
		
		grid[1][4] = m_hangManFull[1][4];
	}

	//progress 4
	else if (m_hangManProgress == 4)
	{
		std::cout << "------HANGMAN------" << std::endl;

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[i][0] = m_hangManFull[i][0];
		}

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[0][i] = m_hangManFull[0][i];
		}

		for (int i = 1; i < GRID_SIZE; i++)
		{
			for (int j = 1; j < GRID_SIZE; j++)
			{
				grid[i][j] = m_hangManEmpty[i][j];
			}
		}

		grid[1][4] = m_hangManFull[1][4];

		grid[2][3] = m_hangManFull[2][3];
		grid[2][4] = m_hangManFull[2][4];
		grid[2][5] = m_hangManFull[2][5];
	}

	//progress 5
	else if (m_hangManProgress == 5)
	{
		std::cout << "------HANGMAN------" << std::endl;

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[i][0] = m_hangManFull[i][0];
		}

		for (int i = 0; i < GRID_SIZE; i++)
		{
			grid[0][i] = m_hangManFull[0][i];
		}

		for (int i = 1; i < GRID_SIZE; i++)
		{
			for (int j = 1; j < GRID_SIZE; j++)
			{
				grid[i][j] = m_hangManEmpty[i][j];
			}
		}

		// head
		grid[1][4] = m_hangManFull[1][4];

		// body
		grid[2][3] = m_hangManFull[2][3];
		grid[2][4] = m_hangManFull[2][4];
		grid[2][5] = m_hangManFull[2][5];

		//legs
		grid[3][3] = m_hangManFull[3][3];
		grid[3][5] = m_hangManFull[3][5];

	}

	//ERROR Build
	else
	{
		std::cout << "!!!!BUILD_ERROR!!!!" << std::endl;
	}
	

	
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << "---GUESS_PROGRESS---" << std::endl;
	
	std::cout << m_guessProgress << std::endl;

	std::cout << "--------------------" << std::endl;
}

void Hangman::StartGame()
{
	intro();
	GenerateAnswer();

	while (!m_isGameOver)
	{
		buildHangMan();
		makeGuess();
		CheckGuess();

		int check = 0;

		for (int i = 0; i < m_answerLength; i++)
		{
			for (int j = 0; j < m_answerLength; j++)
			{
				if (m_guessProgress[i + i] == m_answer[j])
				{
					check++;
				}
			}
		}

		if (check == m_answerLength)
		{
			system("cls");
			buildHangMan();
			m_isGameOver = true;
			std::cout << "//////////////////////////" << std::endl;
			std::cout << "----------YOU_WIN---------" << std::endl;
			std::cout << "//////////////////////////" << std::endl;
		}

		if (m_hangManProgress == 5)
		{
			system("cls");
			buildHangMan();
			m_isGameOver = true;
			std::cout << "//////////////////////////" << std::endl;
			std::cout << "---------GAME_OVER--------" << std::endl;
			std::cout << "//////////////////////////" << std::endl;
		}

		system("pause");
		system("cls");
	}
}

void Hangman::CheckGuess()
{
	int check = 0;
	
	
	for (int i = 0; i < m_answerLength; i++)
	{
		if (m_playerInput[0] == m_answer[i])
		{
			m_guessProgress[i + i] = m_answer[i];
			check++;
		}
	}

	if (check == 0 && m_validInput)
	{
		m_hangManProgress++;
	}
}
