// Signal.cpp
#include "Signal.h"
#include <algorithm>    // for std::sort, std::upper_bound

Signal::Signal(const std::string& name)
    : name(name)
{
    // At t = 0, default value is false
    history.emplace_back(0.0, false);
}

void Signal::setValue(bool v, double t) {
    // Append the new event
    history.emplace_back(t, v);
    // Keep history sorted by time ascending
    std::sort(
        history.begin(), history.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        }
    );
}

bool Signal::getValueAt(double t) const {
    // Find the first event with time > t
    auto it = std::upper_bound(
        history.begin(), history.end(),
        std::make_pair(t, true),
        [](const auto& lhs, const auto& rhs) {
            return lhs.first < rhs.first;
        }
    );

    // If all events are > t, return the very first (which is at t=0)
    if (it == history.begin()) {
        return it->second;
    }

    // Otherwise step back to the last event ≤ t
    --it;
    return it->second;
}

const std::string& Signal::getName() const {
    return name;
}
