#include "Core.h"

Core::Core(QObject *parent)
    : QObject{parent}
{
    reOpr.setPattern("[-+*/()=]");
   
    
}

void Core::getInput(QString _in)
{
    matchOpr = reOpr.match(_in);
    if(matchOpr.hasMatch()){
        ch =  matchOpr.captured().at(0); 
        if(!numBuffer.isEmpty())
        numStack.push(numBuffer.toDouble());
        calculate();
        numBuffer.clear();
        qDebug()<<numStack<<oprStack;
    }
    else{
        numBuffer += _in;
    }
}


double Core::getResult()
{
    return numStack.top();
}

int Core::checkPriority(QString _opr)
{
   
    if(_opr == "+" ||_opr == "-" )
        return 1;
    if(_opr == "*" ||_opr == "/" )
        return 2; 
    return 0;    
}

void Core::applyTop()
{
    if(numStack.size() > 1){
        const double num1 = numStack.pop();
        const double num2 = numStack.pop();
        const QString oprTop = oprStack.pop();
        if(oprTop == "+")
            numStack.push(num1+num2);
        if(oprTop == "-")
            numStack.push(num2-num1);
        if(oprTop == "*")
            numStack.push(num1*num2);
        if(oprTop == "/")
            numStack.push(num2/num1);
    }

}

void Core::calculate()
{
   
  if (ch == QChar('=')) {
        while (!oprStack.isEmpty() && oprStack.top() != QStringLiteral("("))
            applyTop();
        oprStack.clear();               
        return;                          
    }
    if (ch == QChar(')')) {
        while (!oprStack.isEmpty() && oprStack.top() != QStringLiteral("("))
            applyTop();
        if (!oprStack.isEmpty())
            oprStack.pop();              
        return;                           
    }
    if (ch == QChar('(')) {
        oprStack.push(QStringLiteral("("));
        return;
    }
    while (!oprStack.isEmpty()
           && oprStack.top() != QStringLiteral("(")
           && checkPriority(ch) < checkPriority(oprStack.top()))
        applyTop();

    if(numStack.size() <oprStack.size())
        oprStack.push(ch);
}
