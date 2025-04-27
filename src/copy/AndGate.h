// AndGate.h
#pragma once
#include "Gate.h"

class AndGate : public Gate {
public:
    AndGate(const std::string& name, double delay = 3.0)
        : Gate(name, delay) {}
protected:
    bool evaluate(bool a, bool b) const override {
        return a && b;
    }
};
