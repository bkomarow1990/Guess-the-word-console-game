#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Quest.h"
using namespace std;
class QuestList
{
private:
	vector <Quest> list;
	void get_db();
	friend class Game;
public:
	QuestList();
	const Quest& getQuest(const int& index)const;
	const int getSize()const;

};

