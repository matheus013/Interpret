#include <QCoreApplication>
#include <QDebug>

#include "interp.h"

using namespace std;

int main(int argc, char *argv[]) {

    QVector<int> memory;
    Interp inter;

    while(true) {
        QTextStream input(stdin);
        QStringList memoryInput =
                input.readLine().split(QRegExp("\\W+"), QString::SkipEmptyParts);

        for(int i = 0; i < memoryInput.length(); i++) {
            QString arg = memoryInput.at(i);

            if(!arg.compare("ADD")) {
                memory.append(-10);
            }
            else if (!arg.compare("HALT")) {
                memory.append(-5);
            }
            else {
                memory.append(arg.toInt());
            }
            //qDebug() << memoryInput.at(i);
        }
        qDebug() << memory;
        //inter.interpreter(memory,0);
    }
   // memory << -10 << 2 << -10 << 1 << -5 << -3 << -5 << 0;
}
