#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Maximum number of students and friends
const int MAX_STUDENTS = 100;
const int MAX_FRIENDS = 100;

// Data to store the students and their friendships
string students[MAX_STUDENTS];
int graph[MAX_STUDENTS][MAX_FRIENDS];
int studentCount = 0;

// Find the index of a student in the array
int findStudent(string name) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i] == name) {
            return i;
        }
    }
    return -1;
}

// Add a student to the list and return their index
int addStudent(string name) {
    students[studentCount] = name;
    return studentCount++;
}

// Load the graph from the file
void loadGraph(string filename) {
    ifstream file(filename);
    string student, friendName;

    while (file >> student) {
        int studentIndex = findStudent(student);
        if (studentIndex == -1) {
            studentIndex = addStudent(student);
        }

        while (file.peek() != '\n' && file >> friendName) {
            int friendIndex = findStudent(friendName);
            if (friendIndex == -1) {
                friendIndex = addStudent(friendName);
            }
            graph[studentIndex][friendIndex] = 1; // Mark as friends
        }
    }
}

// Find and display 1-hop, 2-hop, and 3-hop connections
void findConnections(string startStudent, int maxHops) {
    int visited[MAX_STUDENTS] = {0};
    int queue[MAX_STUDENTS], front = 0, back = 0;
    int hops[MAX_STUDENTS] = {0};

    int startIndex = findStudent(startStudent);
    if (startIndex == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    // Start BFS
    queue[back++] = startIndex;
    visited[startIndex] = 1;

    while (front < back) {
        int current = queue[front++];
        int currentHop = hops[current];

        if (currentHop < maxHops) {
            for (int i = 0; i < studentCount; i++) {
                if (graph[current][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    hops[i] = currentHop + 1;
                    queue[back++] = i;
                }
            }
        }
    }

    // Display results
    for (int hop = 1; hop <= maxHops; hop++) {
        cout << hop << "-Hop Connections: ";
        for (int i = 0; i < studentCount; i++) {
            if (hops[i] == hop) {
                cout << students[i] << " ";
            }
        }
        cout << endl;
    }
}

// Main function
int main() {
    string filename = "data.txt";
    string startStudent;

    // Load the graph
    loadGraph(filename);

    // Ask user for starting student
    cout << "Enter the student's name: ";
    cin >> startStudent;

    // Find connections
    findConnections(startStudent, 3);

    return 0;
}
