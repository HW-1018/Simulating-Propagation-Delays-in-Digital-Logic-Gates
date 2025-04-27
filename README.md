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
```

## 特色功能

- 支援多種邏輯閘（AND、OR、NOT、NAND、NOR、XOR、XNOR）
- 可自訂訊號並設定任意時刻的值
- 支援訊號與閘的綁定，自由組合電路結構
- 支援 propagation delay（訊號傳遞延遲）
- 可查詢任意時刻 Gate 的輸出（歷史追蹤）
## 基本使用方式
啟動程式後，於命令列依下列格式輸入指令：
ˋˋˋbash
Add signal <名稱>                # 新增訊號
Add AND <閘名稱>                 # 新增 AND 閘（其他閘類型同理）
Set <訊號名稱> <True/False> <t>  # 設定某訊號在 t 時刻的值
Bind <來源> <目標閘> <pin>       # 將來源訊號/閘綁定至閘的第 pin 腳
Query <閘名稱> <t>               # 查詢閘在 t 時間點的輸出
EXIT                             # 離開程式
ˋˋˋ
## 範例流程
ˋˋˋbash
Add signal a
Add signal b
Add AND g1
Set a True 0
Set b False 0
Bind a g1 0
Bind b g1 1
Query g1 10
ˋˋˋ
