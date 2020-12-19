#pragma once
#include "QuestList.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;
class Game
{
	static const char filler = '#';
	QuestList list; // default ctor, ���������� ��������� �������
	string question; // ���������
	string userWord;  // ������ �����, �������� ��������� ������ ��������
	string answer; //��������� �����- �������
	void start(); //�� ����� �� �� �� ������� � .dat ����
	const int getCountQuestionInDb()const;
	
public:
	Game();
	void run();
	void updateUserWord(char letter);
	friend class QuestList;

};
