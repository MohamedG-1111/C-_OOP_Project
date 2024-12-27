
#include <fstream>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define el "\n"
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int x;
bool fst=0;
bool ftc=0;
bool fco=0;
class Base{
private:
    int _ID;
    string _name;
public:
    Base(){}
    void setID(int ID){
        _ID=ID;
    }
    int getID(){
        return _ID;
    }
    void setName(string name){
        _name=name;
    }
    string getName(){
        return _name;
    }
    Base(int id,string name){
        _ID=id;
        _name=name;
    }
};
class person:public Base{
private:
    int _age;
    string _phoneNumber;
public:
    person(){}
    person(int  id,string name,int age,string phone):Base(id,name){
        _age=age;
        _phoneNumber=phone;
    }
    void setAge(int age){
        _age=age;
    }

    void setPhoneNumber(string phone){
        _phoneNumber=phone;
    }

    int getAge(){
        return _age;
    }

    string getPhoneNumber(){
        return _phoneNumber;
    }
    friend class teacher;
};
class teacher:public person{
private:
    double _salary;
    int studentsid[5];
public:
    teacher(){}

    teacher(int  iD,string name,int age,string phone,double salary)
            :person( iD, name,age,phone){
        _salary=salary;
    }
    void setstudentIDS(int studentid[5]){
        for(int i=0;i<5;i++)
            this->studentsid[i]=studentsid[i];
    }
    int *getsutdents(){
        return studentsid;
    }
    void setsalary(double salary){
        _salary=salary;
    }
    double getsalary(){
        return _salary;
    }
    static void ShowTeacher(teacher Teacher){
        cout<<"ID : "<<Teacher.getID()<<" "<<"Name : "<<Teacher.getName()<<" "<<"Age : "<<Teacher.getAge()<<" "<<"Phone : "<<Teacher.getPhoneNumber()
            <<" "<<"Salary : "<<Teacher.getsalary()<<"\n";

    }

};
class Courses:public Base{
private:
    double _hour;
    int studentIDS[5];
public:

    Courses(){}
    Courses(int ID,string name,double hour):Base(ID,name){
        _hour=hour;
    }
    void setstudentsIDS(  int studentIDS[5]) {
        for (int i = 0; i < 5; i++) {
            this->studentIDS[i] = studentIDS[i];
        }
    }
    int *getstudentIDS(){
        return studentIDS;
    }

    void sethour(double hour){
        _hour=hour;
    }
    double gethour(){
        return _hour;
    }
};
class Student:public person{
private:
    double _Gpa;
    teacher teachers[5];
    Courses courses[5];
public:

    Student(){}
    Student(int  iD,string name,int age,string phone,double gpa)
            :person(iD,name,age,phone){
        _Gpa=gpa;
    }

    Courses *setcourses(Courses courses[5]){
        for(int i=0;i<5;i++){
            this->courses[i]=courses[i];
        }
        return courses;
    }
    Courses *getcourses(){
        return courses;
    }
    void setTeacher(teacher teachers[5]){
        for(int i=0;i<5;i++){
            this->teachers[i]=teachers[i];
        }
    }
    teacher * getTeacher(){
        return teachers;
    }
    void setgpa(double Gpa){
        _Gpa=Gpa;
    }
    double getgpa(){
        return _Gpa;
    }
};
/////// Repository
class Data{
public:
    static vector<Student>Students;
    static int dd;
    static vector<Courses>course;
    static int cr;
    static vector<teacher>teachers;
    static long long ID_C;
};
vector<Student>Data::Students;
int Data::dd=221385;
vector<Courses>Data::course;
int Data::cr=100;
long long Data::ID_C=11123;

vector<teacher>Data::teachers;
///////////////  Repository  Student 

class studentRepo{
protected:
    static int number_student;

public:

    virtual   int addstudent(Student st)=0;
    virtual int getnumberofstudent()=0;
    virtual int remove(int ID)=0;
    virtual int editStudent(Student &student)=0;
};
int studentRepo ::number_student=0;
class StudentRepoImpl:public studentRepo{
protected:

