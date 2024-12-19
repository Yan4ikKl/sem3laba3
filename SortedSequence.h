#pragma once
#include "DynamicArray.h"

#include <string>
#include <stdexcept>


struct Key_Value
{
	std::string key;
	int value;
	Key_Value& operator =(const Key_Value& other)
	{
		if (this != &other)
		{
			this->key = other.key;
			this->value = other.value;
		}
		return *this;
	}
	const std::string getKey() const
	{
		return key;
	}
	const int getValue() const
	{
		return value;
	}
	void setKey(std::string newKey)
	{
		this->key = newKey;
	}
	void setValue(int newValue)
	{
		this->value = newValue;
	}
};

template <typename T> class SortedSequence
{
private:
	DynamicArray<Key_Value>* sequence;
public:
	SortedSequence() 
	{
		this->sequence = new DynamicArray<Key_Value>;
	}
	size_t getLength()
	{
		return sequence->getSize();
	}
	bool getIsEmpty()
	{
		if (sequence->getSize() == 0) return true;
		return false;
	}
	const Key_Value get(int index) const
	{
		if (index < 0 || index >= sequence->getSize())
			throw std::out_of_range("Index is out of range\n");
		return sequence->get(index);
	}
	const T getFirst() const
	{
		return sequence->get(0);
	}
	const T getLast() const
	{
		return sequence->get(sequence->getSize() - 1);
	}
	int indexOfKey(std::string key)
	{
		int index = -100;
		for (int i = 0; i < sequence->getSize(); i++)
		{
			if ((sequence->get(i)).getKey() == key)
			{
				index = i;
				break;
			}
		}
		if (index != -100) return index;
		return -1;
	}
	int indexOfValue(int value)
	{
		int index = -100;
		for (int i = 0; i < sequence->getSize(); i++)
		{
			if ((sequence->get(i)).getValue() == value)
			{
				index = i;
				break;
			}
		}
		if (index != -100) return index;
		return -1;
	}
	SortedSequence<Key_Value> getSubsequence(int startIndex, int endIndex)
	{
		SortedSequence<Key_Value> newSequence;
		for (int i = startIndex; i <= endIndex; i++)
		{
			newSequence.add(this->get(i).getKey(), this->get(i).getValue());
		}
		return newSequence;
	}
	void add(const std::string& key, const int& value)
	{
		Key_Value newElement{};
		newElement.key = key;
		newElement.value = value;
		int index = this->getLength();
		for (int i = 0; i < this->getLength(); i++)
		{
			if (key[0] < (this->get(i).key)[0])
			{
				index = i;
				break;
			}
			if (key[0] == (this->get(i).key)[0])
			{
				int minimum = 0;
				if (this->get(i).key.length() > key.length())
				{
					minimum = key.length();
				}
				else 
				{
					minimum = this->get(i).key.length();
				}
				for (int j = 1; j < minimum; j++)
				{
					if (key[j] < (this->get(i).key)[j])
					{
						index = i;
						break;
					}
				}
			}
		}
		sequence->resize(this->getLength() + 1);
		for (int i = this->getLength() - 1; i > index; i--)
		{
			sequence->set(i, this->get(i - 1));
		}
		sequence->set(index, newElement);
	}
	DynamicArray<std::string> getKeys()
	{
		DynamicArray<std::string> result;
		for (int i = 0; i < sequence->getSize(); i++)
		{
			result.append(sequence->get(i).key);
		}
		return result;
	}
	DynamicArray<int> getValues()
	{
		DynamicArray<int> result;
		for (int i = 0; i < sequence->getSize(); i++)
		{
			result.append(sequence->get(i).value);
		}
		return result;
	}
	

	bool isInSequence(std::string key)
	{
		bool flag = false;
		for (int i = 0; i < this->getLength(); i++)
		{
			if (this->get(i).getKey() == key)
			{
				flag = true;
			}
		}
		return flag;
	}
	void remove(const std::string& key)
	{
		int index = indexOfKey(key);
		if (index == -1)
			throw std::out_of_range("Key not found in the sequence\n");
		for (int i = index; i < sequence->getSize() - 1; i++)
		{
			sequence->set(i, sequence->get(i + 1));
		
		}
		sequence->resize(sequence->getSize() - 1);
	}
	int getValueOfKey(std::string key)
	{
		int result{};
		if (this->isInSequence(key) == false)
			throw std::out_of_range("Key not found in the sequence\n");
		for (int i = 0; i < this->getLength(); i++)
		{
			if (this->get(i).getKey() == key)
			{
				result = this->get(i).getValue();
			}
		}
		return result;
	}
	std::string getKeyOfValue(int value)
	{
		std::string result{};
		for (int i = 0; i < this->getLength(); i++)
		{
			if (this->get(i).getValue() == value)
			{
				result = this->get(i).getKey();
			}
		}
		return result;
	}
	void changeValue(std::string& key, int newValue)
	{
		int index = indexOfKey(key);
		if (index != -1)
		{
			Key_Value& element = sequence->get(index);
			element.setValue(newValue);
		}
		else
		{
			throw std::out_of_range("Key not found in the sequence\n");
		}
	}
};

