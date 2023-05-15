#include <iostream>
#include <string>

using namespace std;
// Student structure
struct Student {
    string name;
    int rollNo;
    string course, code;
    int semester;
    float marks;

    enum department {
        AI, CS, DS, EE,
    };
}students[100];

// Function to add a student record
void addStudent(Student* students, int& count) {
    cout << "ADD A STUDENT TO SYSTEM..\n";
    cout << "Enter student name: ";
    cin >> students[count].name;
    cout << "Enter roll number: ";
    cin >> students[count].rollNo;
    cin.ignore(); // Ignore newline character in input buffer
    cout << "Enter course name: ";
    getline(cin, students[count].course);
    cout << "Enter semester: ";
    cin >> students[count].semester;
    cout << "Enter marks: ";
    cin >> students[count].marks;
    count++;
    cout << endl;
}

// Function to remove a student record
void removeStudent(Student* students, int& count) {
    cout << "REMOVE A STUDENT FROM SYSTEM..\n";
    cout << "Enter the roll number of the student you want to remove: ";
    int rollNumber;
    cin >> rollNumber;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNumber) {
            found = true;
            // Shift all elements after the removed student back by one position
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            break;
        }
    }

    if (found) {
        cout << "Student with roll number " << rollNumber << " has been removed from the system.\n";
    }
    else {
        cout << "Student with roll number " << rollNumber << " not found in the system.\n";
    }
}
// Function to view all students added

void viewStudent(Student* students, int& count) {
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        if ((students + i)->rollNo == 0)
        {
            continue;
        }
        else {
            cout << "Name :" << students[i].name << endl;
            cout << "Roll No :" << students[i].rollNo << endl;
        }
    }

}

// Teacher structure
struct Teacher {
    string name;
    int id;
}teachers[20];

// Function to add a teacher record
void addTeacher(Teacher* teachers, int& count) {
    cout << "ADD A TEACHER TO SYSTEM......" << endl;
    cout << "Enter name of teacher : " << endl;
    cin >> teachers[count].name;
    cout << "Enter id of teacher : " << endl;
    cin >> teachers[count].id;
    count++;
}

// Function to remove a teacher record
void removeTeacher(Teacher* teachers, int& count, int teacherId) {
    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (teachers[i].id == teacherId) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        cout << "Teacher with ID " << teacherId << " not found in system." << endl;
        return;
    }
    for (int i = foundIndex; i < count - 1; i++) {
        teachers[i] = teachers[i + 1];
    }
    count--;
    cout << "Teacher with ID " << teacherId << " removed from system." << endl;
}

// Function to view teachers record
void viewTeachers(Teacher* teachers, int& count) {
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        if ((teachers + i)->id == 0)
        {
            continue;
        }
        else {
            cout << "Name :" << teachers[i].name << endl;
            cout << "Roll No :" << teachers[i].id << endl;
        }
    }
}

// New Course structure
struct newCourse {
    string courseName;
    string courseCode;
}course;
// function to allocate courses to teacher
void allocateCourse(Teacher* teachers, newCourse& course) {
    cout << "Enter teacher name: ";
    cin>>teachers->name;
    cout << "Enter teacher ID: ";
    cin >>teachers->id;

    cout << "Enter course name: ";
    cin >>course.courseName;
    cout << "Enter course code: ";
    cin >> course.courseCode;

    cout << "Course " << course.courseName << " (" << course.courseCode << ") has been allocated to " << teachers->name << " (" << teachers->id << ")." << endl;
}
// function to de allocate course from teacher
void deAllocateCourse(Teacher* teachers, newCourse& course) {
cout << "Deallocating course " << course.courseName << " (" << course.courseCode << ") from " << teachers->name << " (" << teachers->id << ")." << endl;
// Remove the course from the teacher's list of courses
string code;
cout<<"Enter the course code you want to de-allocate\n";
cin>>code;
if (code==course.courseCode)
{
    cout<<"This course has been de- allocated\n";
}
else
    cout<<"Course not found\n";

}
// Function to add a new course to system
void addCourse(newCourse course[], int& count) {
    cout << "ADD A NEW COURSE TO SYSTEM...." << endl;
    cout << "Enter name of course : " << endl;
    cin >> course[count].courseName;
    cout << "Enter code of course : " << endl;
    cin >> course[count].courseName;
    count++;
}

