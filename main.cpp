//#include "mainwindow.h"
#include "ised_win.h"
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QDialog>
void accept()
{}

void reject()
{}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ised::ised_win w;

     w.show();
    return a.exec();
}
