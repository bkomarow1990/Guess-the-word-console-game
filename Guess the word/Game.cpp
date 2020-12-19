#include "Game.h"
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
void Game::start()
{
	int rand_num= rand() % list.list.size();
	question = list.list[rand_num].getQuestion();
	answer = list.list[rand_num].getAnswer();
	userWord="";
	for (size_t i = 0; i < answer.size(); i++)
	{
		userWord += filler;
	}
	list.list.erase(list.list.begin()+rand_num);
}

const int Game::getCountQuestionInDb() const
{
	ifstream file("db.txt");
	int count=0;
	string line;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			++count;
		}
	}
	file.close();
	return count;
}

Game::Game()
{
	userWord=filler;
}

void Game::run()
{

	bool end = false;
	while (!end)
	{
		for (size_t i = 0; i < list.list.size(); i++)
		{
		
			start();
			while (userWord!= answer)
			{
				cout << "===========~~~~Guess the word~~~~===========" << endl;
			
			char temp_word;
			cout << "\t     " <<question << endl;
			cout << "\t        " <<userWord << endl;
			cout << "\t     Enter Word: ";
			cin >> temp_word;
			updateUserWord(temp_word);
			ClearScreen();
			}
		}
		cout << "\t  YOU GUESS ALL WORDS!!!" << endl;
		end = true;
	}
}

void Game::updateUserWord( char letter)
{
	size_t found = answer.find(letter);
	if (found != std::string::npos) {
		
		//cout << "Have" << endl;
		userWord[found] = letter;
		system("color 20");
		Sleep(1000);
		system("color 07");
		return;
	}
	letter -= 32;
	found = answer.find(letter);
	if (found != std::string::npos) {

		//cout << "Have" << endl;
		userWord[found] = letter;
		system("color 20");
		Sleep(1000);
		system("color 07");
		return;
	}
	system("color 47");
	Sleep(1000);
	system("color 07");

}

