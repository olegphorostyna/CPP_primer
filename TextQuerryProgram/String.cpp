#include "String.h"
#include <iostream>


std::allocator<char> String::alloc;

String::String(const char* c) : String() {
	std::cout << "Const char constructor" << std::endl;
	while (c && *c != '\0')
		push_back(*c++);
}

String::String(std::initializer_list<char> li) {
	for (auto c : li) {
		push_back(c);
	}
}


String::String(const String& o) {
	std::cout << "Copy constructor" << std::endl;
	first_elem = alloc.allocate(o.size());
	first_free = cap = std::uninitialized_copy(o.begin(), o.end(), first_elem);
}

String& String::operator=(const String& o) {
	std::cout << "Sddignment operator" << std::endl;
	auto new_storage = alloc.allocate(o.size());
	auto new_first_free = std::uninitialized_copy(o.begin(), o.end(), new_storage);
	free();
	first_elem = new_storage;
	first_free = cap = new_first_free;
	return *this;
}

void String::pop_back() {
	if (!empty()) {
		alloc.destroy(--first_free);
	}	
}

void String::reserve(size_t n) {
	if (n > capacity()) {
		realocate(n);
	}
}


std::string String::str() const {
	return std::string(cbegin(), cend());	
}

void String::resize(size_t n, const char& c) {
	if (n > size()) {
		for (int i = n - size(); i > 0; --i) {
			push_back(c);
		}
	}
	else if (n < size()) {
		for (int i = size() - n; i > 0; --i) {
			pop_back();
		}
	}
}


void String::push_back(const char& ch) {
	if (size() == capacity())
		realocate(empty() ? 1 : 2 * capacity());
	alloc.construct(first_free++, ch);
}


String::~String() {
	free();
}


void String::realocate(size_t n) {
	auto new_storage = alloc.allocate(n);
	auto new_first_free = new_storage;
	for (auto it = begin(); it != end(); it++) {
		alloc.construct(new_first_free++, std::move(*it));
	}
	free();
	first_elem = new_storage;
	first_free = new_first_free;
	cap = first_elem + n;
}

void String::free() {
	while (!empty()) {
		alloc.destroy(--first_free);
	}
	alloc.deallocate(first_elem, capacity());
	first_free = first_elem = cap = nullptr;
}



std::ostream& operator<< (std::ostream& s, const String& d) {
	s << d.str();
	return s;
}


bool operator==(const String& l, const String& r) {
	return l.size() == r.size() && std::equal(l.begin(), l.end(), r.begin());
}
bool operator!=(const String& l, const String& r) {
	return !(l == r);
}

bool operator>(const String& l, const String& r) {
	auto li = l.begin(), ri = r.begin();
	for (; li != l.end() && ri != r.end(); li++, ri++)
		if (*li > * ri)
			return true;
		else if (*li < *ri)
			return false;
	return ri == r.end() && li != l.end();
}
bool operator<(const String& l, const String& r) {
	return r > l;
}
bool operator>=(const String& l, const String& r) {
	return !(l < r);
}
bool operator<=(const String& l, const String& r) {
	return !(l > r);
}



