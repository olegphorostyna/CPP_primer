#pragma once
#include <string>
#include <ostream>
class Quote {
public:
  Quote() = default;
  Quote(const std::string& book, double sale_price) :book_no(book), price(sale_price) {}
  std::string isbn() const { return book_no; }
  virtual double net_price(std::size_t n) const {
    return n * price;
  }

  virtual ~Quote() = default;
private:
  std::string book_no;
protected:
  double price = 0.0;
};


double print_total(std::ostream &os, const Quote& item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}
