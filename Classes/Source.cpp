#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>


using namespace std;


#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLD "\033[1m"

#define RESET "\033[0m"
#define total 4


				  //------------------------
				  // Displaying Shop
				  //------------------------
#define draw 	cout << BOLD << YELLOW << " ID "<< BLUE <<"|"<< WHITE <<"  Stock  "<< BLUE <<"|"<< WHITE <<"   Item   "<< BLUE <<"|"<< GREEN <<"  Price  "<< BLUE <<"|"<< RED <<"  Sell  "<< BLUE <<"|"<< WHITE <<" Bal: $" << player.gold << BLUE << " |" WHITE <<" Round: " << score << "\n";	cout << PURPLE <<"___________________________________________" << endl;	for (int i = 0; i < total - 1; i++)	{		cout << " " << YELLOW << i << BLUE << "  |	" << WHITE << shop.quantity[i] << "	 " << WHITE << shop.item[i] <<  GREEN << "	    $" << shop.price[i] << RED << "	      $" << shop.sellPrice[i] << "\n"; 	cout << PURPLE <<"___________________________________________" << endl;}	cout << " " << YELLOW << total - 1 << BLUE << "  |	" << WHITE << shop.quantity[total - 1] << "	 " << WHITE << shop.item[total - 1] << GREEN << "	    $" << shop.price[total - 1] << RED << "     $" << shop.sellPrice[total - 1] << "\n"; 	cout << PURPLE << "___________________________________________" << RESET << endl;
				 
				  //------------------------
				  // Learing screen and displaying shop
				  //------------------------
#define clear system("cls"); draw 


class merchant
{
public:
	int gold;

	class shop 
	{
	public:
	string item[total];
	int price[total];
	int quantity[total];
	int sellPrice[total];
	};
};


				  //------------------------
				  // Assigning names to items
				  //------------------------

string items(int num)
{
	switch (num)
	{
	case 0:
		return "Sword";
		break;
	case 1:
		return "Shield";
		break;
	case 2:
		return "Bow";
		break;
	case 3:
		return "Win";
		break;
	default:
		return "Invaild Item";
		break;
		
	}
}


				 //------------------------
				 // Assigning prices to items
				 //------------------------	

int prices(int num, int price)
{
	switch (num)
	{
	case 0:						 // Sword
		price = rand() % 20;
		return price;
		break;
	case 1:						 // Shield
		price = rand() % 20;
		return price;
		break;
	case 2:						 // Bow
		price = rand() % 20;
		return price;
		break;
	case 3:
		price = 1000;
		return price;
		break;
	default:
		return 404;
		break;

	}
}

int sell(int num, int price)
{
	switch (num)
	{
	case 0:						 // Sword
		price = rand() % 25;
		return price;
		break;
	case 1:						 // Shield
		price = rand() % 25;
		return price;
		break;
	case 2:						 // Bow
		price = rand() % 25;
		return price;
		break;
	case 3:
		price = NULL;
		return price;
		break;
	default:
		return 404;
		break;

	}
}



int main()
{			
	srand(time(NULL));
															// Declaring Varibles
	merchant player;
	merchant::shop shop;
	string current;
	int price;
	player.gold = 1000;
	int buffer[3];
	int input;
	bool play = true;
	int score = 0;

				 //------------------------
				 // Assigning values to items
				 //------------------------	

															// Item Names
	for (int i = 0; i < total; i++)
	{
		current = items(i);
		shop.item[i] = current;
	}												   
															// Item Prices
	for (int i = 0; i < total; i++)							
	{														
		price = prices(i, 10);								
		shop.price[i] = price;								
	}														
 														    // Item Sell Price
	for (int i = 0; i < total; i++)							
	{														
		price = sell(i, 10);								
		shop.sellPrice[i] = price;								
	}														
															// Item Amount
	for (int i = 0; i < total; i++)
	{
		shop.quantity[i] = 1;
	}
	shop.quantity[3] = NULL;

	do{
		clear




			//------------------------
			// MENU
			//------------------------

		cout << BOLD << BLUE << "\n" << "What would you like to do? \n";
		cout << WHITE << "1." << GREEN << " Buy \n";
		cout << WHITE << "2." << RED << " Sell \n";
		cout << WHITE << "3." << PURPLE << " Exit \n";

		cout << WHITE << "Input: " << YELLOW;
		cin >> input;

		clear





			//------------------------
			// BUYING
			//------------------------

			// buffer[0] == ID		
			// buffer[1] == Amount
			// buffer[2] == Price

		if (input == 1)
		{
			
			do													// Getting ID from player
			{
				cout << BOLD << GREEN <<"\nEnter ID of Item You would like to buy: " << YELLOW;
				cin >> buffer[0];
				buffer[2] = prices(buffer[0], NULL);
				clear
			} while (buffer[0] >= total || player.gold < buffer[2]);


			do													//Getting Amount from player
			{
				cout << BOLD << GREEN << "\nHow many: " << YELLOW;
				cin >> buffer[1];
				buffer[2] = (buffer[1] * shop.price[buffer[0]]);
				clear
			} while (buffer[1] <= 0 || player.gold < buffer[2] );

				player.gold -= buffer[2];
				shop.quantity[buffer[0]] += buffer[1];

				shop.sellPrice[buffer[0]] = rand() % 25 + score;
				shop.price[buffer[0]] = rand() % 20 + score;

		}

															// Selling items
		if (input == 2)
		{
			//------------------------
			// SELLING
			//------------------------		

			// buffer[0] == ID											  
			// buffer[1] == Amount


			do													// Getting ID from player
			{
				cout << BOLD << RED << "\nEnter ID of Item You would like to sell: " << YELLOW;
				cin >> buffer[0];
				clear
			} while (shop.quantity[buffer[0]] == 0 || buffer[0] < 0 || buffer[0] >= total);


			do													//Getting Amount from player
			{
				cout << BOLD << RED << "\nHow many: " << YELLOW;
				cin >> buffer[1];
				clear
			} while (buffer[1] <= 0 || buffer[1] > shop.quantity[buffer[0]]);
			
			player.gold += buffer[1] * shop.sellPrice[buffer[0]];
			shop.quantity[buffer[0]] -= buffer[1];

			shop.sellPrice[buffer[0]] = rand() % 25 + score;
			shop.price[buffer[0]] = rand() % 20 + score;

		}

		if (input == 3)
		{
			return 0;

		}


		if (shop.quantity[3])
		{
			system("cls");
			cout << GREEN << "YOU WON! \n";
			system("pause");
			return 0;
		}
		score++;
	} while (play);											// Game Loop
	
	return 0;
}