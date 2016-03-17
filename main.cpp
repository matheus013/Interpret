#include <QCoreApplication>
#include <QDebug>

#include "interp.h"


int main(int argc, char *argv[]) {
    Q_UNUSED(argc); Q_UNUSED(argv);

    Interp inter;
    inter.startInfo();

    while(true) {
        QVector<int> memory;
        QTextStream input(stdin);
        QStringList memoryInput =
                input.readLine().split(QRegExp("\\W+"), QString::SkipEmptyParts);
        //Help menu
        if(memoryInput.length() == 1) {
            if(!QString::compare("h", memoryInput.at(0), Qt::CaseSensitive)) {
                inter.availableOperationsInfo();
                inter.usageInfo();
            }
            else {
                //Yep... informações em português e sem acentuação
                //mesmo, não é que nós sejamos analfabetos...
                //mas a situação exige.
                qDebug() << "Instrucao invalida";
                inter.startInfo();
            }
        }
        //fill memory
        else {
            for(int i = 0; i < memoryInput.length(); i++) {
                QString arg = memoryInput.at(i);

                if(!arg.compare("ADD")) {
                    memory.append(-10);
                }
                else if (!arg.compare("HALT")) {
                    memory << -5 << 0;
                }
                else if (!arg.compare("SUB")) {
                    memory.append(-15);
                }
                else if (!arg.compare("MULT")) {
                    memory.append(-20);
                }
                else {
                    if(inter.valid(arg))
                        memory.append(arg.toInt());
                    else
                        memory << -9;
                }
            }
            //We must always have a halt operation
            //so the process will always stop
            memory << -5 << 0;
            (memory[0] == -20) ? memory.append(1) : memory.append(0);
            //Interpret instructions
            inter.interpreter(memory, 0);
        }
    }
}
