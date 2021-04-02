#pragma once
#include <string>
#include <iostream>
#include <vector>

class Book {

	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend std::istream& operator>>(std::istream&, Book&);

public:

	Book() : isbn(""), name(""), authors(), published_year(0), publisher(""), version(0) {}
	Book(const std::string& i, const std::string& n, const std::vector<std::string> &a, unsigned y, const std::string& p, unsigned v = 1)
		: isbn(i),name(n), authors(a), published_year(y),publisher(p),version(v) {}
	Book(std::istream& is) {
		is >> isbn >> name;
		std::string s;
		is >> s;
		authors.push_back(s);
		is >> published_year >> publisher >> version;
	}


private:
	std::string isbn;
	std::string name;
	std::vector<std::string> authors;
	unsigned published_year;
	std::string publisher;
	unsigned version;
};



std::ostream& operator<<(std::ostream& s, const Book& d) {
	s << d.isbn<<" "<< d.name<<" ";
	for (const auto& str : d.authors) {
		s << str << " ";
	}
	s << d.published_year << " " << d.publisher << " " << d.version;
	return s;	
}

std::istream& operator>>(std::istream& s, Book& d) {
	s >> d.isbn >> d.name;
	std::string str;
	s >> str;
	d.authors.push_back(str);
	s >> d.published_year >> d.publisher >> d.version;
	if (!s) {
		d = Book();
	}
	return s;
}
