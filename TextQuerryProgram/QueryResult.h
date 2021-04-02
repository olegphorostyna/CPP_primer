#pragma once
#include <iostream>;
#include <memory>
#include <string>
#include <set>
#include <vector>
#include "StrVec.h"
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
	
public:
	typedef std::vector<std::string>::size_type line_no;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<StrVec> f) :
		sought(s), lines(p), file(f) {}

	std::set<line_no>::iterator begin() {
		return lines->begin();
	}
	std::set<line_no>::iterator end()
	{
		return lines->end();
	}

	std::shared_ptr<StrVec> get_file() {
		return file;
	}

private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<StrVec> file;
};



