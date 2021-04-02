#pragma once
#include<string>
#include<iostream>

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream& s, const Sales_data& d);
public:
	Sales_data() : Sales_data("", 0, 0.0) {}
	explicit Sales_data(const std::string& no) : Sales_data(no, 0, 0.0) {}
	Sales_data(const std::string& bn, unsigned s, double r) : bookNo(bn), units_sold(s), revenue(r) {}

	Sales_data& operator+=(const Sales_data&);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

