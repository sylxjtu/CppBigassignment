#include "msgdialog.h"
#include "ui_msgdialog.h"
#include<QString>
#include<QLabel>
#include<QMessageBox>
#include"mainwindow.h"

MsgDialog::MsgDialog(method me, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MsgDialog),
    m(me){
    ui->setupUi(this);
    static QMap<MsgDialog::method, QString> fields;
    fields.insert(MsgDialog::add, "添加");
    fields.insert(MsgDialog::removeCourse, "删除课程记录");
    fields.insert(MsgDialog::removeStudent, "删除学生记录");
    fields.insert(MsgDialog::update, "修改记录");
    this->setWindowTitle(fields[me]);
    inLoop = false;
}


MsgDialog::~MsgDialog(){
    delete ui;
}

void MsgDialog::doExec(void){
    inLoop = true;
    this->show();
    loop.exec();
}


void MsgDialog::on_buttonBox_clicked(QAbstractButton *button){
    if(ui->buttonBox->standardButton(button) != QDialogButtonBox::Cancel){
        unsigned long long sid = ui->sidInput->text().toULongLong();
        QString sname = ui->nameInput->text();
        QString cname = ui->courseInput->text();
        int cgrade = ui->scoreInput->text().toInt();
        double cvalue = ui->valueInput->text().toDouble();
        if((m == MsgDialog::add) && (Students::addData(sid, sname, cname, cgrade, cvalue))){
            goto ret;
        }else if((m == MsgDialog::update) && (Students::updateData(sid, sname, cname, cgrade, cvalue))){
            goto ret;
        }else if((m == MsgDialog::removeCourse) && (Students::deleteData(sid, cname))){
            goto ret;
        }else if((m == MsgDialog::removeStudent) && (Students::deleteData(sid))){
            goto ret;
        }
        QMessageBox::warning(this, tr("警告"), tr("录入信息不匹配"), QMessageBox::Ok);
    }
ret:
    if(inLoop){
        inLoop = false;
        loop.quit();
    }
    this->close();
}
