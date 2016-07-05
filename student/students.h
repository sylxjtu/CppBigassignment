#ifndef STUDENTS_H
#define STUDENTS_H

#include<QString>
#include<QList>
#include"course.h"


class Students{
private:
    QString stuName;
    unsigned long long stuId;
    QList<Course> stuCourses;
    double stuGpa;
    static QList<Students> students;
public:
    Students();
    Students(QString name, unsigned long long id);
    bool tookCourse(QString courseName) const;
    QString name(void) const;
    unsigned long long id(void)  const;
    double gpa(void);
    QList<Course>& courses(void);
    bool addCourse(QString courseName, int courseGrade);
    bool deleteCourse(QString courseName);
    bool updateGrade(QString courseName, int courseGrade);
    void updateName(QString newName);
    void updateStudentId(unsigned long long newId);
    int courseCount(void) const;
    int grade(QString course) const;
    bool operator==(const Students& other);
    static QList<int> calculate(QString column);
    static QList<Students>& studentLists(void);
    static bool addData(unsigned long long sid, QString sname, QString cname, int cgrade, double cvalue);
    static bool updateData(unsigned long long sid, QString sname, QString cname, int cgrade, double cvalue);
    static bool deleteData(unsigned long long sid);
    static bool deleteData(unsigned long long sid, QString cname);
    friend bool operator<(const Students& one, const Students& other);
    friend bool comparel(const Students& one, const Students& other);
    friend bool compareGpa(const Students& one, const Students& other);
};

bool operator<(const Students& one, const Students& other);
bool comparel(const Students& one, const Students& other);
bool compareGpa(const Students& one, const Students& other);

#endif // STUDENTS_H
