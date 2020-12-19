#include "Quest.h"

const string Quest::getAnswer() const
{
    return answer;
}

Quest::Quest(const string& question, const string& answer)
    :question(question), answer(answer)
{

}

const string& Quest::getQuestion() const
{
    return question;
}
