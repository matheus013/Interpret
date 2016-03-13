#include <QCoreApplication>
#include <QDebug>

#include "interp.h"

int main(int argc, char *argv[]) {

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
                qDebug() << "Instrucao invalida";
                inter.startInfo();
            }
        }
        //fill memory
        else {
            for(int i = 0; i < memoryInput.length(); i++) {
                QString arg = memoryInput.at(i);

                if(!arg.compare("ADD")) {//Sum operation
                    memory.append(-10);
                }
                else if (!arg.compare("HALT")) { //Stop operation
                    memory.append(-5);
                }
                else {
                    memory.append(arg.toInt());
                }
            }
            //We must always have a halt operation
            //so the process will always stop
            memory.append(-5);
            memory.append(0);

            //Interpre instructions
            inter.interpreter(memory, 0);
        }
    }
}
