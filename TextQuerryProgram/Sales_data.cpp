#include "Sales_data.h"


Sales_data& Sales_data::operator+=(const Sales_data& d) {
	units_sold += d.units_sold;
	revenue += d.revenue;
	return *this;
}


Sales_data operator+(const Sales_data& l, const Sales_data& r) {
	Sales_data sd = r;
	sd += l;
	return sd;
}


std::istream& operator>>(std::istream& s, Sales_data& d) {
	double price;
	s >> d.bookNo >> d.units_sold >> price;
	if (s) {
		d.revenue = d.units_sold * price;
	}
	else {
		d = Sales_data();
	}
	return s;
}
std::ostream& operator<<(std::ostream& s, const Sales_data& d) {
	s << d.isbn() << " " << d.units_sold << " " << d.revenue << " " << d.avg_price();
	return s;
}




inline double Sales_data::avg_price() const {
	return units_sold ? revenue / units_sold : 0;
}

Sales_data &Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& l, const Sales_data& r) {
	Sales_data sum = l;
	sum.combine(r);
	return sum;
}

std::istream& read(std::istream& s, Sales_data &d) {
	double price;
	s >> d.bookNo >> d.units_sold >> price;
	d.revenue = d.units_sold * price;
	return s;
}
std::ostream& print(std::ostream& s, const Sales_data& d) {
	s << d.isbn() << " " << d.units_sold << " " << d.revenue << " " << d.avg_price();
	return s;
 }