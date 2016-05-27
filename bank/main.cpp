#include "mainwindow.h"
#include <QApplication>
<<<<<<< Updated upstream

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
=======
int main(int argc, char* argv[]){
    QApplication a(argc,argv);
>>>>>>> Stashed changes
    MainWindow w;
    w.show();

    return a.exec();
}