    static int fins;
    int index_st;
    Data data;
public:
    int addstudent(Student st){
        st.setID(data.dd++);
        data.Students.push_back(st);
        return data.dd-1;
    }
    int editStudent(Student &student)  {
        for (int i = 0; i < Data::Students.size(); i++) {
            if (student.getID() == data. Students[i].getID()) {
                index_st = i;
                break;
            }
        }
        if (index_st == -1) return -1;
        else {
            data.Students[index_st]=student;
            return index_st;
        }

    }


    int remove(int ID) {
        for (int i = 0; i < Data::Students.size(); i++) {
            if (ID == data.Students[i].getID()){
                data.Students.erase(data.Students.begin() + i);
                fst=1;
            }
        }
 if(fst){
     fins=fst;
     fst=0;
     cout<<"Remove  student done  \n";
    return true;
 }
 else{
    cout<<"NOT found  or delete previosly \n";
     return false ;
 }

    }
    int getnumberofstudent() {
        number_student++;
        return number_student ;
    }
    static void print(){
        if(Data::Students.size()==0)
            cout<<"No students \n";
        else {
            for (int i = 0; i < Data::Students.size(); i++) {
                cout << " ID : " << Data::Students[i].getID() << " name :" << Data::Students[i].getName() << " age :"
                     <<Data::Students[i].getAge()
                     << " phone :" << Data::Students[i].getPhoneNumber() << " gpa :" <<float(Data::Students[i].getgpa()) << "\n";
            }
        }
    }
};
int StudentRepoImpl::fins=0;

//////// repository Courses \\\\\\\\\\\\\\\\\

class CourseRepo:public Courses{
protected:

    static int numberCourses;
public:
    virtual int addcourses(Courses course)=0;
    virtual  int getNumberofcourses()=0;
    virtual int RemoveCourse(int id)=0;
    virtual int EditCourse(Courses cours)=0;
};

class CourseRepoImp:public CourseRepo   {
protected:

    int indexte=-1;
        Data data;
public:
    int addcourses (Courses cour){
        cour.setID(data.cr++);
        data.course.push_back(cour);
        return data.cr-1;
    }
    int EditCourse(Courses cours){
        for(int i=0;i<Data::course.size();i++){
            if(cours.getID() == data.course[i].getID()){
                indexte=i;
                break ;
            }

            }
        if(indexte==-1) return -1;
        else
        {
            data.course[indexte]=  cours;
            return indexte;
        }
    }

    int RemoveCourse(int id){
        for(int i=0;i<Data::course.size();i++){
           if(id == data.course[i].getID()){
               Data::course.erase(Data::course.begin()+i);
               fco=1;
           }
        }
       if(fco){
        fco=0;
         cout<<"Removed done \n";
         return true ;
       }
      else
       {
         cout<<"NOT found \n ";
         return false ;
       }
    }
    int getNumberofcourses(){
        numberCourses++;
        return numberCourses;
    }
    static void ShowCourse(){
        for(int i=0;i<Data::course.size();i++){
            cout<<"ID : "<<Data::course[i].getID()<<" "<<"Name : "<<Data::course[i].getName()
            <<" "<<"Hour : "<<Data::course[i].gethour()<<" \n";
        }
    }
};

int CourseRepo:: numberCourses=0;



///////////////  Repository  Teacher

class teacherRepo{
protected:
    static int number_teacher;

public:
    virtual int addteacher(teacher Teacher)=0;
    virtual int getnumber_teacher()=0;
    virtual int RemoveTeacher(int id)=0;
    virtual int EditTeacher(teacher Teacher )=0;

};
class teacherRepoImpl:public teacherRepo{
protected:
    static int fintc;
    Data datat;
public:
    teacherRepoImpl(){}
    int addteacher(teacher Teachers){
        Teachers.setID(datat.ID_C++);
        datat. teachers.push_back(Teachers);
        return datat.ID_C-1;
    }
   int EditTeacher(teacher Teacher ){
        int indexte=-1;
       for(int i=0;i<datat.teachers.size();i++) {
           if (Teacher.getID() == datat.teachers[i].getID()) {
               indexte = i;
               break;
           }
       }
           if(indexte == -1) return -1;
           else{
               datat.teachers[indexte]=Teacher;
               return indexte;
           }
    }
    int  RemoveTeacher(int id){
        for(int i=0;i<datat.teachers.size();i++){
            if(id==datat.teachers[i].getID()){
                datat.teachers.erase(datat.teachers.begin()+i);
               ftc=1;
               break ;
            }
        }
       if(ftc==1)
       {
           fintc=ftc;
           ftc=0;
           cout<<"Remove done \n";
           return true;
       }
       else{
 cout<<"NOT found \n";
           return false;
       }

    }
    int  getnumber_teacher(){
        number_teacher++;
        return number_teacher;
    }
    static void ShowTeachers(){
        for(int i=0;i<Data::teachers.size();i++){
            cout<<"ID : "<<Data::teachers[i].getID()<<" "<<"Name : "<< Data::teachers[i].getName()<<" "<<"Age : "
            <<Data::teachers[i].getAge()<<" "
                <<"Phone : "<<Data::teachers[i].getPhoneNumber()<<" "<<" Salary "<<Data::teachers[i].getsalary()<<"\n";
        }
    }


};
int teacherRepo::number_teacher=0;
int teacherRepoImpl::fintc=0;


