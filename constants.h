#pragma once
#include <iostream>
#include <limits>
void printstuff()
{

	std::cout << "(1.) Hit - Recieve card 1-12" << std::endl;
	std::cout << "(2.) Stand - Keep current card ammount, Can't play further." << std::endl;
	std::cout << "-----------------------------------------------------------\n";

}

void errorhandlerothercode()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void errorhandler()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			exit(0);
		}

		std::cin.clear();
		errorhandler();
	}
}
