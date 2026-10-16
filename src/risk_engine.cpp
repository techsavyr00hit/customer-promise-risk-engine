#include "risk_engine.hpp"
#include <sstream>

std::vector<RiskResult> RiskEngine::evaluate(const std::vector<Promise>& p, const std::string& d) const {
    std::vector<RiskResult> r;
    for (const auto& x : p) r.push_back(calculateRisk(x, d));
    return r;
}

std::string RiskEngine::report(const Promise& p, const RiskResult& r) {
    std::ostringstream o;
    o << p.customer << " | " << p.description << " | due " << p.dueDate
      << " | score " << r.score << " | " << r.level;
    return o.str();
}

std::vector<size_t> RiskEngine::highRisk(const std::vector<Promise>& p, const std::string& d, int t) const {
    auto r = evaluate(p, d);
    std::vector<size_t> out;
    for (size_t i = 0; i < r.size(); ++i)
        if (r[i].score >= t) out.push_back(i);
    return out;
}