//////////// vaildation

////////////////////// vaildation Student 

class Studentvaildation{
public :
    int studentvaildatin(Student st){
        if (st.getName().size() > 100)
            cout << "Invailed name \n";
        else if (st.getAge() > 18) cout << "age must be lower than 18 \n";
        else if (st.getPhoneNumber().size() != 11) cout << "phone number must be  equal 11 numbers  \n";
        else if (st.getgpa() > 4 || st.getgpa() < 0) cout << "invailed GPA \n";
        else
            return 1;
        return -1;
    }
    int studentremove(int idr){
        if(idr<221385){
            cout<<"ID of students start up 221385 ";
            return false;
        }
        else
            return true;
    }
};

////////////////////// vaildation Teacher  

class Teachervaildation{
public:
    int Teachervaid(teacher Teachers){
        if (Teachers.getName().size() > 100)
            cout << "Invailed name \n";
        else if (Teachers.getAge() > 60 || Teachers.getAge()<30 ) cout << "age must be lower than 60 and more than 30  \n";
        else if (Teachers.getPhoneNumber().size() !=11) cout << "phone number must be  equal 11 numbers  \n";
        else if(Teachers.getsalary()<5000 || Teachers.getsalary()>15000  ) cout<<"invailed salary \n";
        else
            return 1;

        return -1;
    }
    int tacheridvaild(int id ){
        if(id <11123)
          return false;
        else
          return true;
    }

};

////////////////////// vaildation course  

class CourseVaild{
public:
    int coursevaild(Courses course){
        if(course.gethour()>5) cout<<"hour must be lower than 5 \n";
        else
            return 1;
        return -1;
    }
    int vaildid(int id){
        if(id <100 ){
            cout<<"ID startup 100 \n ";
            return false;
        }
        else
            return true;
    }

};


////////   Services

/////////////////////// ServicesStudent

class ServicesStudent: public StudentRepoImpl {
public:
    virtual  int AddStudent(Student student)=0;
    virtual  void showstudent(int ID)=0;
    virtual  int remove();
    virtual void editST(Student  &student);
};
class ServicesStudentImp:public ServicesStudent {
private:
    StudentRepoImpl studentt;
    Studentvaildation studentvaildation;
public:
    int AddStudent(Student st) {
        if(studentvaildation.studentvaildatin(st)==1)
            return studentt.addstudent(st);
        else
            return -1;
    }

    void  editST(Student  &student ){
        if(studentvaildation.studentvaildatin(student)==1){
            studentt.editStudent(student);
            cout<<"Succeed edit \n" ;
        }

        else
            cout<<"Student not found \n";
    }

    int remove(){
        cout<<"Enter student ID : ";  int id ;cin>>id;
        if(studentvaildation.studentremove(id)==1){
            studentt.remove(id);

            return true;
        }
        else{
            cout<<"Invailed value \n";
            return -1;
        }
    }
    void showstudent(int ID){
        bool found =0;
        int t=0;
        for(int i=0;i<Data::Students.size();i++) {
            if ((ID == Data::Students[i].getID())) {
                found = true;
                t = i;
            }
        }
        if(found==true){
            cout<<"Student is found \n";
            cout<<"IF you want see Date of Student Enter YES else Enter NO \n";
            string s; cin>>s;
                if(s=="YES"){
                    cout<<"ID : "<<Data::Students[t].getID()<<" "<<"name : "<<Data::Students[t].getName()<<" "
                        <<"Age : "<<Data::Students[t].getAge()<<" "<<"Phone : "<<Data::Students[t].getPhoneNumber()<<" "
                        <<"GPA : "<<Data::Students[t].getgpa()<<"\n";
                }
        }
        else
            cout<<"Student is not found \n";
    }

};

