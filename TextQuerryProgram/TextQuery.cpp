#include "TextQuery.h"
#include "QueryResult.h"





TextQuery::TextQuery(std::ifstream& is) : file(new StrVec()) {
	std::string text;
	while (std::getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1; // the current line number
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines) { //lines is null when key is inserted for the first time
				lines.reset(new std::set<line_no>);
			}
			lines->insert(n);
		}

	}
}

QueryResult TextQuery::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);
	}
	else {
		return QueryResult(sought, loc->second, file);
	}
}