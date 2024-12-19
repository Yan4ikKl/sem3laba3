#pragma once

#include "SortedSequence.h"

template<class T> class Dictionary
{
private:
	SortedSequence<Key_Value>* dict;
public:
	Dictionary()
	{
		this->dict = new SortedSequence<Key_Value>;
	}
	size_t getCount()
	{
		return dict->getLength();
	}
	const Key_Value get(int index) const
	{
		return this->dict->get(index);
	}
	int getValue(std::string key)
	{
		return this->dict->getValueOfKey(key);
	}
	bool containsKey(std::string key)
	{
		return this->dict->isInSequence(key);
	}
	void add(const std::string key, const int& value)
	{
		this->dict->add(key, value);
	}
	void remove(std::string key)
	{
		this->dict->remove(key);
	}
	void changeValue(std::string& key, int newValue)
	{
		this->dict->changeValue(key, newValue);
	}
	int getValueOfKey(std::string key)
	{
		return this->dict->getValueOfKey(key);
	}
	std::string getKeyOfValue(int value)
	{
		return this->dict->getKeyOfValue(value);
	}
};
