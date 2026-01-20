#include "Hangman.h"
#include <fstream>
#include <string>

Hangman::Hangman() :  m_answer(""), m_guessProgress(), m_playerInput()
{

}

void Hangman::GenerateAnswer()
{
	int m_index;
	std::string m_answerList; 
	std::fstream answerFile("AnswerList.txt");

	while (getline(answerFile, m_answerList[]))
	{

	}
}
