#pragma once
#include <QObject>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QRegularExpression>
#include <QStack>
#include <QChar>
class Core: public QObject
{
    Q_OBJECT
public:
    explicit Core(QObject *parent = nullptr);
    void getInput(QString _in);
    double getResult();
private:
    int checkPriority(QString _opr);
    QStack<double> numStack; 
    QStack<QString> oprStack;
    QString ch;
    QRegularExpression reOpr;
    QRegularExpressionMatch matchOpr;
    void applyTop();
    void calculate();
    QString numBuffer;
signals:
    void sentResult(QString _result);
};