// Function to remove a course from system
void removeCourse(newCourse course[], int& count) {
    cout << "REMOVE A COURSE FROM SYSTEM...." << endl;
    // if (count == 0) {
    //     cout << "No courses to remove." << endl;
    //     return;
    // }
    cout << "Enter the code of the course to remove: " << endl;
    string codeToRemove;
    cin >> codeToRemove;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (course[i].courseCode == codeToRemove) {
            found = true;
            for (int j = i; j < count - 1; j++) {
                course[j] = course[j + 1];
            }
            count--;
            cout << "Course removed from the system." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Course with code " << codeToRemove << " not found in the system." << endl;
    }
}


// Admin structure
struct Admin {
    string name;
    int salary;
};

// Login function
int login() {
    int userType;
    int b;
    cout << "                   *************************WELCOME TO LMS SYSTEM*************************\n";
    cout << "                   ***********************************************************************\n";
    cout << "                   ***********************************************************************\n";
    cout << "                   ***********************************************************************\n";
    cout << endl << endl;
    // Prompt user to select user type
    cout << "Please select user type:\n";
    cout << "1. Student\n";
    cout << "2. Teacher\n";
    cout << "3. Admin\n";
    cout << "Enter your choice: ";
    cin >> userType;

    // Validate user input
    while (userType < 1 || userType > 3) {
        cout << "Invalid choice. Please try again.\n";
        cout << "Enter your choice: ";
        cin >> userType;
    }

    return userType;

}

// Student login function
void studentLogin()
{
    int a;
    cout << "                        *******************WELCOME TO STUDENT PORTAL*************************\n";
    cout << "                     *****************************************************************************\n";
    cout << "                  ***********************************************************************************\n";
    cout << endl << endl;
    do {
        Student student;
        int department, n;
        cout << " 1 . Update personal details \n";
        cout << " 2 . Enroll a new course to your degree\n";
        cout << " 3 . See the list of all the courses\n";
        cout << " 4 . See the list of his/her teachers\n";
        cout << " 5.  See list of courses he has enrolled in\n";
        cout << " 6.  See list of the dropped courses\n";
        cout << "Enter your choice: ";
        cin >> n;
        while (n < 1 || n > 6) {
            cout << "Invalid choice. Please try again.\n";
            cout << "Enter your choice: ";
            cin >> n;
        }
        int x;
        if (n == 1)
        {
            // do {

            // Display student personal information
            cout << "Enter your name: ";
            cin >> student.name;
            cout << "Enter your roll number: ";
            cin >> student.rollNo;
            cout << "Enter your faculty in terms of integers from 0 to 3 : " << endl;
            cin >> department;
            cout << "Student Information\n";
            cout << "Name: " << student.name << endl;
            cout << "Roll No: " << student.rollNo << endl;
            if (department == student.AI)
            {
                cout << "Faculty: Artifcial intelligence\n";
            }
            else if (department == student.CS)
            {
                cout << "Faculty: Computer science\n";
            }
            else if (department == student.DS)
            {
                cout << "Faculty: Data Science\n";
            }
            else if (department == student.EE)
            {
                cout << "Faculty: Electrical engineering\n";
            }
            else {
                cout << "Invalid faculty\n";
            }
            // cout<<"Press 0 to go back :";
            // cin>>x;
        // }while(x);

        }
        //  courses information
        else if (n == 2)
        {
            // do{
            cout << "Enter the course : ";
            cin >> student.course;
            cout << "Enter marks for that course " << ": ";
            cin >> student.marks;
            cout << "Courses: " << student.course << endl;
            cout << "Marks: " << student.marks << endl;
            // cout<<"Press 0 to go back :";
            // cin>>x;
            // }while(x);
        }
        else if (n == 3)
        {

            // do{
            cout << "The available cousres are :\n";
            cout << "MT-102\n";
            cout << "CS-112\n";
            cout << "MM-101\n";
            cout << "HM-102\n";
            cout << "IF-102\n";
            cout << "ES-111\n";
            cout << "CS-112-lab\n";
            cout << "MM-141-lab\n";
            // cout<<"Press 0 to go back :";
            // cin>>x;
        // }while(x);
        }
        else if (n == 4)
        {
            // do{
            cout << "The teachers are : \n";
            cout << "Qasim Riaz \n";
            cout << "Minhaj Zaheer\n";
            cout << "Shanzay Rehman\n";
            cout << "Hira Ahad\n";
            cout << "Amna Arooj\n";
            cout << "Zahid Iqbal\n";
            //     cout<<"Press 0 to go back :";
            //     cin>>x;
            // }while(x);
        }
         else if (n == 5)
        {
            do{
            
            if (student.course == "MT101")
            {   
                cout << "The courses he/she has enrolled in are : \n";
                cout<<"MT101\n";
            }
            else
            {   cout<<"No courses are enrolled.\n";}
            
                cout<<"Press 0 to go back :";
                cin>>x;
            }while(x);
        }
         else if (n == 6)
        {
            do{
            
            if (student.course == "MT101")
            {   
                cout << "The dropped courses are : \n";
                cout<<"MT101\n";
            }
            else
            {   cout<<"No courses are dropped.\n";}
            
                cout<<"Press 0 to go back :";
                cin>>x;
            }while(x);
        }

        cout<<endl<<endl<<endl;
        cout << "\t\t'Press 1 to see the student menu'  :\n";
        cout << "\t\t'Press 0 to exit':\n";
        cout<<"\t\t";
        cin >> a;
    } while (a);



}

