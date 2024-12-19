#include "AlphabeticalIndex.h"
#include "TestAlphabeticalIndex.h"

#include <cassert>
#include <string>
#include <fstream>

void TestAlphabeticalIndex::allTests()
{
	test1();
	test2();
}
void TestAlphabeticalIndex::test1()
{
	std::string text = "This is an exmple of text which will be distributed by lines and pages. Function will distribute text into words and located them by certain properties";

	int numberOfSymbolsInTheLine = 30;
	int numberOfLinesInThePage = 5;  

	Book book = alphabeticalIndex(text, numberOfSymbolsInTheLine, numberOfLinesInThePage);
	//book.print();
}
void TestAlphabeticalIndex::test2()
{
	std::ifstream inputFile("example.txt");
	std::string content;
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			content += line + "\n";
		}
		inputFile.close();
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}
	int sizeOfLine = 50;
	int numberOfLines = 10;
	Book book = alphabeticalIndex(content, sizeOfLine, numberOfLines);
	//book.print();
}

