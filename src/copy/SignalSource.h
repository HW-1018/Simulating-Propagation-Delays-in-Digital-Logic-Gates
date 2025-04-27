#pragma once

// 定義抽象介面 Component
struct SignalSource {
	virtual ~SignalSource() = default;
	virtual bool getValueAt(double t) const = 0;
};