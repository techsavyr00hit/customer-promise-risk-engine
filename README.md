# Customer Promise Risk Engine

A small C++ CRM intelligence project that detects customer commitments that are likely to be missed.

## Stack
- C++17
- MongoDB + mongocxx/bsoncxx
- cpr HTTP client
- nlohmann/json
- Salesforce REST API
- CMake

## Idea
Salespeople make commitments such as sending quotations, arranging demos, or calling customers. Salesforce records the activity, but a commitment can still become overdue. This engine turns those commitments into an explainable risk score.

## Risk rules
- Overdue: +40
- Due today: +20
- High-value customer: +15
- Previous missed promises: +15
- Rescheduled: +10

Scores: 0-29 LOW, 30-59 MEDIUM, 60-79 HIGH, 80+ CRITICAL.