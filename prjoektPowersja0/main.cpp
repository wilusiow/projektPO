
#include "stdafx.h"
#include<Windows.h>
#include<iostream>
#include<string>
#include"Board.h"
#include"Player.h"
#include"User.h"
#include"Bot.h"

using namespace std;

int main()
{
	while (true)
	{

		int menu;
		cout << "Witaj w grze gomoku!\nZasady sa proste uloz piec swoich symboli (pionowo, poziomo, na ukos oraz wspak)."<<endl;
		cout<< "Pamietaj bledny ruch oznacza utrate kolejki."<<endl;
		cout <<	"Aby rozpoczac gre wybierz tryb poprzez przycisk 1 lub 2, aby zakonczyc program wybierz 3: " << endl;
		cout << "(1) Gra z komputerem." << endl;
		cout << "(2) Gra z innym uzytkownikiem." << endl;
		cout << "(3) Wyjscie." << endl;
		cin >> menu;
		char again='c';


		switch (menu)
		{
		case 1:
		{
			int sizeB;
			cout << "W gomoku gra sie na planszy kwadratowej standardowo o wymiarach 15x15, jednak czasem powieksza sie ja nawet do 19x19." << endl;
			cout << "Przyjmujac, ze plansza ma wymiar nxn, podaj n w zakresie 5-19" << endl;
			cin >> sizeB;
			while ((sizeB < 5) || (sizeB > 19) )
			{
				system("cls");
				cout << "Przyjmujac, ze plansza ma wymiar nxn, podaj n w zakresie 5-19" << endl;
				cin >> sizeB;
				if ((sizeB >= 5) && (sizeB <= 19))
				{
					break;
				}
			}

			 


			Board* board = new Board(sizeB + 2);
			User* userO = new User('O', board);
			Bot* bot = new Bot('X', board);
			string move;
			cout << "\n";
			system("cls");
			board->makeBoard();
			while (true)
			{
				cout << "Ruch gracza 'O', podaj pole [w formacie 3 znakowym np. a01, b10] : \n";
				cin >> move;

				userO->makeMove(move);

				if (board->winOrTie('O'))
				{
					break;
				}
				bot->makeMove(move);

				if (board->winOrTie('X'))
				{
					break;
				}

			}
			delete board;
			delete bot;
			delete userO;
			Sleep(2000);
			system("cls");
			
			while (again != 't' || again != 'n')
			{
				cout << "Czy chcesz zagrac ponownie? t/n\n";
				cin >> again;
				system("cls");
				if (tolower(again) == 't') break;
				if (tolower(again) == 'n') exit(1);
			}
			break;
		}
		case 2:
		{
			int sizeB;
			cout << "W gomoku gra sie na planszy kwadratowej standardowo o wymiarach 15x15, jednak czasem powieksza sie ja do 19x19." << endl;
			cout << "Przyjmujac, ze plansza ma wymiar nxn, podaj n:" << endl;
			cin >> sizeB;
			while ((sizeB < 5) || (sizeB > 19))
			{
				system("cls");
				cout << "Przyjmujac, ze plansza ma wymiar nxn, podaj n w zakresie 5-19" << endl;
				cin >> sizeB;
				if ((sizeB >= 5) && (sizeB <= 19))
				{
					break;
				}
			}

			Board* board = new Board(sizeB + 2);
			User* userX = new User('X', board);
			User* userO = new User('O', board);

			string move;
			cout << "\n";
			system("cls");
			board->makeBoard();
			while (true)
			{
				cout << "Ruch gracza 'O', podaj pole [w formacie 3 znakowym np. a01, b10] : \n";
				cin >> move;
				userO->makeMove(move);

				if (board->winOrTie('O'))
				{
					break;
				}
				cout << "Ruch gracza 'X', podaj pole w [formacie 3 znakowym np. a01, b10] : \n";
				cin >> move;
				userX->makeMove(move);

				if (board->winOrTie('X'))
				{
					break;
				}
			}
			delete board;
			delete userX;
			delete userO;
			Sleep(2000);
			system("cls");

			while (again != 't' || again != 'n')
			{
				cout << "Czy chcesz zagrac ponownie? t/n\n";
				cin >> again;
				system("cls");
				if (tolower(again) == 't') break;
				if (tolower(again) == 'n') exit(1);
			}
			break;
		}
		case 3:
		{
			return 0;
			break;
		}
		default:
			cout << "Zle wybrales, wybierz ponownie." << endl;
			Sleep(2000);
			system("cls");
			break;
		}
	}
}