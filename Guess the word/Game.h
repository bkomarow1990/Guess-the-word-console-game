#pragma once
#include "QuestList.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;
class Game
{
	static const char filler = '#';
	QuestList list; // default ctor, заповнення питаннями вектору
	string question; // Запитання
	string userWord;  // шаблон слова, спочатку заповнити певним символом
	string answer; //правильне слово- відповідь
	void start(); //Не робив бо всі мої питання в .dat файлі
	const int getCountQuestionInDb()const;
	
public:
	Game();
	void run();
	void updateUserWord(char letter);
	friend class QuestList;

};
