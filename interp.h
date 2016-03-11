#pragma once
#include <QVector>
#include <QObject>
enum run{
    ADD,
    HALT,
    ARG
};
class Interp : public QObject{
    Q_ENUM(run)
     int pc;
     int ac;
     int instr;
     run instrType;
     int dataLoc;
     int data;
     bool runBit = true;
     QVector<int> memory;

public:
     void interpreter(QVector<int> memory, int firstAddress);
private:
     void setMemory(const QVector<int> &value);
     run getInstrType(int inst);
     int findData(int instr, int type);
     void execute(run type, int data);



};
