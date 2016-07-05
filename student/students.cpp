#include "students.h"
#include"sortwindow.h"

QList<Students> Students::students;
Students::Students(){}
Students::Students(QString name, unsigned long long id){
    stuName = name;
    stuId = id;
    stuGpa = 0;
}

QList<Students>& Students::studentLists(void){
    return students;
}

QString Students::name(void) const{
    return stuName;
}
double Students::gpa(void){
    double count = 0, sum = 0;
    int courseCount = stuCourses.size();
    for(int i = 0; i < courseCount; i++){
        sum += stuCourses[i].value() * stuCourses[i].grade();
        count += stuCourses[i].value();
    }
    stuGpa = sum / count;
    if(count == 0)
        stuGpa = 0;
    return stuGpa;
}
QList<Course>& Students::courses(void){
    return stuCourses;
}
unsigned long long Students::id(void) const{
    return stuId;
}


bool Students::addCourse(QString courseName, int courseGrade){
    Course course = Course(courseName, courseGrade);
    if(stuCourses.contains(course))
        return false;
    stuCourses.push_back(course);
    return true;
}
int Students::courseCount(void) const{
    return stuCourses.size();
}
bool Students::deleteCourse(QString courseName){
    if(!stuCourses.contains(Course(courseName, 0)))
        return false;
    stuCourses.removeOne(Course(courseName, 0));
    return true;
}
bool Students::tookCourse(QString courseName) const{
    return stuCourses.contains(Course(courseName, 0));
}
void Students::updateStudentId(unsigned long long newId){
    stuId = newId;
}
void Students::updateName(QString newName){
    stuName = newName;
}
bool Students::updateGrade(QString courseName, int courseGrade){
    int ind = stuCourses.indexOf(Course(courseName, 0));
    if(ind == -1)
        return false;
    stuCourses[ind].updateCourseGrade(courseGrade);
    return true;
}
bool Students::operator==(const Students& other){
    return stuId == other.stuId;
}
bool operator<(const Students& one, const Students& other){
    return one.stuId > other.stuId;
}
int Students::grade(QString course) const{
    int ind = stuCourses.indexOf(Course(course, 0));
    Course c = stuCourses[ind];
    return c.grade();
}
bool comparel(const Students& one, const Students &other){
    QString course = SortWindow::compareColumn;
    return one.tookCourse(course) && other.tookCourse(course) && (one.grade(course) > other.grade(course));
}
bool compareGpa(const Students& one, const Students &other){
    return one.stuGpa > other.stuGpa;
}


/**
 * @brief Students::calculate Will calculate number of people having different grades.
 * @param column Name of the course or GPA
 * @return QList with 5 int, indecating number of people within 100-90, 89-79, ..., 59-0.
 */
QList<int> Students::calculate(QString column){
    QList<int> result;
    result << 0 << 0 << 0 << 0 << 0;
    for(int i = 0; i < students.size(); i++){
        if(column == "gpa"){
            if(students[i].gpa() >= 90)
                result[0]++;
            else if(students[i].gpa() >= 80)
                result[1]++;
            else if(students[i].gpa() >= 70)
                result[2]++;
            else if(students[i].gpa() >= 60)
                result[3]++;
            else
                result[4]++;
        }else{
            if(!students[i].tookCourse(column))
                continue;
            if(students[i].grade(column) >= 90)
                result[0]++;
            else if(students[i].grade(column) >= 80)
                result[1]++;
            else if(students[i].grade(column) >= 70)
                result[2]++;
            else if(students[i].grade(column) >= 60)
                result[3]++;
            else
                result[4]++;
        }
    }
    return result;
}

/**
 * @brief Students::addData Add data to the students. Same for following functions.
 * @param sid 学号
 * @param sname 姓名
 * @param cname 课程名
 * @param cgrade 成绩
 * @param cvalue 学分
 * @return true if action succeeds.
 */
bool Students::addData(unsigned long long sid, QString sname, QString cname, int cgrade, double cvalue){
    Students s(sname, sid);
    Course::addCourse(cname, cvalue);
    QList<Students> stmp = students;
    int ind = stmp.indexOf(s);
    if(ind < 0){
        s.addCourse(cname, cgrade);
        students.push_back(s);
    }else{
        if(stmp[ind].name() != sname){
            return false;
        }else{
            students[ind].addCourse(cname, cgrade);
        }
    }
    return true;
}

bool Students::updateData(unsigned long long sid, QString sname, QString cname, int cgrade, double cvalue){
    Students s(sname, sid);
    int i = students.indexOf(s);
    if(i >= 0){

        if(students[i].updateGrade(cname, cgrade)){
            students[i].updateName(sname);
            Course::updateCourseValue(cname, cvalue);
            return true;
        }
    }
    return false;
}

bool Students::deleteData(unsigned long long sid){
    return students.removeOne(Students("", sid));
}

bool Students::deleteData(unsigned long long sid, QString cname){
    int i = students.indexOf(Students("", sid));
    if(i >= 0){
        return students[i].deleteCourse(cname);
    }
    return false;
}
