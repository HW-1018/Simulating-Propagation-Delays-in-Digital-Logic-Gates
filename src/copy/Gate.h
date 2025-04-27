// Gate.h
#pragma once

#include <string>
#include "SignalSource.h"

// Abstract base class for all logic gates, also a signal source
class Gate : public SignalSource {
public:
    // Construct a gate with a name and optional propagation delay (default 3.0 ns)
    Gate(const std::string& name, double delay = 3.0);

    // Ensure proper teardown via the virtual destructor
    virtual ~Gate() = default;

    // Bind a signal or another gate output to the specified pin (0 or 1)
    void bind(SignalSource* src, int pin);

    // Return the output value of this gate at time t, considering its delay
    bool getValueAt(double t) const override;

protected:
    // Subclasses implement this to apply their specific logic (AND, OR, etc.)
    virtual bool evaluate(bool a, bool b) const = 0;

    std::string    name;   // Identifier for this gate
    double         delay;  // Propagation delay in nanoseconds
    SignalSource* in0;    // Pointer to the first input source
    SignalSource* in1;    // Pointer to the second input source
};
