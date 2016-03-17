#pragma once
#include <QVector>
#include <QObject>

enum run{
    ADD,
    SUB,
    MULT,
    HALT,
    ARG
};

class Interp : public QObject {
    Q_ENUM(run)
    int m_pc;
    int m_ac;
    int m_instr;
    run m_instrType;
    int m_dataLoc;
    int m_data;
    bool m_runBit = true;
    QVector<int> m_memory;

public:
    void interpreter(QVector<int> memory, int firstAddress);
    void availableOperationsInfo();
    void startInfo();
    void usageInfo();
    bool valid(QString arg);

private:
    void setMemory(const QVector<int> &value);
    run getInstrType(int inst);
    int findData(int instr, int type);
    void execute(run type, int data);
};
