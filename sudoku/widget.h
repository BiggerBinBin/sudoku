#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
     ~Widget();


private slots:
    void on_qiujie_button_clicked();

    void on_qiujie_button_2_clicked();

private:
    Ui::Widget *ui;
    QLineEdit *cmdLineEdit;

};


bool Check(int n, int key);
int DFS(int n);
#endif // WIDGET_H
