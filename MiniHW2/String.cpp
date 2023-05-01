#include "String.h"
#pragma warning(disable:4996)
char String::at(unsigned index) const
{
	return text[index];
}

char String::back() const
{
	return text[actualSize - 1];
}

char String::front() const
{
	return text[0];
}

char* String::str() const
{
	return text;
}

unsigned String::length() const
{
	return actualSize;
}

unsigned String::capacity() const
{
	return this->cap;
}

bool String::empty() const
{
	return this->text == nullptr || this->actualSize == 0;
}

String& String::append(const char* appText)
{
	String temp(this->text, this->actualSize + strlen(appText));
	for (size_t i = this->actualSize, j = 0; i < temp.actualSize; i++, j++)
	{
		temp.text[i] = appText[j];
	}
	*this = temp;
	return *this;
}

void String::clear()
{
	for (size_t i = 0; i < this->actualSize; i++)
	{
		this->text[i] = '\0';
	}
}

bool String::equals(const char* text) const
{
	return !strcmp(this->text, text);
}

bool String::equals(const String& other) const
{
	return equals(other.text);
}

int String::find(const char symb) const
{
	for (size_t i = 0; i < this->actualSize; i++)
	{
		if (this->text[i] == symb)
		{
			return i;
		}
	}
	return -1;
}

void String::shrinkToFit()
{
	resizeShrink();
	this->cap = this->actualSize;
}

void swapNums(unsigned& num1, unsigned& num2) {
	unsigned temp = num1;
	num1 = num2;
	num2 = temp;
}

void swapText(char* txt1, char* txt2) {
	char* temp = txt1;
	txt1 = txt2;
	txt2 = temp;
}

void String::swap(String& other)
{
	swapNums(this->actualSize, other.actualSize);
	swapNums(this->cap, other.cap);
	swapText(this->text, other.text);
}

unsigned String::find(const String& other) const
{
	if (this->actualSize < other.actualSize)
	{
		return -1;
	}
	for (size_t i = 0; i < this->actualSize; i++)
	{
		if (this->text[i] == other.text[0])
		{
			bool areEqual = true;
			for (size_t j = 1; j < other.actualSize; j++) {
				if (this->text[i + j] != other.text[j])
				{
					areEqual = false;
					break;
				}
			}
			if (areEqual)
			{
				return i;
			}
		}
	}
	return -1;
}

bool String::contains(const String& other) const
{
	return find(other) != -1;
}

bool String::contains(const char symbol) const
{
	return find(symbol) != -1;
}

String::String() : text(nullptr), cap(0), actualSize(0)
{}

String::String(const char* text)
{
	actualSize = strlen(text) + 1;
	cap = 2 * actualSize;
	this->text = new char[cap];
	strcpy(this->text, text);
}

String::String(const char* text, unsigned size)
{
	this->actualSize = size + 1;
	this->cap = 2 * this->actualSize;
	this->text = new char[this->cap];
	this->text[this->actualSize - 1] = '\0';
	for (size_t i = 0; i < this->actualSize - 1; i++)
	{
		this->text[i] = text[i];
	}

}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (&other != this)
	{
		free();
		copy(other);
	}
	return *this;
}

String::~String()
{
	free();
}

void String::resizeGrow()
{
	String temp(this->text, 2 * this->actualSize);
	*this = temp;
}

void String::resizeShrink()
{
	String temp(this->text, this->actualSize / 2);
	*this = temp;
}

void String::copy(const String& other)
{
	this->cap = other.cap;
	this->actualSize = other.actualSize;
	this->text = new char[this->cap];
	strcpy(this->text, other.text);
}

void String::free()
{
	delete[] this->text;
}