///////////////////////  ServiceTeacher  

class ServiceTeacher:public teacherRepoImpl {
public:
    virtual int addTeacher(teacher Teacher) = 0;
    virtual void showteacher(int ID)=0;
    virtual void editteacher(teacher Teacher)=0;
};

class ServicesTeacherImp : public ServiceTeacher {
private:
    teacherRepoImpl teacherr;
    Teachervaildation teachervai;
public:
    ServicesTeacherImp() {}
    void editteacher(teacher Teacher){
        int tt=teacherr.EditTeacher(Teacher);
        if(tt==-1) cout<<"not found \n";
        else
            cout<<"update successful \n";
    }
    int  addTeacher(teacher Teacher) {
        if(teachervai.Teachervaid(Teacher)==1)
            return teacherr.addteacher(Teacher);
        else
            return -1;
    }

    int remove_teacher(){
        cout<<"Enter ID of Teacher : ";
        int id ;cin>>id;
        if(teachervai.tacheridvaild(id)==1){
            teacherr.RemoveTeacher(id);
            return true;
        }
        else{
            cout<<"invailed value \n";
            return false ;
        }

    }
    void showteacher(int ID){
        bool found = 0 ;
        int tt=0;
        for(int i=0;i<Data::teachers.size();i++){
            if(ID==Data::teachers[i].getID()) {
                found=1;
                tt=i;
            }
        }
        if(found==1){
            cout<<"Teacher is Found \n";
            cout<<"IF you want see teacher Enter YES else Enter NO \n";
            string ss; cin>>ss;
            if(ss=="YES"){
                teacher::ShowTeacher(Data::teachers[tt]);
            }
        }
        else
            cout<<"NOT found \n";
    }
};

///////////////////////  CoursesService   /////////////////////////

class CoursesService: public CourseRepoImp {
public:
    virtual int addCourse(Courses course) = 0;
    virtual void show(int ID)=0;
    virtual void EditCO(Courses course)=0;
};

class CoursesServicesImp : public CoursesService {
private:
    CourseRepoImp courss;
    CourseVaild coursevaild;
public:

    int addCourse(Courses course) {
        if (coursevaild.coursevaild(course) == 1)
            return courss.addcourses(course);
        else
            return -1;
    }
    void EditCO(Courses course){
        int indeco=courss.EditCourse(course);
        if(indeco == -1) cout<<"Not found \n";
        else{
            cout<<"UPdate succeed \n";
        }
    }
int remove_course(int id){
       if(coursevaild.vaildid(id)==1){
           courss.RemoveCourse(id)  ;
           return true;
       }
       else
           return false;
    }
    void show(int ID) {
        bool found = 0;
        int cc;
        for (int i = 0; i < Data::course.size(); i++) {

            if (ID == data.course[i].getID()) {
                found = 1;
                cc = i;
                break;
            }
        }

        if (found == 1) {
            cout << "      Course IS Found \n";
            cout << "IF you want to see Course Enter YES else Enter NO \n";
            string sss;
            cin >> sss;
            if (sss == "YES")
                cout << "ID : " << data.course[cc].getID() << " " << "name : " << data.course[cc].getName()
                     << " " << "Hour of course : " << data.course[cc].gethour() << "\n";

        }
        else
            cout<<"    Course Not Found \n ";
    }
};


////////////// controller

//////////////////// StudentContrpller ////////////////

class StudentContrpller{
private:
    ServicesStudentImp servicesStudent;
public:
    int addStudent(Student student) {
        return servicesStudent.AddStudent(student);
    }
    void updateStudent(Student &student){
        servicesStudent.editStudent(student);
    }
    void showstudent(){
        int ID ; cin>>ID;
        servicesStudent.showstudent(ID);
    }
    void removestudent(){
        servicesStudent.remove();
    }

};

////////////////////  TeacherContrpller ////////////////

