#pragma once

// �w�q��H���� Component
struct SignalSource {
	virtual ~SignalSource() = default;
	virtual bool getValueAt(double t) const = 0;
};