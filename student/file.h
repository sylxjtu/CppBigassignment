#ifndef FILE_H
#define FILE_H

#include<QFile>
#include<QFileDialog>
#include<QList>
#include"students.h"

class File{
private:
    static QString fileName; //Last opened file;
public:
    File();
    static QString lastOpenedFile(void);
    static QList<Students> readFile(QString filename);
    static void saveFile(QString filename, QList<Students>& studentList);
};

#endif // FILE_H
