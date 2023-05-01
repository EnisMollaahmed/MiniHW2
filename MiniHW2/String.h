#pragma once
#include <iostream>
class String
{
public:
	char at(unsigned) const;
	char back() const;
	char front() const;
	char* str() const;
	unsigned length() const;
	unsigned capacity() const;
	bool empty() const;
	String& append(const char*);
	void clear();
	bool equals(const char*) const;
	bool equals(const String&) const;
	int find(const char) const;
	void shrinkToFit();
	void swap(String&);
	unsigned find(const String&) const;
	bool contains(const String&) const;
	bool contains(const char) const;
	String();
	String(const char*);
	String(const char*, unsigned);
	String(const String&);
	String& operator=(const String&);
	~String();
private:
	void resizeGrow();
	void resizeShrink();
	void copy(const String&);
	void free();
	char* text;
	unsigned cap;
	unsigned actualSize;
};

