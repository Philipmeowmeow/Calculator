#pragma once

#include <QMainWindow>
#include "Shell.h"
#include "Core.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
  
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Shell m_shell;
    Core m_core;
   
    
};
