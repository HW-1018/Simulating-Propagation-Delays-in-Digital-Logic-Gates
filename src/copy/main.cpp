// main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <memory>

#include "Signal.h"
#include "Gate.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "XorGate.h"
#include "XnorGate.h"

using namespace std;

int main() {
    // 管理所有 Signal 和 Gate 實例
    unordered_map<string, unique_ptr<Signal>> signals;
    unordered_map<string, unique_ptr<Gate>>   gates;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string cmd;
        iss >> cmd;

        if (cmd == "Add") {
            string type, name;
            iss >> type >> name;
            if (type == "signal") {
                signals[name] = make_unique<Signal>(name);
            }
            else {
                // 根據 gate type 建立對應子類別
                if (type == "AND")  gates[name] = make_unique<AndGate>(name);
                else if (type == "OR")   gates[name] = make_unique<OrGate>(name);
                else if (type == "NOT")  gates[name] = make_unique<NotGate>(name);
                else if (type == "NAND") gates[name] = make_unique<NandGate>(name);
                else if (type == "NOR")  gates[name] = make_unique<NorGate>(name);
                else if (type == "XOR")  gates[name] = make_unique<XorGate>(name);
                else if (type == "XNOR") gates[name] = make_unique<XnorGate>(name);
                else {
                    cout << "Unknown gate type: " << endl;
                }
            }
        }
        else if (cmd == "Set") {
            string name, val;
            double t;
            iss >> name >> val >> t;
            bool b = (val == "True");
            if (signals.count(name)) {
                signals[name]->setValue(b, t);
            }
            else {
                cout << "Unknown gate type: " << endl;
            }
        }
        else if (cmd == "Bind") {
            string src, dst;
            int pin;
            iss >> src >> dst >> pin;
            SignalSource* srcPtr = nullptr;
            if (signals.count(src)) srcPtr = signals[src].get();
            else if (gates.count(src)) srcPtr = gates[src].get();
            else {
                cout << "Unknown gate type: " << endl;
                continue;
            }
            if (gates.count(dst)) {
                gates[dst]->bind(srcPtr, pin);
            }
            else {
                cout << "Unknown gate type: " << endl;
            }
        }
        else if (cmd == "Query") {
            string name;
            double t;
            iss >> name >> t;
            if (gates.count(name)) {
                bool out = gates[name]->getValueAt(t);
                cout << (out ? "True\n" : "False\n");
            }
            else {
                cout << "Unknown gate type: " << endl;
            }
        }
        else if (cmd == "EXIT") {
            break;
        }
        else {
            cout << "Unknown gate type: " << endl;
        }
    }

    return 0;
}
