#pragma once
#include "Quote.h"

class Bulk_limit : public Quote {
public:
	Bulk_limit() = default;
	Bulk_limit(const std::string& book, double p, std::size_t lim , double disc) :
		Quote(book, p), limit(lim), discount(disc) {}

	double net_price(std::size_t) const override;
private:
	std::size_t limit = 0; // limit to which discount is applied 
	double discount = 0.0; // fractional discount to apply

};


double Bulk_limit::net_price(std::size_t cnt) const {
	if (cnt >= limit) {
		return limit*(1 - discount) * price+(cnt-limit)*price;
	}
	else {
		return cnt * (1 - discount) * price;
	}
}
