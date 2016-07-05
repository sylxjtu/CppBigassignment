#include "file.h"
#include<QIODevice>
#include<QTextStream>
#include<QMessageBox>

QString File::fileName;

File::File(){}

QString File::lastOpenedFile(void){
    return fileName;
}

/**
 * @brief File::readFile Obtain data from file
 * @param filename File to be opened
 * @return Data read from the file, or empty QList if failed
 */
QList<Students> File::readFile(QString filename){
    QList<Students> studentLists;
    QList<QString> courseLists;
    QFile f(filename);
    if(f.open(QFileDevice::ReadOnly | QIODevice::Text)){
        fileName = filename;
        QTextStream input(&f);
        input.setCodec("UTF-8");
        char ch;
        unsigned long long studentId;
        QString studentName;
        QString courseName;
        double courseValue;
        int courseGrade;
        while(!input.atEnd()){
            input >> ch;
            if("id:" == input.read(3)){
                input >> studentId;
            }else
                goto errorEncontered;
            if(" name:" != input.read(6))
                goto errorEncontered;
            input >> studentName;
            studentLists.push_back(Students(studentName, studentId));
            while(input.read(2) == " {"){
                if((input.atEnd()))
                    goto errorEncontered;
                input >> courseName;
                if((input.atEnd()))
                    goto errorEncontered;
                input >> courseValue;
                if((input.atEnd()))
                    goto errorEncontered;
                input >> courseGrade;
                if(!(input.read(1) == "}"))
                    goto errorEncontered;
                if(Course::addCourse(courseName, courseValue))
                    courseLists.push_back(courseName);
                studentLists[studentLists.size() - 1].addCourse(courseName, courseGrade);
            }//read courses
            continue;
errorEncontered:
            for(int i = 0; i < courseLists.size(); i++)
                Course::removeCourse(courseLists[i]);
            QList<Students> er;
            return er;
        }//read student data
        f.close();
        return studentLists;
    }
    f.close();
    return studentLists;
}

/**
 * @brief File::saveFile save studentLists to filename
 * @param filename File to be updated
 * @param studentLists Data
 */
void File::saveFile(QString filename, QList<Students>& studentLists){
    QFile f(filename);
    if(f.open(QFileDevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&f);
        for(int i = 0; i < studentLists.size(); i++){
            out << "$id:" << studentLists[i].id() << " name:" << studentLists[i].name();
            QList<Course> courses = studentLists[i].courses();
            for(int j = 0; j < courses.size(); j++){
                out << " {" << courses[j].name() << ' ' << courses[j].value() << ' ' << courses[j].grade() << "}";
            }
            out << "; ";
        }
        f.close();
    }
}
