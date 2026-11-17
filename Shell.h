#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <Qlabel>
#include <QButtonGroup>
#include <QList>
#include <QString>
#include "Core.h"
class Shell: public QWidget
{
    Q_OBJECT

public:
    explicit Shell(QWidget *parent = nullptr);
    void Build();
    void setCore(Core *_core);
    
private:
    QGridLayout *m_grid;
    QList<QPushButton*> m_btns;
    QButtonGroup *m_btnGrp;
    QBoxLayout *m_box;
    QLineEdit *m_lE;
    Core * m_core;
signals:
    void sendInput(QString _out);
};
