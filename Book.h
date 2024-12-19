#pragma once
#include "DynamicArray.h"
#include "Page.h"
#include <string>

class Book
{
private:
	DynamicArray<Page>* book;
public:
	Book()
	{
		this->book = new DynamicArray<Page>;
	}
	Book(DynamicArray<Page> words)
	{
		book = new DynamicArray<Page>;
		for (int i = 0; i < words.getSize(); i++)
		{
			book->append(words.get(i));
		}
	}
	void print()
	{
		for (int i = 0; i < this->book->getSize(); i++)
		{
			std::cout << "Page " << i + 1 << ":\n";
			this->book->get(i).print();
			std::cout << "\n\n\n";
		}
	}
	void append(Page page)
	{
		this->book->append(page);
	}
};
