#include "Foo.h"

//Foo is modifiable rvalue: there is no potential users so we can change the object itself
Foo Foo::sorted() && {
	std::cout << "Foo Foo::sorted()&&" << std::endl;
	std::sort(data.begin(), data.end());
	return *this;

}

//for lvalue or const rvalue
Foo Foo::sorted() const & {
	std::cout << "Foo Foo::sorted() const&" << std::endl;
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}


void Foo::print() const {
	for(auto & i : data) {
		std::cout << i << std::endl;
	}
}

