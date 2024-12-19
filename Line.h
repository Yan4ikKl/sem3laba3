#pragma once
#include "DynamicArray.h"
#include <string>
#include <iostream>

class Line
{
private:
	DynamicArray<std::string>* line;
public:
	Line()
	{
		this->line = new DynamicArray<std::string>;
	}
	Line(DynamicArray<std::string> words)
	{
		line = new DynamicArray<std::string>;
		for (int i = 0; i < words.getSize(); i++)
		{
			line->append(words.get(i));
		}
	}
	void print() const
	{
		for (int i = 0; i < this->line->getSize(); i++)
		{
			std::cout << this->line->get(i);
		}
		std::cout << "\n";
	}
	void append(std::string word)
	{
		this->line->append(word);
	}
};
