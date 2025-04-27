// OrGate.h
#pragma once
#include "Gate.h"

class OrGate : public Gate {
public:
    OrGate(const std::string& name, double delay = 3.0)
        : Gate(name, delay) {}
protected:
    bool evaluate(bool a, bool b) const override {
        return a || b;
    }
};
