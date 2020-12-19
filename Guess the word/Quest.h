#pragma once
#include <iostream>
#include <string>
using namespace std;
class Quest
{
private:
	string question;
	string answer;
	const string getAnswer()const;
	friend class QuestList;
	friend class Game;
public:
	friend class Questlist;
	Quest(const string& question, const string& answer);
	const string& getQuestion() const;
};

