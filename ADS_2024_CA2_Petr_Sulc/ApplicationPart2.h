#pragma once
#include "TreeMap.h"

class ApplicationPart2
{
private:
	TreeMap<char, string> map;

	void ParseText(const string& text);
	void AddWordToMap(const string& word);

public:
	void LoadFile(const string& filePath);
	void PrintKeys();
	void PrintValues(const char& key);
};

