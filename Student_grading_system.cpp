#include<iostream>
#include<limits>
#include<vector>

using namespace std;

struct Student
{
    string name;
    double grade;
};

/*This function calculates the average grade of all students. 
Note : The const keyword means the function won't modify the vector, and the reference & means it won't copy the whole vector (which is more efficient). 
It returns a double, which will be the average grade.*/
double averageCalculation(const vector<Student> &students){
    double total = 0;
    for(const auto &student: students) //const auto& means it's accessing each Student in the vector by reference (to avoid copying) but won't modify them. 
    {
        total += student.grade;
    }
    return students.empty() ? 0 : total/students.size();
}

//function to find the highest and the lowest grade.
void findHighestAndLowest(const vector<Student> &students, double &highest, double &lowest){
    if(students.empty()) return;
    
    //initialising both highest and lowest to the first student's data.
    highest = students[0].grade; 
    lowest = students[0].grade;

    for(const auto &Student : students){
        if(Student.grade>highest) 
            highest = Student.grade;

        if(Student.grade < lowest) 
            lowest = Student.grade;
    }
}

int main(){
    vector<Student> students;
    string name;
    double grade;
    
    while(true){
        cout<<"Enter student's name (or type 'done' to finish): ";
        getline(cin, name);
        if(name=="done") break;

        cout<<"Enter " << name << "'s grade: ";
        cin>> grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        students.push_back({name, grade});
    }

    double averageGrade = averageCalculation(students);
    double highestGrade, lowestGrade;
    findHighestAndLowest(students, highestGrade, lowestGrade);

    cout<<"Average Grade: "<< averageGrade << endl;
    cout<<"Highest Grade: "<< highestGrade << endl;
    cout<<"Lowest Grade: "<< lowestGrade << endl;
    
    return 0;
}