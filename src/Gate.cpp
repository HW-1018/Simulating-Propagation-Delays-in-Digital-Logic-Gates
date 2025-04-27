// Gate.cpp
#include "Gate.h"
#include <algorithm>    // for std::max
#include <stdexcept>    // for std::invalid_argument

Gate::Gate(const std::string& name, double delay)
    : name(name), delay(delay), in0(nullptr), in1(nullptr) { }

void Gate::bind(SignalSource* src, int pin) {
    if (pin == 0) {
        in0 = src;
    }
    else if (pin == 1) {
        in1 = src;
    }
    else {
        throw std::invalid_argument("Gate::bind: pin must be 0 or 1");
    }
}

bool Gate::getValueAt(double t) const {
    // Calculate effective input time, clamped to 0
    double t_in = t - delay;
    if (t_in < 0.0) t_in = 0.0;

    // Retrieve input values (nullptr ¡÷ false)
    bool a = in0 ? in0->getValueAt(t_in) : false;
    bool b = in1 ? in1->getValueAt(t_in) : false;

    // Evaluate the gate-specific logic
    return evaluate(a, b);
}
