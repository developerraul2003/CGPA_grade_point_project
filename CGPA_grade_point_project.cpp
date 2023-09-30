#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to hold information about a course
struct Course {
    string courseName;
    int credits;
    char grade;
};

// Function to calculate grade points based on the grade received
double calculateGradePoints(char grade) {
    switch (grade) {
        case 'A':
            return 4.0;
        case 'B':
            return 3.0;
        case 'C':
            return 2.0;
        case 'D':
            return 1.0;
        case 'F':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    // Input grades and credits for each course
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter course name: ";
        cin >> courses[i].courseName;
        cout << "Enter credits for " << courses[i].courseName << ": ";
        cin >> courses[i].credits;
        cout << "Enter grade for " << courses[i].courseName << " (A, B, C, D, or F): ";
        cin >> courses[i].grade;

        // Calculate and accumulate grade points
        double gradePoints = calculateGradePoints(courses[i].grade);
        if (gradePoints == -1.0) {
            cout << "Invalid grade entered for " << courses[i].courseName << ". Please enter A, B, C, D, or F." << endl;
            return 1;
        }
        totalGradePoints += gradePoints * courses[i].credits;
        totalCredits += courses[i].credits;
    }

    // Calculate GPA for the semester
    double semesterGPA = totalGradePoints / totalCredits;

    cout << "Semester GPA: " << semesterGPA << endl;

    // Additional code for file handling (saving data to a file)
    ofstream outFile("cgpa_data.txt");
    if (!outFile) {
        cout << "Error: Unable to open the file for writing." << endl;
        return 1;
    }

    // Write course data to the file
    for (vector<Course>::const_iterator it = courses.begin(); it != courses.end(); ++it) {
    const Course& course = *it;
    outFile << course.courseName << " " << course.credits << " " << course.grade <<endl;
}


    return 0;
}
