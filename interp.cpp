#include "interp.h"
#include <QDebug>

void Interp::setMemory(const QVector<int> &value) {
    memory = value;
}

void Interp::interpreter(QVector<int> memory, int firstAddress) {
    setMemory(memory);
    pc = firstAddress;

    while (runBit) {
        instr = memory[pc];
        instrType = getInstrType(instr);
        dataLoc = findData(instr,instrType);
        pc+=2;
        if(dataLoc >= 0)
            data = memory[dataLoc];
        execute(instrType,data);
    }
}

run Interp::getInstrType(int inst){
    if(inst == -10) return ADD;
    if(inst == -5) return HALT;
    return ARG;
}

int Interp::findData(int instr, int type) {
    for (int i = pc; i < memory.size(); ++i)
        if(memory[i] == instr && getInstrType(instr) == type)
            return i + 1;
}

void Interp::execute(run type, int data) {
    qDebug() << "Data:" << data;
    switch (type) {
    case ADD:
        ac += data;
        break;
    case HALT:
        runBit = false;
        qDebug() << ac;
        break;
    case ARG:
        qDebug() << "instrunção invalida" << type;
        break;
    default:
        qDebug() << type << data;
    }
}
