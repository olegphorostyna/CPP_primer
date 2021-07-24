#pragma once
#include "Quote.h"

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}

	double net_price(std::size_t) const override;
private:
	std::size_t min_qty = 0; // min purchase for discount to apply
	double discount = 0.0; // fractional discount to apply

};


double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= min_qty) {
		return cnt * (1 - discount) * price;
	}
	else {
		return cnt * price;
	}
}
