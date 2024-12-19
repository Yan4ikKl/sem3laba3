#pragma once
#include "DynamicArray.h"
#include "Line.h"
#include <string>

class Page
{
private:
	DynamicArray<Line>* page;
public:
	Page()
	{
		this->page= new DynamicArray<Line>;
	}
	Page(DynamicArray<Line> words)
	{
		page = new DynamicArray<Line>;
		for (int i = 0; i < words.getSize(); i++)
		{
			page->append(words.get(i));
		}
	}
	void print() const
	{
		for (int i = 0; i < this->page->getSize(); i++)
		{
			this->page->get(i).print();
		}
	}
	void append(Line line)
	{
		this->page->append(line);
	}
};
