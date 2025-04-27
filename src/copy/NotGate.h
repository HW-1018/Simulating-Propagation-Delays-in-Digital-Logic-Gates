// NotGate.h
#pragma once
#include "Gate.h"

class NotGate : public Gate {
public:
    NotGate(const std::string& name, double delay = 3.0)
        : Gate(name, delay) {}
protected:
    bool evaluate(bool a, bool /*unused*/) const override {
        return !a;
    }
};
