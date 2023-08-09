#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include "constants.h"

#include <Windows.h>

void printstuff();
void errorhandlerothercode();
void errorhandler();

int main(){
	int start{};
start:

	std::random_device rd{}; // random device
	std::seed_seq seedrng{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd() }; // 11 instances of seeded rng
	std::mt19937 rng{ seedrng };

	std::uniform_int_distribution d_21game(1, 12);
	
	std::string p1name;
	std::cout << "Hello! Lets play a game of 21! \n";
	std::cout << "Player 1! Enter your name!:";
	std::getline(std::cin >> std::ws, p1name); // take player 1 name
	std::cout << "\n";

	errorhandler();


	std::string p2name;
	std::cout << "Awesome! Now Player 2 Enter your name!:";
	std::getline(std::cin >> std::ws, p2name); // take player 2 name

	errorhandler();

	std::cout << "Awesome! Player 1 Your name is: " << p1name << " And Player 2, your name is: " << p2name << "!\n\n";

	std::cout << "\n\nNow lets get the real game started shal we?\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "CLEARING CONSOLE! PLEASE WAIT!\n";
	std::cout << "-------------------------------------------\n";

	Sleep(2500); 
	system("cls"); // clear console

	std::cout << "Would you like to read the rules of the game? Y/N";


	char YorN{};
	while (!YorN)
	{
		std::cin >> YorN;
		switch (YorN)
		{
		case 'Y':
			std::cout << "The rules of 21 are very simple!\n";
			std::cout << "Hitting:If you choose to hit you will recieve a card 1-12!\n";
			std::cout << "Standing:If you choose to stand, You will be locked into your current total (Added up through the card numbers!)\n";
			std::cout << "How the game works:First player to reach the number 21 wins! Be careful though! If you go over 21 you automatically lose! (bust)\n ";
			Sleep(750); // give user time to read.

			return 1;

		case 'y':
			std::cout << "The rules of 21 are very simple!\n";
			std::cout << "Hitting:If you choose to hit you will recieve a card 1-12!\n";
			std::cout << "Standing:If you choose to stand, You will be locked into your current total (Added up through the card numbers!)\n";
			std::cout << "How the game works:First player to reach the number 21 wins! Be careful though! If you go over 21 you automatically lose!\n";
			Sleep(750); // give user time to read.
			break;

		case 'N':
			std::cout << "Cool! Starting the game now then!\n";
			break;

		case 'n':
			std::cout << "Cool! Starting the game now then!\n";
			break;
		default:
			std::cout << "Error. That is not a valid entry...\n";
			std::cout << "-------------------------------------------------------------------\n";
			errorhandler();
		}
	}
	std::cout << "---------------------------------------------------\nGet ready! The game will start in 5 seconds!\n";

	std::cout << "5\n";
	Sleep(1000);
	std::cout << "4\n";
	Sleep(1000);
	std::cout << "3\n";
	Sleep(1000);
	std::cout << "2\n";
	Sleep(1000);
	std::cout << "1\n";
	Sleep(1000);
	std::cout << "PLAY!" << std::endl;// endl to flush
	Sleep(500);
	system("cls");

	bool player1_stand{ false };
	bool player2_stand{ false };
	int card_ammount_checker{ 21 };
	int roundcounter{ 0 };
	int player1_cards{ 0 };
	int player2_cards{ 0 }; // assigns add cards to rng
	int lockcard1{};
	int lockcard2{};

	while (player1_cards != card_ammount_checker || player2_cards != card_ammount_checker) // keeps loop running while cards are below 21
	{
		
		// checks if player stands, if player did stand then player with more cards wins unless they go over 21
		if (player1_stand == true && player2_cards > player1_cards && player2_cards < 21)
		{
			std::cout << p2name << " WINS! with " << player2_cards << std::endl;
			std::cout << p1name << " LOSES! with" << player1_cards << std::endl;
			goto playagain;
		}
		if (player2_stand == true && player1_cards > player2_cards && player1_cards < 21)
		{
			std::cout << p1name << " WINS! with " << player1_cards << std::endl;
			std::cout << p2name << " LOSES! with " << player2_cards << std::endl;
			goto playagain;
		}







		// actual game start
		int rngcard{ d_21game(rng) };
		int rngcard2{ d_21game(rng) };
		short choice{};
		if (!player1_stand)
		{

			printstuff();
			std::cout << p1name << " Enter your choice!: ";
			std::cin >> choice;
			switch (choice) // switch start
			{
			case 1:
				std::cout << "\n You've chosen to take a hit!\n";
				player1_cards += rngcard; // googled how to do this, RNG card is in the loop to constantly give it a random value, += to add a variable to existing
				if (player1_cards == 21)
				{
					std::cout << p1name << " Wins! By hitting " << player1_cards << std::endl;;
					goto playagain; // see end of code
					break;
				}
				else if (player1_cards > 21)
				{
					std::cout << p1name << " LOSES! with a card count of:" << player1_cards << std::endl;
					goto playagain;// see end of code
					break;
				}
				else
				{
					std::cout << player1_cards << std::endl;
					break;
				
				} 

			case 2:
				std::cout << "\n You've chosen to stand!\n";
				player1_stand == true;
				break;
			default:
				std::cout << "Invalid selection, Please select a valid variable.\n";
				errorhandler();
			}// switch end

		}

		if (!player2_stand) // if player 2 hasnt chose to stand code will run
		{
			std::cout << "Ok! Now " << p2name << " You're turn!\n";
			printstuff();
			short choice2{};
			std::cin >> choice2;
			switch (choice2)
			{
			case 1:
				std::cout << "\nYou've chosen to take a hit!\n";
				player2_cards += rngcard2; // googled how to do this, RNG card is in the loop to constantly give it a random value, += to add a variable to existing
				if (player2_cards == 21)
				{
					std::cout << p2name << " Wins! by hitting " << player2_cards << '!' << std::endl;
					goto playagain;// see end of code
					break;
				}
				else if (player2_cards > 21)
				{
					std::cout << p2name << " LOSES! with a card count of:" << player2_cards << std::endl;
					goto playagain;// see end of code
					break;

				}
				else
				{
					std::cout << player2_cards << std::endl;
					break;
				}
			case 2:
				std::cout << "\nYou've chosen to stand!\n";
				player2_stand = true;
				break;
			default:
				std::cout << "Invalid selection, Please select a valid variable.\n";
				errorhandler();
			}// switch player 2 end
		}

		// game end



		++roundcounter;

	}
	
	int playagain;
	playagain:


	std::cout << "\n\n\n---------------------------------------------------\n";
	std::cout << "This game lasted " << roundcounter << " rounds!\n-------------------------------------------\n";

	char Restart_YorN{};
	std::cout << "Do you want to play again?\n Y/N: ";
	std::cin >> Restart_YorN;
	switch (Restart_YorN)
	{
	case 'Y':
		std::cout << "Restarting the game in 1 second.";
		Sleep(750); // give user time to read.
		goto start; // restarts program
		break;

	case 'y':
		std::cout << "Restarting the game in 1 second.";
		Sleep(750); // give user time to read.
		goto start; // restarts program
		break;

	case 'N':
		std::cout << "Maybe next time then!";
		Sleep(500);
		break;

	case 'n':
		std::cout << "Maybe next time then!";
		Sleep(500);
		break;
	default:
		std::cout << "Invalid selection, Please select a valid variable.\n";
		errorhandler();
		goto playagain;
	}



	return 0;

}
