#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include "StrVec.h"
class QueryResult;
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<StrVec> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
 };