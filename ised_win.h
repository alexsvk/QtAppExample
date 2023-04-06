#ifndef ISED_WIN_H
#define ISED_WIN_H
#include <QMainWindow>
#include <qobject.h>
#include <qlineedit.h>
#include <QVBoxLayout>
namespace ised
{

class ised_win : public QMainWindow
{
    Q_OBJECT
    
public:
    enum PersonType
    {
        operator_=0,
        technician=1,
        engineer=2
    };

    // ctro & dtor

    ised_win(QWidget *parent = 0);
    ~ised_win();

    void calculateCountofWidgetsAsync();

public Q_SLOTS:
    void accept();//scp
    void onBtnPressed();

private:
    int calc();
private:
    int m_countOfWidgets;
    QWidget m_w;
    QLineEdit* m_edit;
    QVBoxLayout *vbox;

    QVBoxLayout* grid;
    QDialog* ndlg;
    QString m_session;
};
} // namespace ised

#endif // ISED_WIN_H
