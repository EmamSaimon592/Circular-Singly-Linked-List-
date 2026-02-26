#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

struct Student {
    int id;
    string name;
    double marks;
};

int main() {

    // Using vector (Dynamic Array)
    vector<Student> students = {
        {101, "Imam", 85.5},
        {102, "Rahim", 78.0},
        {103, "Karim", 92.3},
        {104, "Sakib", 88.7}
    };

    // Sort students by marks (Descending)
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.marks > b.marks;
    });

    cout << "Students sorted by marks:\n";
    for (auto s : students) {
        cout << s.id << " " << s.name << " " << s.marks << endl;
    }

    cout << "\n";

    // Find a student using find_if
    int searchId = 102;
    auto it = find_if(students.begin(), students.end(),
        [searchId](Student s) {
            return s.id == searchId;
        });

    if (it != students.end()) {
        cout << "Found Student: " << it->name << endl;
    } else {
        cout << "Student not found\n";
    }

    cout << "\n";

    //  Using map (Key-Value Pair)
    map<int, string> studentMap;
    for (auto s : students) {
        studentMap[s.id] = s.name;
    }

    cout << "Student Map:\n";
    for (auto p : studentMap) {
        cout << p.first << " => " << p.second << endl;
    }

    cout << "\n";

    //  Calculate average marks using accumulate
    double total = accumulate(students.begin(), students.end(), 0.0,
        [](double sum, Student s) {
            return sum + s.marks;
        });

    cout << "Average Marks: " << total / students.size() << endl;

    return 0;
}