// Teacher login function
void teacherLogin() {
    cout << "                        *******************WELCOME TO TEACHER CONTROL*************************\n";
    cout << "                     *****************************************************************************\n";
    cout << "                  ***********************************************************************************\n";
    cout << endl << endl;
    int a, n;
    do 
        { 
    cout<<endl<<endl<<endl;
    cout<<"Teacher's contol system..................\n";
    cout<<"1. Update personal details\n";
    cout<<"2. See list of courses allocated to him\n";
     cout << "Enter your choice: ";
        cin >> n;
        while (n < 1 || n > 6) 
                                {
            cout << "Invalid choice. Please try again.\n";
            cout << "Enter your choice: ";
            cin >> n;
                                }  

        
        int x;
        if (n == 1)
        {   
            do{
                Teacher teacher;
                cout << "Enter your name: ";
                cin >> teacher.name;
                cout << "Enter your ID: ";
                cin >> teacher.id;

                // Display teacher information
                cout << "Teacher Information\n";
                cout << "Name: " << teacher.name << endl;
                cout << "ID: " << teacher.id << endl;
                cout<<"Press 0 to go back :";
                cin>>x;
            }while(x);
        }   
        else if(n == 2){
            do{
                cout<<"No courses are allocated \n";
                cout<<"Press 0 to go back :";
                cin>>x;
            }while(x);

        }
        cout<<endl<<endl;
        cout << "\t\t'Press 1 to see the teacher control system'  :\n";
        cout << "\t\t'Press 0 to exit':\n";
        cout<<"\t\t";
        cin >> a;
    } while (a);
}

