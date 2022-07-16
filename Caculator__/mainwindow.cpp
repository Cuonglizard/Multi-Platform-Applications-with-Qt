#include "mainwindow.h"
#include "ui_mainwindow.h"


double Memory=0.0;
double CalcVal=0.0;
bool divTrigger = false;
bool multTrigger=false;
bool addTrigger =false;
bool subTrigger =false;
bool BinaryTrigger =false;
bool binhphuongTrigger=false;
bool sodoiTrigger=false;
bool sqrtTrigger=false;
// dung de danh dau xem dang toan hoc nao da duoc chon

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // thiee lap space giao dien

    ui->Display->setText(QString::number(CalcVal)); //hien ra gia tri cua calcval
    QPushButton *numButtons[10];
    // gan signal
    for(int i = 0; i < 10; ++i){
           QString butName = "Button" + QString::number(i);

           // Get the buttons by name and add to array
           numButtons[i] = MainWindow::findChild<QPushButton *>(butName);

           // When the button is released call num_pressed()
           connect(numButtons[i], SIGNAL(released()), this,
                   SLOT(NumPressed()));
    }

    // connect Signal and slots for math buttons

       connect(ui->Add, SIGNAL(released()), this,
               SLOT(MathButtonPress()));
       connect(ui->Subtract, SIGNAL(released()), this,
               SLOT(MathButtonPress()));
       connect(ui->Multiply, SIGNAL(released()), this,
               SLOT(MathButtonPress()));
       connect(ui->Divide, SIGNAL(released()), this,
               SLOT(MathButtonPress()));
       connect(ui->Sodoi, SIGNAL(released()), this,
               SLOT(MathButtonPress()));
       connect(ui->sqrt, SIGNAL(released()), this,
               SLOT(MathButtonPress()));
       connect(ui->Muhai, SIGNAL(released()), this,
               SLOT(MathButtonPress()));

       // Connect equals button
       connect(ui->Equals, SIGNAL(released()), this,
               SLOT(EqualButtonPress()));

       // Connect change sign
       connect(ui->ChangeSign, SIGNAL(released()), this,
               SLOT(ChangeNumbersign()));
       connect(ui->Clear, SIGNAL(released()), this,
               SLOT(ClearButtonPress()));

}

 // destroy the MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){

    QPushButton *button =(QPushButton *)sender();

    QString butVal =button->text();

    // get the value in the display in Ui
    QString displayVal = ui->Display->text();

    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){

        // show on display the number pressed
            ui->Display->setText(butVal);
     }
    else{
        QString newVal = displayVal + butVal;

        double dblNewVal = newVal.toDouble();

        // set value in display  and allow up to 16 numbers

        ui->Display->setText(QString::number(dblNewVal, 'g', 16));

    }

}


void MainWindow::MathButtonPress(){

    // cancel aout previous math button
      divTrigger = false;
       multTrigger = false;
       addTrigger = false;
       subTrigger = false;
       binhphuongTrigger=false;
       sodoiTrigger=false;
       sqrtTrigger=false;

       QString displayVal = ui->Display->text();
        CalcVal = displayVal.toDouble();

        QPushButton *button = (QPushButton *)sender();

       // GET THE   SYMBOL on the button
        QString butVal = button->text();
        if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
               divTrigger = true;
           }
        else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
               multTrigger = true;
           }
        else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
               addTrigger = true;
           }
        else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0) {
               subTrigger = true;
           }
        else if(QString::compare(butVal, "1/x", Qt::CaseInsensitive) == 0) {
               sodoiTrigger = true;
           }
        else{
            binhphuongTrigger = true;
        }

        //clear text
        ui->Display->setText(" ");

}

void MainWindow::EqualButtonPress(){

    double solution = 0.0;

    // Get value in display
    QString displayVal = ui->Display->text();
       double dblDisplayVal = displayVal.toDouble();
     // make a math
       if(addTrigger || subTrigger || multTrigger || divTrigger||sodoiTrigger|| binhphuongTrigger ){
               if(addTrigger){
                   solution = CalcVal + dblDisplayVal;
               } else if(subTrigger){
                   solution = CalcVal - dblDisplayVal;
               } else if(multTrigger){
                   solution = CalcVal * dblDisplayVal;
               } else if(divTrigger){
                   solution = CalcVal / dblDisplayVal;
               } else if(sodoiTrigger){
                   if(dblDisplayVal==0.0)
                       return;
                   solution = 1 / CalcVal;
               }else {
                   solution = CalcVal * CalcVal;
               }
           }
       //show result in display

       ui->Display->setText(QString::number(solution));

}

void MainWindow::ChangeNumbersign(){
    // get value in display
    QString displayVal = ui->Display->text();

    QRegExp reg("[-+]?[0-9.]*");

    if(reg.exactMatch(displayVal)){
            double dblDisplayVal = displayVal.toDouble();
            double dblDisplayValSign = -1 * dblDisplayVal;
          // display the result
            ui->Display->setText(QString::number(dblDisplayValSign));

}
}

void MainWindow ::ClearButtonPress(){
    // Clear in the display
    divTrigger = false;
     multTrigger = false;
     addTrigger = false;
     subTrigger = false;
     binhphuongTrigger=false;
     sqrtTrigger=false;


     ui->Display->setText("0");
}

void MainWindow ::ANSButtonPress(){


    Memory = ui->Display->text().toDouble();

    CalcVal=Memory;
    ui->Display->setText(QString::number(CalcVal));
    /////
}
















