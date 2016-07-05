#include "course.h"
#include<QMap>
#include<QString>
QMap<QString, double> Course::knownCourses;

Course::Course(){}
Course::Course(QString newCourseName, int newCoursesGrade){
    if(knownCourses.contains(newCourseName)){
        courseName = newCourseName;
        courseGrade = newCoursesGrade;
    }
}

bool Course::addCourse(QString name, double value){
    if(knownCourses.contains(name))
        return false;
    knownCourses.insert(name, value);
    return true;
}

bool Course::removeCourse(QString name){
    return knownCourses.remove(name);
}

bool Course::contains(QString name){
    return knownCourses.contains(name);
}

bool Course::updateCourseName(QString name, QString newName){
    if(!knownCourses.contains(name))
        return false;
    knownCourses.insert(newName, knownCourses[name]);
    knownCourses.remove(name);
    return true;
}

bool Course::updateCourseValue(QString name, double newValue){
    if(!knownCourses.contains(name))
    return false;
    knownCourses.insert(name, newValue);
    return true;
}

void Course::updateCourseGrade(int newGrade){
    courseGrade = newGrade;
}

QString Course::name(void) const{
    return courseName;
}

int Course::grade(void) const{
    return courseGrade;
}

double Course::value(void) const{
    return knownCourses[courseName];
}

bool Course::operator ==(const Course& other){
    return courseName == other.courseName;
}

int Course::totalCourseCount(void){
    return knownCourses.size();
}
QList<QString> Course::courses(void){
    return knownCourses.keys();
}
bool operator <(const Course& one, const Course& other){
    return one.name() < other.name();
}
