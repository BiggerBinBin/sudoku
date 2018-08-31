//sudoku 实现文件
//核心实现代码请参考：
//https://www.cnblogs.com/dancer16/p/6916795.html
#include "widget.h"
#include "ui_widget.h"
#include "QLineEdit"
#include <QDebug>
int num[9][9]={0};
bool sign = false;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(400,400);
    this->setMinimumSize(400,400);
    int i = 0;
    for(i=0; i<81; i++)
    {
        QLineEdit *bt=new QLineEdit(this);//注：最后一个参数一定为一个“父窗体”！
        bt->setGeometry((i%9)*10*3+20, i/9*10*3+40, 30, 30); //x、y是相对于“父窗体”的位置，可以自己验证
        QRegExp regx("[1-9]^\\d+$");
        QValidator *validator = new QRegExpValidator(regx, this);
        bt->setValidator(validator);
        if((i+1)%3==0)
            bt->setStyleSheet("border-left:1px,dashed #cecccc;border-style:outset;"
                              "border-top:1px,dashed #cecccc;border-style:outset;"
                              "border-right-width: 1px,dashed #000000;border-style:outset;"
                              "border-bottom: 1px;");

        else
            bt->setStyleSheet("border:1px,solid #000000;border-style:outset;");

        if(i>=18 && i<=26 || i>=45&&i<=53 || i>=72&&i<=80)
        {
            bt->setStyleSheet("border-left:1px,solid #cecccc;border-style:outset;"
                              "border-top:1px,solid #cecccc;border-style:outset;"
                              "border-right: 1px,solid #cecccc;border-style:outset;"
                              "border-bottom-width: 1px;");
            if((i+1)%3==0)
                bt->setStyleSheet("border-left:1px,solid #cecccc;border-style:outset;"
                                  "border-top:1px,solid #cecccc;border-style:outset;"
                                  "border-right-width: 1px,solid #000000;border-style:outset;"
                                  "border-bottom-width: 1px;");
        }

    }



  /*  QList <QLineEdit*> LineEdits = findChildren<QLineEdit *>();
    for(QList<QLineEdit*>::size_type i=0;i!=LineEdits.size();++i)
   {
       LineEdits.at(i)->setText(QString::number(i));
   }
   */
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_qiujie_button_clicked()                             //求解按钮的响应
{

    bool ok;
    sign = false;                                                   //状态重置，不重置会出BUG
    QString str;
    for(int i=0;i<81;i++)
        num[i/9][i%9]=0;
    QList <QLineEdit*> LineEdits = findChildren<QLineEdit *>();     //遍历控件，以获得用户输入的字符
    for(QList<QLineEdit*>::size_type i=0;i!=LineEdits.size();++i)
    {
        //int dec = str.toInt(&ok, 10);

        str=LineEdits.at(i)->text();                                //获取用户输入的字符
        num[int(i/9)][int(i%9)]=str.toInt(&ok,10);                  //把字符转换成整形数字
    }
    DFS(0);                                                         //求解
    for(QList<QLineEdit*>::size_type i=0;i!=LineEdits.size();++i)
    {
        LineEdits.at(i)->setText(QString::number(num[i/9][i%9]));   //输出答案
    }
}

bool Check(int n, int key)          //检查函数
{
    for (int i = 0; i < 9; i++)		//判断n在此行是否合法
    {
        int j = n / 9;
        if (num[j][i] == key)
            return false;
    }

    for (int i = 0; i < 9; i++)		//判断n所在竖是否合法
    {
        int j = n % 9;
        if (num[i][j] == key)
            return false;
    }

    int x = n / 9 / 3 * 3;			//x为n所在的小九宫格左顶点坚坐标
    int y = n % 9 / 3 * 3;			//y为n所在的小九宫格左顶点横坐标

    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (num[i][j] == key)
                return false;
        }
    }

    return true;					//全部合法
}

int DFS(int n)                      //求解
{
    if (n > 80)
    {
        sign = true;
        return 0;
    }

    if (num[n/9][n%9] != 0)
    {
        DFS(n+1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (Check(n, i) == true)
            {
                num[n / 9][n % 9] = i;
                DFS(n+1);
                if (sign == true)
                    return 0;
                num[n / 9][n % 9] = 0;
            }
        }
    }
}

void Widget::on_qiujie_button_2_clicked()   //重置函数
{
    QList <QLineEdit*> LineEdits = findChildren<QLineEdit *>();
    for(QList<QLineEdit*>::size_type i=0;i!=LineEdits.size();++i)
    {
         LineEdits.at(i)->clear();
    }
 }
