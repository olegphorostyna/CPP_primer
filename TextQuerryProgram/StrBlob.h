#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> ls);
	StrBlob(const StrBlob& o):data(o.data){
		
	};
	StrBlob& operator=(const StrBlob& o){
		data =o.data;
		return *this;
	};
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//add and remove elements
	inline void push_back(const std::string& t) {		
		data->push_back(t);
	}
	inline void push_back(const std::string&& t) {
		std::cout << "StrBlob::push_back(std::string &&s)" << std::endl;
		data->push_back(std::move(t));
	}
	void pop_back();
	//elements access

	StrBlobPtr begin();

	StrBlobPtr end();

	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;
	//throw message when data[i] is invalid
	void check(size_type i, const std::string& message) const;
};