#include "StrVec.h"
#include <algorithm>
//StrVec(const StrVec&);
//StrVec& operator=(const StrVec&);
//~StrVec();
//
//void push_back(const std::string&); // copy element
//size_t size() const { return first_free - elements; }
//size_t capacity() const { return cap - elements; }
//std::string* begin() { return elements; }
//std::string* end() { return first_free; }
//private:
//	std::allocator<std::string> alloc;
//
//	void chk_n_alloc() {
//		if (size() == capacity()) reallocate();
//	}
//
//	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
//
//	void free();
//	void reallocate();
//
//	std::string* elements; // first element in mem array 
//	std::string* first_free; // first free element in a array 
//	std::string* cap; // one past the end element

void StrVec::push_back(const std::string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);

}

//allocate memory suitable for holding elements from input range;
//copy ellements from given range into newley created memory space;
//return pair of poiners - begin of a new sequence and one past the end;
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	if (elements){
		for_each(elements, first_free, [&](std::string &s) {
			alloc.destroy(&s);
			});
	 
	
		alloc.deallocate(elements, cap - elements);
	}
}


StrVec::StrVec( StrVec&& o) noexcept : elements(o.elements), first_free(o.first_free), cap(o.cap) {
	o.elements = o.first_free = o.cap = nullptr;
}


StrVec& StrVec::operator=(StrVec&& o) noexcept {
	if (this != &o) {
		free();
		elements = o.elements;
		first_free = o.first_free;
		cap = o.cap;
		
		o.first_free = o.elements = o.cap = nullptr;
	}
	return *this;
}


StrVec::StrVec(const StrVec& o) {
	auto newData = alloc_n_copy(o.begin(), o.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVec::~StrVec() {
	free();
}

void StrVec::resize(size_t n) {
	auto newdata = alloc.allocate(n);
	//move data from old memory to the new 
	auto dest = newdata; // next free position in a new array
	auto elem = elements; // next element in old array
	for (size_t i = 0; (i != size()) && (i < n); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	//free old elements after data movement
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::reserve(size_t n) {
	if (n > capacityBeforeRealocate()) {		
		auto newdata = alloc.allocate(n);
		//move data from old memory to the new 
		auto dest = newdata; // next free position in a new array
		auto elem = elements; // next element in old array
		for (size_t i = 0; i != size(); ++i) {
			alloc.construct(dest++, std::move(*elem++));
		}
		//free old elements after data movement
		free();

		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}

StrVec& StrVec::operator=(const StrVec& r) {
	auto data = alloc_n_copy(r.begin(), r.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	//move data from old memory to the new 
	auto dest = newdata; // next free position in a new array
	auto elem = elements; // next element in old array
	//for (size_t i = 0; i != size(); ++i) {
	//	alloc.construct(dest++, std::move(*elem++));
	//}

	//use move iterators to fill unitialized space
	std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);

	//free old elements after data movement
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}