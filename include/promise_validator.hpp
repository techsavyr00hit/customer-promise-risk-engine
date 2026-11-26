#pragma once
#include "promise.hpp"
#include <string>
#include <vector>

struct ValidationResult {
    bool valid;
    std::vector<std::string> errors;
};
ValidationResult validatePromise(const Promise& p);

int daysBetween(const std::string& from, const std::string& to);
