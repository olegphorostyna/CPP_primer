#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

class Foo {
public:
	Foo() = default;
	Foo(std::initializer_list<int> li) :data(li) {}

	Foo sorted()&&;
	Foo sorted() const &;

	void print() const;

private:
	std::vector<int> data;


};
