#ifndef COURSE_H
#define COURSE_H
#include<QString>
#include<QMap>
class Course{
private:
    static QMap<QString, double> knownCourses;//QMap<课程名, 学分>
    QString courseName;
    int courseGrade;
public:
    Course();
    Course(QString newCourseName, int newCoursesGrade);
    static bool addCourse(QString name, double value);
    static bool removeCourse(QString name);
    static bool updateCourseName(QString name, QString newName);
    static bool updateCourseValue(QString name, double newValue);
    static bool contains(QString name);
    void updateCourseGrade(int newGrade);
    QString name(void) const;
    double value(void) const;
    int grade(void) const;
    bool operator ==(const Course& other);
    static int totalCourseCount(void);
    static QList<QString> courses(void);
    friend bool operator <(const Course& one, const Course& other);
};
bool operator <(const Course& one, const Course& other);
#endif // COURSE_H
