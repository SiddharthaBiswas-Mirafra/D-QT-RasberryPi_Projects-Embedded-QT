#include<cstdio>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FILE *Sys_Handle=NULL;
    if((Sys_Handle=fopen("/sys/class/gpio/export","w"))!=NULL)
    {
            fwrite("3",sizeof(char),2,Sys_Handle);
            fclose(Sys_Handle);
    }
    if((Sys_Handle=fopen("/sys/class/gpio/gpio16/direction","w"))!=NULL)
    {
        fwrite("out",sizeof(char),4,Sys_Handle);
        fclose(Sys_Handle);
    }
    MainWindow w;
    w.show();

    return a.exec();
}
