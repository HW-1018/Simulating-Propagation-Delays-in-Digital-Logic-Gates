// Signal.h
#pragma once

#include <string>
#include <vector>
#include <utility>
#include "SignalSource.h"

class Signal : public SignalSource {
public:
    // Construct a signal with the given name, initialize to false at t=0
    Signal(const std::string& name);

    // Record that this signal takes value v at time t
    void setValue(bool v, double t);

    // Retrieve the signal's value at time t (override of SignalSource)
    bool getValueAt(double t) const override;

    // Accessor for the signal's name
    const std::string& getName() const;

private:
    std::string                           name;
    // History of (time, value) pairs, sorted by time ascending
    std::vector<std::pair<double, bool>>   history;
};
