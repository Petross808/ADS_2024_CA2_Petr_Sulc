#include "ApplicationPart2.h"
#include "fstream"
#include <string>

void ApplicationPart2::LoadFile(const string& filePath)
{
    ifstream in(filePath);
    string fileString;
    while (!in.eof())
    {
        string line;
        getline(in, line);
        fileString += ' ' + line;
    }
    in.close();
    ParseText(fileString);
}

void ApplicationPart2::ParseText(const string& text)
{
    int currentWordStart = 0;
    string word;
    char curr;
    for (int i = 0; i < text.size(); i++)
    {
        curr = text.at(i);
        if ((curr >= 'A' && curr <= 'z') || curr == '\'')
        {
            continue;
        }

        if (i == currentWordStart)
        {
            currentWordStart++;
            continue;
        }

        word = text.substr(currentWordStart, i - currentWordStart);
        currentWordStart = i + 1;
        AddWordToMap(word);
    }

    if (text.size() != currentWordStart)
    {
        word = text.substr(currentWordStart, text.size());
        AddWordToMap(word);
    }
}

void ApplicationPart2::AddWordToMap(const string& word)
{
    map.put(tolower(word[0]), word);
}

void ApplicationPart2::PrintKeys()
{
    auto keySet = map.keySet();
    keySet.printInOrder(cout);
}

void ApplicationPart2::PrintValues(const char& key)
{
    auto valueList = map.get(key);
    auto currentValue = valueList.first();
    for (int i = 0; i < valueList.getSize(); i++)
    {
        cout << currentValue->value << endl;
        currentValue = currentValue->next;
    }

}