class TeacherContrpller {
private:
    ServicesTeacherImp serviceTeacher;
public:
    int addteacher(teacher &Teachers) {
        return serviceTeacher.addTeacher(Teachers);
    }
    void ShowTeacher(){
        cout<<"Enter ID of Teacher : ";int c; cin>>c;
        serviceTeacher.showteacher(c);
    }
    void Remove_teacher(){
        serviceTeacher.remove_teacher();
    }
    void updateTeacher(teacher Teacher){
        serviceTeacher.editteacher(Teacher);
    }
};


//////////////////// CoursesContrpller   ////////////////


class CoursesContrpller {
private:
    CoursesServicesImp serviccourses;
public:
    int addcourses(Courses courses) {
        return serviccourses.addCourse(courses);
    }
    void showCourse(){
        cout<<"Enter ID : ";int y; cin>>y;
        serviccourses.show(y);
    }
    void Removecourse(){
        cout<<"Enter ID : ";int y; cin>>y;
        serviccourses.remove_course(y);
    }
    void updatecourse( Courses courses){
        serviccourses.EditCO(courses);
    }
};

void showlist(string value) {
    cout << "\t\t******** " << value << " Management System **************** " << "\n";
    cout << "Choose what do you want \n";
    cout << "           1- Add " << value << "\t\t" << " 2- Remove  " << value << "\n";
    cout << "           3 - Edit " << value << "\t" << "     4 - Show  " << value << " by ID \n";
    cout<<"           5 - show all "<<value<<"  6 - Exist \n";

}

void displaypro() {
    cout << "\t\t********  Management System ********** " << "\n";
    cout << "Choose what do you want \n";
    cout << "             1 - about student " << "\t\t" << "    2 - about Courses " << "\n";
    cout << "             3 - about Teachers " << "\t\t" << "4 - Exist " << "\n";
}

//////// add ////////////////

void addstudent() {
    Student st;
    StudentContrpller studentContrpller;
    cout << "                  Enter Student Data  \n";
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    st.setName(name);
    int age;
    cout << "Enter age: ";
    cin >> age;
    st.setAge(age);
    string pho;
    cout << "Enter phone: ";
    cin >> pho;
    st.setPhoneNumber(pho);
    float  Gp;
    cout << "Enter GPA: ";
    cin >> Gp;
    st.setgpa(Gp);
    cin.ignore();
    int n= studentContrpller.addStudent(st);
    if(n!=-1){
        cout<<" added successed  and ID  is  :"<<n<<"\n";
    }
    else
        cout<<" Date is not correct , NOT added ! \n";
}
void addcourse() {
    Courses cou;
    CoursesContrpller coursescontrpller;
    cout << "          Enter Date of Course \n";
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    cou.setName(name);
    int hour;
    cout << "Enter hours of coures : ";
    cin >> hour;
    cou.sethour(hour);
    int m=coursescontrpller.addcourses(cou);
    if(m!=-1)
        cout << "added successed and ID : " << m << "\n";
    else
        cout<<"Date is not correct , NOT added ! \n";
}
void addteacher() {
    teacher te;
    TeacherContrpller teacherContrpller;
    cout << "              Enter teacher Data:\n";
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    te.setName(name);
    int age;
    cout << "Enter age: ";
    cin >> age;
    te.setAge(age);
    string pho;
    cout << "Enter phone: ";
    cin >> pho;
    te.setPhoneNumber(pho);
    cout << "Enter salary of teacher : ";
    int salary;
    cin >> salary;
    te.setsalary(salary);
    int b=teacherContrpller.addteacher(te);
    if(b!=-1){
        cout<<"teacher is added succeed and ID is : "<<b<<"\n";
    }
    else
        cout<<"Date is not correct ,NOT added \n";
}

