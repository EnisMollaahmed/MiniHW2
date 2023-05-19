#include "String.h"
#pragma warning(disable:4996)
char String::at(unsigned index) const
{
	return text[index];
}

char String::back() const
{
	return text[size - 1];
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
	return size;
}

unsigned String::capacity() const
{
	return this->capacitance;
}

bool String::empty() const
{
	return this->text == nullptr || this->size == 0;
}

String& String::append(const char* appText)
{
	unsigned addSize = strlen(appText);
	if (addSize + this->size >= this->capacitance * 2 + 1)
	{
		resize();
	}
	strcat(this->text, appText);
	this->size += addSize;
	return *this;
}

void String::clear()
{
	for (size_t i = 0; i < this->size; i++)
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
	for (size_t i = 0; i < this->size; i++)
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
	this->capacitance = this->size - 1;
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
	swapNums(this->size, other.size);
	swapNums(this->capacitance, other.capacitance);
	swapText(this->text, other.text);
}

unsigned String::find(const String& other) const
{
	if (this->size < other.size)
	{
		return -1;
	}
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->text[i] == other.text[0])
		{
			bool areEqual = true;
			for (size_t j = 1; j < other.size; j++) {
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

String::String() : text(nullptr), capacitance(0), size(0)
{}

String::String(const char* text)
{
	size = strlen(text);
	capacitance = 2 * size + 1;
	this->text = new char[capacitance];
	strcpy(this->text, text);
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

void String::resize()
{
	this->capacitance *= 2;
	char* temp = new char[capacitance];
	strcpy(temp, this->text);
	free();
	this->text = temp;
}

void String::copy(const String& other)
{
	this->capacitance = other.capacitance;
	this->size = other.size;
	this->text = new char[this->capacitance];
	strcpy(this->text, other.text);
}

void String::free()
{
	delete[] this->text;
}