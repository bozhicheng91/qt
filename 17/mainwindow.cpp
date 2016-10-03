//mainwindow.cpp

#include <QtGui>
#include <QtWidgets>
#include "mainwindow.h"

//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //设置打开文件函数相关功能

    openAction = new QAction(QIcon(":/images/file-open.png"), tr("&Open..."), this);
    //添加快捷键
    openAction->setShortcuts(QKeySequence::Open);
    //添加状态栏提示语
    openAction->setStatusTip(tr("Open an existing file"));
    //为openAction对象添加响应动作
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    //设置保存文件函数相关功能
    saveAction = new QAction(QIcon(":/images/file-save.png"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    //为saveAction对象添加响应动作
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    //设置helpAction相关设置
    helpAction = new QAction(QIcon(":/images/help.png"), tr("&Help..."), this);
    helpAction->setShortcuts(QKeySequence::HelpContents);
    helpAction->setStatusTip(tr("Look for help"));
    //为saveAction对象添加响应动作
    connect(helpAction, &QAction::triggered, this, &MainWindow::open);


    //在菜单栏添加File按钮
    QMenu *file = menuBar()->addMenu(tr("&文件"));
    //在File按钮下添加功能键,openAction和saveAction
    file->addAction(openAction);
    file->addAction(saveAction);
    file->addAction(helpAction);

    //在工具栏添加两个动作
    QToolBar *toolBar = addToolBar(tr("&文件夹"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(helpAction);




    //QTextEdit类用于显示富文本文件
    textEdit = new QTextEdit(this);
    //该函数用于设置textEdit为窗口的中心组件
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openFile()
{
    //获取打开文件的路径,该函数的所有参数都是可选的.
    /*
    */
    QString path = QFileDialog::getOpenFileName(
                    this,                     //父窗口.qt标准对话框提供静态函数, 用于返回一个静态对话框
                    tr("Open File"),         //对话框标题
                    ".",                     //对话框打开时默认目录,"."代表当前目录."/"代表当前盘符的根目录.
                    tr("Text Files(*.txt)")  //过滤器,设定打开某种特定类型的文件
                    );
    if(!path.isEmpty()) {
        //创建QFile对象, 用于打开path路径的文件
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }
        //读取文件
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Write File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }
}

void MainWindow::open()
{

    //实例化一个dialog类
    QDialog dialog;
    //设置窗口的标题
    dialog.setWindowTitle(tr("this is help context!!"));
    //设置窗口的大小
    dialog.resize(300,100);


    dialog.exec();
}
