/*!
  \author Alexander Syvak. (alexander.svk@gmail.com)
  \date Aug, 2013.
*/
// PROJECT
#include <QVBoxLayout> // USES
#include <QLineEdit> // USES
#include <QLabel> // USES
#include <QPushButton> // USES

#include <QApplication> // -//-

#include <QFile> // uses => remove

#include <QStatusBar> // aggregates
#include <QAction> // uses
#include <QtNetwork/QTcpSocket> // aggregates
#include <QFileInfo> // uses => absoluteDir, canonicalPath

#include <QApplication> // uses => activeWindow
#include <QScreen> // uses => primaryScreen
#include <QDialog>
#include <QTextEdit>
#include <qdebug.h>
#include <memory>
// LOCAL
#include "ised_win.h" // IMPLEMENTS


namespace ised
{
// operationx

// ctor

ised_win::ised_win(QWidget *parent)
    : QMainWindow(parent)
{
    //authenticate
    this->setCentralWidget(&m_w);

    resize(640,480);
    // 1. button & label
    QLabel *label = new QLabel("<center>Привет, мир!</center>");
    QBoxLayout* layout = new QHBoxLayout;
    m_edit = new QLineEdit;
    layout->addWidget( m_edit );

    QPushButton* okBtn = new QPushButton( "OK" );
    connect( okBtn, SIGNAL( clicked() ), this, SLOT(accept()) );
    layout->addWidget( okBtn );

    vbox = new QVBoxLayout();
    vbox->addWidget(label);
    vbox->addLayout(layout);
    m_w.setLayout(vbox);

    vbox->setEnabled(true);
}

ised_win::~ised_win()
{

}

void ised_win::accept()
{
    m_session = m_edit->text();

    int c = calc();
    // Add
    if (grid)
    {
        //delete grid;
    }
    grid = new QVBoxLayout();
    for (int j = 0; j < c; ++j)
    {
        char buffer[3];
        itoa(j, buffer, 10);//to do
        auto bp = new QPushButton(buffer);
        grid->addWidget(bp);
    }
    vbox->addLayout(grid);

    QPushButton *btnNewWnd = new QPushButton("&Открыть новое окно");
    vbox->addWidget(btnNewWnd);

    QObject::connect(btnNewWnd, SIGNAL(clicked()),
                     this, SLOT(onBtnPressed()));

}//accept

void ised_win::onBtnPressed()
{
    ndlg = new QDialog(this);
    ndlg->setModal(false);
    ndlg->resize(320, 240);
    QVBoxLayout* l = new QVBoxLayout;
    int c = calc();
    for (int j = 0; j < c; ++j)
    {
        char buffer[3];
        itoa(j, buffer, 10);//to do
        auto bp = new QTextEdit(buffer);
        l->addWidget(bp);
    }
    ndlg->setLayout(l);
    ndlg->show();
}

int ised_win::calc()
{
    int c = 0;
    if (m_session == "111")
    {
        c = 4;
    }
    else if (m_session == "222")
    {
        c = 6;
    }
    else
    {
        c = 2;
    }
    return c;
}
}
