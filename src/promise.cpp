#include "promise.hpp"

RiskResult calculateRisk(const Promise& p, const std::string& today) {

    int s = 0;
    if (p.status == "OVERDUE" || p.dueDate < today) s += 40;
    else if (p.dueDate == today) s += 20;
    if (p.customerValue >= 80) s += 15;
    if (p.missedCount > 0) s += 15;
    if (p.rescheduled) s += 10;
    s = std::min(s, 100);

    std::string l = "LOW";
    if (s >= 80) l = "CRITICAL";
    else if (s >= 60) l = "HIGH";
    else if (s >= 30) l = "MEDIUM";
    return {s, l};
}