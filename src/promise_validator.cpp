#include "promise_validator.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

ValidationResult validatePromise(const Promise& p) {
    std::vector<std::string> e;
    if (p.id.empty()) e.push_back("missing id");
    if (p.customer.empty()) e.push_back("missing customer");
    if (p.description.empty()) e.push_back("missing description");
    if (p.dueDate.size() != 10) e.push_back("invalid due date");
    if (p.customerValue < 0 || p.customerValue > 100) e.push_back("customer value must be 0-100");
    if (p.missedCount < 0) e.push_back("missed count cannot be negative");
    return {e.empty(), e};
}

static std::tm parse(const std::string& s) {
    std::tm t{};
    std::istringstream in(s);
    in >> std::get_time(&t, "%Y-%m-%d");
    return t;
}

int daysBetween(const std::string& a, const std::string& b) {
    auto x = parse(a), y = parse(b);
    auto tx = std::mktime(&x), ty = std::mktime(&y);
    return int(std::difftime(ty, tx) / (60 * 60 * 24));
}