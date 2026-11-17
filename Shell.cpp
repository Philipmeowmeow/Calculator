#include "Shell.h"

Shell::Shell(QWidget *parent)
    : QWidget{parent}
{   

    m_box = new QVBoxLayout(this);
    m_grid = new QGridLayout(this);
    m_btnGrp = new QButtonGroup(this);
    setLayout(m_box);
    
  
    m_lE = new QLineEdit();
    
}

void Shell::Build()
{
    static int k = 1;
    m_box->addWidget(m_lE);
    m_box->addLayout(m_grid);
    m_btns.append(new QPushButton("0"));m_grid->addWidget
    (m_btns.at(0),4,1,1,1);
    while(k < 10)
    {
        m_btns.append(new QPushButton(QString::number(k++)));
    } 
    k = 1;
    for(size_t i = 3;i > 0;i--)
    {  
        for (size_t j = 0; j < 3; j++)
        {     
            if(k < 10)
            m_grid->addWidget(m_btns.at(k++),i,j,1,1);
            else
            break;
        }  
    }
    m_btns.append(new QPushButton("删除"));m_grid->addWidget
    (m_btns.at(10),0,1,1,1);
    m_btns.append(new QPushButton("清除"));m_grid->addWidget
    (m_btns.at(11),0,0,1,1);
    m_btns.append(new QPushButton("+"));m_grid->addWidget
    (m_btns.at(12),1,3,1,1);
    m_btns.append(new QPushButton("-"));m_grid->addWidget
    (m_btns.at(13),2,3,1,1);
    m_btns.append(new QPushButton("*"));m_grid->addWidget
    (m_btns.at(14),3,3,1,1);
    m_btns.append(new QPushButton("/"));m_grid->addWidget
    (m_btns.at(15),4,3,1,1);
    m_btns.append(new QPushButton("."));m_grid->addWidget
    (m_btns.at(16),4,0,1,1);
    m_btns.append(new QPushButton("="));m_grid->addWidget
    (m_btns.at(17),4,2,1,1);
    m_btns.append(new QPushButton("("));m_grid->addWidget
    (m_btns.at(18),0,2,1,1); 
    m_btns.append(new QPushButton(")"));m_grid->addWidget
    (m_btns.at(19),0,3,1,1);
    for(size_t i = 0; i < m_btns.size();i++ )
    {
        m_btns.at(i)->setMinimumSize(36,36);
        m_btns.at(i)->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        m_btnGrp->addButton(m_btns[i],i); 
    }
    m_lE->setMaximumSize(300,78);
    m_lE->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QFont tmp = m_lE->font();
    tmp.setPointSize(16);
    m_lE->setFont(tmp);
    
    connect(m_btnGrp,&QButtonGroup::idClicked,this,[this](int digit){
        emit  sendInput(m_btns[digit]->text());
        if(digit!=10&&digit!=11){
            m_lE->insert( m_btns[digit]->text());
        }
        if(digit==17)
        {
            
            m_lE->clear();
           m_lE->setText(QString::number(m_core->getResult()));
        }
            
    });
}



void Shell::setCore(Core *_core)
{
    m_core = _core;
    connect(this,&Shell::sendInput,m_core,&Core::getInput);
}