// Admin login function
void adminLogin()
{
    int a;

    cout << "                            *********************WELCOME TO ADMIN CONTROL SYSTEM*********************\n      ";
    cout << "                    *****************************************************************************\n    ";

    cout << endl << endl;
    cout << "You have the given options here as an admin :" << endl;
    int userType;
    // Prompt user to select user type

    do
    {
        // const int MAX_STUDENTS = 100;
                // Student students[100];
        int count = 0;
        int choice;
        cout << "Please select user type:\n";
        cout << "1. Update your information\n";
        cout << "2. Add a teacher to the system\n";
        cout << "3. Add a student to the system\n";
        cout << "4. Add a new course to the system\n";
        cout << "5. Remove a student from the system\n";
        cout << "6. Remove a teacher from the system\n";
        cout << "7. Remove a course from the system\n";
        cout << "8. View all the students in the system\n";
        cout << "9. View all the teachers in the system\n";
        cout << "10. Allocate a course to teacher \n";
        cout << "11. De-Allocate a course from teacher\n";
        cout << "Enter your choice: ";
        cin >> userType;


        // Validate user input
        while (userType < 1 || userType > 11)
        {
            cout << "Invalid choice. Please try again.\n";
            cout << "Enter your choice: ";
            cin >> userType;
        }
        int x;
        // Admin controls 
        if (userType == 1)
        {
            do {
                Admin admin;
                cout << "Enter your name: ";
                cin >> admin.name;
                cout << "Enter your Salary: ";
                cin >> admin.salary;
                // Display admin information
                cout << "Admin Information\n";
                cout << "Name: " << admin.name << endl;
                cout << "Salary: " << admin.salary << endl;
                cout << "\tPress 1 to continue adding second admin details\n";
                cout << "\tPress 0 to go back....\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 2)
        {
            do {
                int count = 0;
                //    const int MAX_TEACHERS = 100;
                //    Teacher teachers[MAX_TEACHERS];
                addTeacher(teachers, count);
                cout << "\tPress 1 to continue adding teachers\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 3)
        {
            do {
                //    int count = 0;
                //    int choice;
                //    const int MAX_STUDENTS = 100;
                //    Student students[MAX_STUDENTS];
                addStudent(students, count);
                cout << "\tPress 1 to continue adding students\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 4) {
            do {
                int count = 0;
                int choice;
                const int Newcourse = 100;
                newCourse course[Newcourse];
                addCourse(course, count);
                cout << "\tPress 1 to continue adding courses\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 5)
        {
            do {
                // int count = 0;
                // int choice;
                // const int removeStu = 100;
                // Student students[removeStu];
                removeStudent(students, count);
                cout << "\tPress 1 to continue removing students\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 6)
        {
            do {
                int count = 0;
                int teacherID;
                cout << "Enter an ID of teacher to remove from system\n";
                cin >> teacherID;
                // const int removTchr = 100;
                // Teacher teachers[removTchr];
                removeTeacher(teachers, count, teacherID);
                cout << "\tPress 1 to continue removing teachers\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 7)
        {
            do {
                int count = 0;
                const int removCourse = 100;
                newCourse course[removCourse];
                removeCourse(course, count);
                cout << "\tPress 1 to continue removing courses\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 8)
        {
            do {

                viewStudent(students, count);
                //    cout<<"\tPress 1 to continue adding students\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if (userType == 9)
        {
            do {

                viewTeachers(teachers, count);
                //    cout<<"\tPress 1 to continue adding teachers\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if(userType == 10){
            do {

                allocateCourse(teachers, course);               
                 //    cout<<"\tPress 1 to continue adding teachers\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        else if(userType == 11){
            do {

                deAllocateCourse(teachers, course);               
                 //    cout<<"\tPress 1 to continue adding teachers\n";
                cout << "\tPress 0 to go back...\n";
                cin >> x;
            } while (x);
        }
        cout<<endl<<endl<<endl;
        cout << "\t\t'Press 1 to see the admin control system'  :\n";
        cout << "\t\t'Press 0 to exit from program':\n";
        cout<<"\t\t";
        cin >> a;
    } while (a);

}

int main() {
    int userType = login();

    switch (userType) {
    case 1:
        studentLogin();
        break;
    case 2:
        teacherLogin();
        break;
    case 3:
        adminLogin();
        break;
    }
    return 0;
}
