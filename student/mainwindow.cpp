#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"file.h"
#include"course.h"
#include"msgdialog.h"
#include"sortwindow.h"
#include"chartwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<algorithm>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("成绩统计");
    refresh(ui->table);
    ui->table->show();
    connect(ui->Exit, SIGNAL(triggered()), this, SLOT(exitTriggered()));
    connect(ui->Open, SIGNAL(triggered()), this, SLOT(openTriggered()));
    connect(ui->Import, SIGNAL(triggered()), this, SLOT(importTriggered()));
    connect(ui->Save, SIGNAL(triggered()), this, SLOT(saveTriggered()));
    connect(ui->Upload, SIGNAL(triggered()), this, SLOT(saveasTriggered()));
    connect(ui->Add, SIGNAL(triggered()), this, SLOT(addTriggered()));
    connect(ui->RemoveCourse, SIGNAL(triggered()), this, SLOT(deleteCTriggered()));
    connect(ui->RemoveStudent, SIGNAL(triggered()), this, SLOT(deleteSTriggered()));
    connect(ui->Update, SIGNAL(triggered()), this, SLOT(updateTriggered()));
    connect(ui->KeyGPAD, SIGNAL(triggered()), this, SLOT(sortTriggeredD()));
    connect(ui->KeyGPAA, SIGNAL(triggered()), this, SLOT(sortTriggeredA()));
    connect(ui->KeyOthers, SIGNAL(triggered()), this, SLOT(sortKeyTriggered()));
    connect(ui->Charts, SIGNAL(triggered()), this, SLOT(chartTriggered()));
}

void MainWindow::exitTriggered(void){
    this->close();
}
void MainWindow::openTriggered(void){
    QString filename = QFileDialog::getOpenFileName(this, tr("打开"), "", tr("Allfile(*.*)"));
    if(filename == "")
        return;
    QList<Students> studentstmp = File::readFile(filename);
    if(studentstmp.size() == 0)
        QMessageBox::warning(this, tr("警告"), tr("文件格式错误"), QMessageBox::Ok);
    else
        Students::studentLists() = studentstmp;
    ui->table->close();
    refresh(ui->table);
    ui->table->show();
}
void MainWindow::importTriggered(void){
    QString filename = QFileDialog::getOpenFileName(this, tr("导入"), "", tr("Allfile(*.*)"));
    if(filename == "")
        return;
    QList<Students> studentstmp = File::readFile(filename);
    if(studentstmp.size() == 0)
        QMessageBox::warning(this, tr("警告"), tr("文件格式错误"), QMessageBox::Ok);
    Students::studentLists() += studentstmp;
    ui->table->close();
    refresh(ui->table);
    ui->table->show();
}
void MainWindow::saveTriggered(void){
    File::saveFile(File::lastOpenedFile(), Students::studentLists());
}
void MainWindow::saveasTriggered(void){
        QString filename = QFileDialog::getOpenFileName(this, tr("导出"), "", tr("Allfile(*.*)"));
        QFile f(filename);
        if(filename == "")
            return;
        f.open(QIODevice::WriteOnly);
        f.close();
        File::saveFile(filename, Students::studentLists());
}
void MainWindow::addTriggered(void){
    MsgDialog* addWindow = new MsgDialog(MsgDialog::add);
    addWindow->doExec();
    ui->table->close();
    refresh(ui->table);
    ui->table->show();
}
void MainWindow::updateTriggered(void){
    MsgDialog* updateWindow = new MsgDialog(MsgDialog::update);
    updateWindow->doExec();
    ui->table->close();
    refresh(ui->table);
    ui->table->show();
}
void MainWindow::deleteCTriggered(void){
    MsgDialog* removeWindow = new MsgDialog(MsgDialog::removeCourse);
    removeWindow->doExec();
    ui->table->close();
    refresh(ui->table);
    ui->table->show();
}
void MainWindow::deleteSTriggered(void){
    MsgDialog* removeWindow = new MsgDialog(MsgDialog::removeStudent);
    removeWindow->doExec();
    ui->table->close();
    refresh(ui->table);
    ui->table->show();
}
void MainWindow::sortTriggeredD(void){
    SortWindow::setCompareColumn("gpa");
    ui->table->close();
    refresh(ui->table, "gpa", false);
    ui->table->show();
}
void MainWindow::sortTriggeredA(void){
    SortWindow::setCompareColumn("gpa");
    ui->table->close();
    refresh(ui->table, "gpa", true);
    ui->table->show();
}
void MainWindow::sortKeyTriggered(void){
    SortWindow* s = new SortWindow;
    s->doExec();
    ui->table->close();
    refresh(ui->table, s->compareColumn, s->ascending());
    ui->table->show();
}
void MainWindow::chartTriggered(void){
    ChartWindow* c = new ChartWindow;
    c->show();
}

