#include "interp.h"
#include <QDebug>

void Interp::setMemory(const QVector<int> &value) {
    m_memory = value;
}

void Interp::interpreter(QVector<int> memory, int firstAddress) {
    setMemory(memory);
    m_pc = firstAddress;
    m_runBit = true;
    m_ac = 0;
    while (m_runBit) {
        m_instr = memory[m_pc];
        m_instrType = getInstrType(m_instr);
        m_dataLoc = findData(m_instr, m_instrType);
        m_pc+=2;
        if(m_dataLoc >= 0)
            m_data = memory[m_dataLoc];
        execute(m_instrType , m_data);
    }
}

run Interp::getInstrType(int inst) {
    if(inst == -10) return ADD;
    if(inst == -5) return HALT;
    return ARG;
}

int Interp::findData(int instr, int type) {
    for (int i = m_pc; i < m_memory.size(); ++i)
        if(m_memory[i] == instr && getInstrType(instr) == type)
            return i + 1;
}

void Interp::execute(run type, int data) {
    switch (type) {
    case ADD:
        m_ac += data;
        break;
    case HALT:
        m_runBit = false;
        qDebug() << "Resultado da operacao: " << m_ac;
        break;
    case ARG:
        qDebug() << "instrucao "<< m_pc/2 << " invalida";
        break;
    default:
        qDebug() << type << data;
    }
}

void Interp::startInfo() {
    qDebug() << "Para utilizar o interpretador, forneca entradas no formato:\n\n"
             << "<INSTRUCAO1> <OPERANDO1> <INSTRUCAO2> <OPERANDO2> ...\n";
    qDebug() << "Para verificar as instrucoes disponiveis digite 'h'.\n";
}

void Interp::usageInfo() {
    qDebug() << "Forma de uso:\n"
             << "<INSTRUCAO1> <OPERANDO1> <INSTRUCAO2> <OPERANDO2> ...\n"
             << "Exemplo: ADD 1 ADD 2\n";
}

void Interp::availableOperationsInfo() {
    qDebug() << "Instrucoes disponiveis:\n"
             << "ADD\n"
             << "HALT\n";
}
