# Simulating-Propagation-Delays-in-Digital-Logic-Gates
```mermaid
classDiagram
    %% Signal Management
    class SignalSource {
        <<interface>>
        +getValueAt(t): bool
    }
    class Signal {
        -name: string
        -history: vector<pair<double,bool>>
        +Signal(name)
        +setValue(v, t)
        +getValueAt(t): bool
        +getName(): string
    }
    SignalSource <|.. Signal

    %% Logic Gates
    class Gate {
        <<abstract>>
        -name: string
        -delay: double
        -in0: SignalSource*
        -in1: SignalSource*
        +Gate(name, delay)
        +bind(src, pin)
        +getValueAt(t): bool
        #evaluate(a, b): bool
    }
    class AndGate {
        +AndGate(name, delay)
        #evaluate(a, b): bool
    }
    class OrGate {
        +OrGate(name, delay)
        #evaluate(a, b): bool
    }
    class NotGate {
        +NotGate(name, delay)
        #evaluate(a, b): bool
    }
    class NandGate {
        +NandGate(name, delay)
        #evaluate(a, b): bool
    }
    class NorGate {
        +NorGate(name, delay)
        #evaluate(a, b): bool
    }
    class XorGate {
        +XorGate(name, delay)
        #evaluate(a, b): bool
    }
    class XnorGate {
        +XnorGate(name, delay)
        #evaluate(a, b): bool
    }

    Gate <|-- AndGate
    Gate <|-- OrGate
    Gate <|-- NotGate
    Gate <|-- NandGate
    Gate <|-- NorGate
    Gate <|-- XorGate
    Gate <|-- XnorGate

    %% Command Interface (main.cpp)
    class CommandInterpreter {
        +signals: map<string, Signal*>
        +gates: map<string, Gate*>
        +run()
    }

    CommandInterpreter ..> Signal
    CommandInterpreter ..> Gate
    Gate o-- SignalSource : input

    %% 分區塊用 note 標示
    note for SignalSource "Signal Management"
    note for Signal "Signal Management"
    note for Gate "Logic Gates System"
    note for AndGate "Logic Gates System"
    note for OrGate "Logic Gates System"
    note for NotGate "Logic Gates System"
    note for NandGate "Logic Gates System"
    note for NorGate "Logic Gates System"
    note for XorGate "Logic Gates System"
    note for XnorGate "Logic Gates System"
    note for CommandInterpreter "Command Interpreter"
