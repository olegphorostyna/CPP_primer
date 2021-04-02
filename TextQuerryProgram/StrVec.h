#pragma once
#include <string>
#include <memory>
#include <initializer_list>

class StrVec {
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {
	
	}

	StrVec(std::initializer_list<std::string> l) : StrVec() {
		for (auto b = l.begin(); b != l.end(); ++b) {
			push_back(*b);
		}		
	}
	StrVec( StrVec&&) noexcept;
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec&& rhs) noexcept;
	~StrVec();


	void push_back(const std::string&); // copy element
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	size_t capacityBeforeRealocate() const { return cap - first_free; }
	void reserve(size_t );
	void resize(size_t );
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
private:
	std::allocator<std::string> alloc;

	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}

	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);

	void free();
	void reallocate();

	std::string* elements; // first element in mem array 
	std::string* first_free; // first free element in a array 
	std::string* cap; // one past the end element 

};
