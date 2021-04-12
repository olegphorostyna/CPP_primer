#pragma once
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"
#include "QueryResult.h"
class StrBlobPtr {
	friend bool operator==(const StrBlobPtr& l, const StrBlobPtr& r);
	friend bool operator!=(const StrBlobPtr& l, const StrBlobPtr& r);
	friend bool operator>(const StrBlobPtr& l, const StrBlobPtr& r);
	friend bool operator<(const StrBlobPtr& l, const StrBlobPtr& r);
	friend bool operator>=(const StrBlobPtr& l, const StrBlobPtr& r);
	friend bool operator<=(const StrBlobPtr& l, const StrBlobPtr& r);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, QueryResult::line_no index = 0) :
		wptr(a.data), curr(index) {}	
	std::string& deref() const;
	StrBlobPtr& incr();

private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	QueryResult::line_no curr;
};