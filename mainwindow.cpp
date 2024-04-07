#include "mainwindow.h"
#include "ui_mainwindow.h"
int value=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_switch_clicked()
{
    FILE *Sys_Handle=NULL;
    QString str=ui->pushButton_switch->text();
    if((Sys_Handle=fopen("/sys/class/gpio/gpio16/value","w"))!=NULL)
    {

        if(str=="ON")
        {
            ui->pushButton_switch->setText("OFF");
            ui->label_Status->setText("LED ON");
        }
        else {
            ui->pushButton_switch->setText("ON");
            ui->label_Status->setText("LED OFF");
        }

            value=value?0:1;
            char str_val[2];
            snprintf(str_val,(2*sizeof(char)),"%d",value);
            fwrite(str_val,sizeof(char),2,Sys_Handle);
            fclose(Sys_Handle);
    }
}
