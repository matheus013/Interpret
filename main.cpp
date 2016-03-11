#include <QCoreApplication>
#include "interp.h"
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QVector<int> memory;

    memory << -10 << 2 << -10 << 1 << -5 << -3 << -5 << 0;
    Interp inter;
    inter.interpreter(memory,0);
    return a.exec();
}
