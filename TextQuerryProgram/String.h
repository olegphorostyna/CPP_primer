#pragma once
#include <memory>
#include <string>
#include <iostream>

class String {
	friend std::ostream & operator<< (std::ostream& s, const String& d);
	friend bool operator==(const String& l, const String& r);
	friend bool operator!=(const String& l, const String& r);
	friend bool operator>(const String& l, const String& r);
	friend bool operator<(const String& l, const String& r);
	friend bool operator>=(const String& l, const String& r);
	friend bool operator<=(const String& l, const String& r);
public:
	String() :first_elem(nullptr), first_free(nullptr), cap(nullptr){}
	String(const char*);
	String(const String&);
	String(std::initializer_list<char>);
	~String();
	String& operator=(const String&);

	void push_back(const char&);
	void pop_back();

	void reserve(size_t);
	void resize(size_t, const char& = char());

	bool empty() const { return cbegin() == cend(); }
	size_t size() const { return first_free - first_elem; }
	size_t capacity() const { return cap - first_elem; }

	char* begin() {return first_elem;}
	char* end() {return first_free;}
	const char* begin() const { return first_elem; }
	const char* end() const  { return first_free; }
	const char* cbegin() const { return begin(); }
	const char* cend() const { return end(); }

	std::string str() const;
private:
	static std::allocator<char> alloc;
	
	char* first_elem;
	char* first_free;
	char* cap;

	void realocate(size_t);
	void free();

};

std::ostream& operator<< (std::ostream& s, const String& d);
