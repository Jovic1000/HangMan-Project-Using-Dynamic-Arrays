#include <iostream>
#include "Hangman.h"

int main()
{
	// show this too matt
	{
	/*	int size = 3;

			int* array = new int[size]
				{1, 2, 3};


			std::cout << "array with size of: " << size << std::endl;

			for (int i = 0; i < size; i++)
			{
				std::cout << array[i] << ", ";
			}

			std::cout << std::endl;

			size++;

			std::cout << "array with size of: " << size << std::endl;

			

			for (int i = 0; i < size; i++)
			{
				array[i] = (i + 1);
				std::cout << array[i] << ", ";
			}

			size = size * 2;
			
			std::cout << std::endl;

			std::cout << "array with size of: " << size << std::endl;

			for (int i = 0; i < size; i++)
			{
				array[i] = (i + 1);
				std::cout << array[i] << ", ";
			}*/



			
	}
	


	srand(time(NULL));
	
	Hangman hangman;

	hangman.StartGame();

	return 0;
}