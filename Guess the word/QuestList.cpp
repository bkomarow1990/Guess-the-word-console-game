#include "QuestList.h"
#include <fstream>
void QuestList::get_db()
{
	ifstream file("db.dat");

	if (file.is_open())
	{
		int i = 0;
		string current_question;
		string current_answer;
		string line;
		while(!file.eof()){
			i = 0;
			current_question = "";
			current_answer = "";
			getline(file, line);
			while (line[i] != '*' && line[i + 1] != '*') {
				current_question += line[i];
				i++;
			}
			i += 4;
			while (line[i]!='\0')
			{
				current_answer += line[i];
				i++;
			}
			list.push_back(Quest(current_question,current_answer));
			
		}
	}
	file.close();
}

QuestList::QuestList()
{
	get_db();
}

const Quest& QuestList::getQuest(const int& index) const
{
    return list[index];
}

const int QuestList::getSize() const
{
    return list.size();
}
