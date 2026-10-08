#pragma once
#include <string>
#include <algorithm>
#include <vector>

struct Promise {
    std::string id, customer, description, dueDate, status = "OPEN";
    int customerValue = 0, missedCount = 0;
    bool rescheduled = false;
};

struct RiskResult {
    int score;
    std::string level;
};

RiskResult calculateRisk(const Promise&, const std::string& today);