/**
 * @brief MainWindow::order Sort data in table
 * @param column Key word
 * @param asc asc or desc
 */
void MainWindow::order(QString column, bool asc){
    QMap<Students, int> studentField;
    for(int i = 0; i < Students::studentLists().size(); i++){
        if(studentField.contains(Students::studentLists()[i])){
            QList<Course> tmp = Students::studentLists()[i].courses();
            for(int j = 0; j < tmp.size(); j++)
                Students::studentLists()[studentField[Students::studentLists()[i]]].addCourse(tmp[j].name(), tmp[j].grade());
            Students::studentLists().removeAt(i--);
        }else
            studentField.insert(Students::studentLists()[i], i);
    }//check if we have a student in two rows;
    if(column == "sid")
        std::sort(Students::studentLists().begin(), Students::studentLists().end());
    else if(column == "gpa")
        std::sort(Students::studentLists().begin(), Students::studentLists().end(), compareGpa);
    else
        std::sort(Students::studentLists().begin(), Students::studentLists().end(), comparel);
    if(asc)
        for(int i = 0, j = Students::studentLists().size() - 1; i < j; Students::studentLists().swap(i++, j--));
}

/**
 * @brief MainWindow::refresh Refesh table
 * @param table
 * @param column Sorting keyword
 * @param asc asc or desc
 */
void MainWindow::refresh(QTableWidget *table, QString column, bool asc){
    order(column, asc);
    int stuCount = Students::studentLists().size();
    table->setRowCount(stuCount);
    QList<QString> courses = Course::courses();
    for(int i = 0; i < courses.size(); i++){
        bool in = false;
        for(int j = 0; (j < stuCount) && (!in); j++){
            in = Students::studentLists()[j].tookCourse(courses[i]);
        }
        if(!in)
            courses.removeAt(i--);
    }//delete useless courses
    QStringList Hheader, Vheader;
    Hheader << "学号" << "姓名";
    for(int i = 0; i < courses.size(); i++){
        Hheader << courses[i] << "学分";
    }
    Hheader << "GPA";
    for(int i = 0; i < stuCount; i++)
        Vheader << QString::number(i + 1);
    int corCount = courses.size() * 2 + 3;
    table->setColumnCount(corCount);
    table->setHorizontalHeaderLabels(Hheader);
    table->setVerticalHeaderLabels(Vheader);
    for(int i = 0; i < stuCount; i++){
        table->setItem(i, 0, new QTableWidgetItem(QString::number(Students::studentLists()[i].id())));
        table->setItem(i, 1, new QTableWidgetItem(Students::studentLists()[i].name()));
        QList<Course> course = Students::studentLists()[i].courses();
        for(int j = 0; j < courses.size(); j++){
            int ind = course.indexOf(Course(courses[j], 0));
            if(ind == -1){
                table->setItem(i, 2 + j * 2, new QTableWidgetItem(QString("")));
                table->setItem(i, 3 + j * 2, new QTableWidgetItem(QString("")));
            }else{
                table->setItem(i, 2 + j * 2, new QTableWidgetItem(QString::number(course[ind].grade())));
                table->setItem(i, 3 + j * 2, new QTableWidgetItem(QString::number(course[ind].value(), 'g',2)));
            }
        }
        table->setItem(i, corCount - 1, new QTableWidgetItem(QString::number(Students::studentLists()[i].gpa(), 'g',2)));       
    }
}

MainWindow::~MainWindow(){
    delete ui;
}
