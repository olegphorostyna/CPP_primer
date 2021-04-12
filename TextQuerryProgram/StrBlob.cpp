#include "StrBlob.h"
#include <stdexcept>
#include "StrBlobPtr.h"


StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}



void StrBlob::check(size_type i, const std::string& message) const {
	if (i >= data->size()) {
		throw std::out_of_range(message);
	}
}


std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}


StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}


void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

 bool operator==(const StrBlob& l, const StrBlob& r) {
	return *l.data == *r.data;	
}
 bool operator!=(const StrBlob& l, const StrBlob& r) {
	return !(l==r);
}


 bool operator>(const StrBlob& l, const StrBlob& r) {
	 return *l.data > * r.data;
 }
 bool operator<(const StrBlob& l, const StrBlob& r) {
	 return r > l;
 }
 bool operator>=(const StrBlob& l, const StrBlob& r) {
	 return !(l < r);
 }
 bool operator<=(const StrBlob& l, const StrBlob& r) {
	 return !(l > r);
 }