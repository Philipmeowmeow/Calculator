#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    
{
    ui->setupUi(this);
    setWindowTitle("Calculator");
    setFixedSize(300,500);
    setCentralWidget(&m_shell);
    m_shell.Build();
    m_shell.setCore(&m_core);
}

MainWindow::~MainWindow()
{
    delete ui;
}
