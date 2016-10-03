//mainwindow.h


#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineEdit>
#include <QMainWindow>

//QTextEdit类声明
class QTextEdit;

//定义 MainWow 类, 该类继承在QMainWindow
class MainWindow : public QMainWindow
{
    //因为QMainWind继承于Qobject, 因此该出也应声明该宏定义.只有加入该宏, 才能使用QT中的signal 和 slot机制
    Q_OBJECT

public:
    //exlicit关键字表明该构造函数必须显示调用.
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//创建信号槽
private slots:
    void openFile();
    void saveFile();
   // void helpFile();
    void open();
private:


    QLineEdit *usrLineEdit;

    QLineEdit *pwdLineEdit;
    //创建动作
    QAction *openAction;
    QAction *saveAction;
    QAction *helpAction;

    //文本组件
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
