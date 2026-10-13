#pragma once
#include "promise.hpp"
#include "report.hpp"
#include <vector>
#include <string>
#include <map>

class RiskEngine {
public:
    std::vector<RiskResult> evaluate(const std::vector<Promise>&, const std::string&) const;
    static std::string report(const Promise&, const RiskResult&);
    std::vector<size_t> highRisk(const std::vector<Promise>&, const std::string&, int threshold = 60) const;
    std::map<std::string, int> summary(const std::vector<Promise>&, const std::string&) const;
};