///////////////////////////////// UPdate
void UPdate_Teacher(){
    teacher te;
    TeacherContrpller teacherContrpller;
    cout<<"Enter ID : "; int x; cin>>x;
    te.setID(x);

    cout << "              Enter teacher new Data:\n";
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    te.setName(name);
    int age;
    cout << "Enter age: ";
    cin >> age;
    te.setAge(age);
    string pho;
    cout << "Enter phone: ";
    cin >> pho;
    te.setPhoneNumber(pho);
    cout << "Enter salary of teacher : ";
    int salary;
    cin >> salary;
    te.setsalary(salary);
    teacherContrpller.updateTeacher(te);
}
void EditStudent(){
    Student st;
    StudentContrpller studentContrpller;
    cout<<"Enter ID that you want his Data  : ";
    int id; cin>>id ;
    cout << "                  Enter  new Student Data  \n";
    st.setID(id);
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    st.setName(name);
    int age;
    cout << "Enter age: ";
    cin >> age;
    st.setAge(age);

    float  Gp;
    cout << "Enter GPA: ";
    cin >> Gp;
    st.setgpa(float(Gp));

    string pho;
    cout << "Enter phone: ";
    cin >> pho;
    st.setPhoneNumber(pho);

    studentContrpller.updateStudent(st);
}
void EditCourse(){
    Courses cou;
    CoursesContrpller coursescontrpller;
    cout<<"Enter ID of course  : ";int id; cin>>id;

    cout << "          Enter Date of Course \n";
    cou.setID(id);
    cin.ignore();
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    cou.setName(name);
    int hour;
    cout << "Enter hours of coures : ";
    cin >> hour;
    cou.sethour(hour);
    coursescontrpller.updatecourse(cou);
}


















//////////////////////////     remove

void Removestudent(){
    StudentContrpller studentcontrpller;
    studentcontrpller.removestudent();
}
void Removeteacher(){
    TeacherContrpller tt;
    tt.Remove_teacher();
}
void REMOVE_COURSE(){
    CoursesContrpller  coursesContrpller;
    coursesContrpller.Removecourse();
}










//////// show //////////////////

void ShowStudent(){
    StudentContrpller studentContrpller;
    cout<<"Enter ID of student ";
    studentContrpller.showstudent();
}
void ShowTeacher(){
    TeacherContrpller teachercontrpller;
    teachercontrpller.ShowTeacher();
}
void Show(){
    CoursesContrpller coursesContrpller;
    coursesContrpller.showCourse();
}

////////////////// Switch ////


void Switchstudent(){
    switch (x) {
        case 1:
            addstudent();
            cout<<"       ------------    \n ";
            break;
        case 2:
            Removestudent();
            cout<<"       ------------    \n ";
            break;
        case 3 :
            EditStudent();
            cout<<"       ------------    \n ";
            break;

        case 4:
            ShowStudent();
            cout<<"       ------------    \n ";
            break ;
        case 5:
            StudentRepoImpl::print();
            cout<<"       ------------    \n ";
        case 6:
            break;
        default:
            cout << "Invailed value \n";
    }
}
void SwitchCoures(){
    switch (x) {
        case 1:
            addcourse();
            cout<<"       ------------    \n ";
            break;
        case 2:
            REMOVE_COURSE();
            cout<<"       ------------    \n ";
            break;
        case 3:
            EditCourse();
            cout<<"       ------------    \n ";
            break;
        case 4:
            Show();
            cout<<"       ------------    \n ";
            break ;
        case 5:
            CourseRepoImp::ShowCourse();
            cout<<"       ------------    \n ";
            break;
        case 6:
            break;
        default:
            cout << "Invailed value \n";
    }
}
void SwitchTeacher(){
    switch (x) {
        case 1:
            addteacher();
            cout<<"       ------------    \n ";
            break;
        case 2:
            Removeteacher();
            cout<<"       ------------    \n ";
            break;
        case 3:
            UPdate_Teacher();
            cout<<"       ------------    \n ";
            break;
        case 4:
            ShowTeacher();
            cout<<"       ------------    \n ";
            break ;
        case 5:
            teacherRepoImpl::ShowTeachers();
            cout<<"       ------------    \n ";
        case 6:
            break;
        default:
            cout << "Invailed value \n";
    }
}


 void school() {

    while (true) {
        bool b = 0;
        displaypro();
        cin >> x;
        switch (x) {
            case 1: {
                while(true){

                    showlist("student");
                    cin >> x;
                    Switchstudent();
                    if(x==6) break ;
                }
                break;
                case 2:
                    while(true){
                        showlist("Coures");
                        cin >> x;
                        SwitchCoures();
                        if(x==6) break;
                    }
                break;
                case 3:
                    while(true){
                        showlist("teacher");
                        cin >> x;
                        SwitchTeacher();
                        if(x==6) break ;
                    }
                break;

                case 4:
                    b = 1;
                cout << "Exist \n";
            }
        }
        if (b) break;
    }
}

int main() {
    school();
    return 0;
}


