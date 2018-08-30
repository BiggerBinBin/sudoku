#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
<<<<<<< HEAD

=======
>>>>>>> 修复了若干BUG
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
<<<<<<< HEAD
    ~Widget();
=======
     ~Widget();

>>>>>>> 修复了若干BUG

private slots:
    void on_qiujie_button_clicked();

    void on_qiujie_button_2_clicked();

private:
    Ui::Widget *ui;
    QLineEdit *cmdLineEdit;
<<<<<<< HEAD
};
=======

};

>>>>>>> 修复了若干BUG
bool Check(int n, int key);
int DFS(int n);
#endif // WIDGET_H
