#include "StrBlobPtr.h"
#include <stdexcept>


std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);

	return ret;
}


std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "deereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool operator==(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.wptr.lock() == r.wptr.lock() && l.curr == r.curr;
}
bool operator!=(const StrBlobPtr& l, const StrBlobPtr& r) {
	return !(l == r);
}

bool operator>(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.wptr.lock() == r.wptr.lock() && l.curr > r.curr;
}
bool operator<(const StrBlobPtr& l, const StrBlobPtr& r) {
	return r > l;
}
bool operator>=(const StrBlobPtr& l, const StrBlobPtr& r) {
	return !(l < r);
}
bool operator<=(const StrBlobPtr& l, const StrBlobPtr& r) {
	return !(l > r);
}