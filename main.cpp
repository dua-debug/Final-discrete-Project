#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_FRIENDSHIPS = 100;
int main() {
    string friendsA[MAX_FRIENDSHIPS];
    string friendsB[MAX_FRIENDSHIPS];
    int count = 0;

    ifstream inputFile("C:\\Users\\hp\\Documents\\nk\\Friends Dataset.txt");


    string a, b;

    while (inputFile >> a >> b) {
       if (count < MAX_FRIENDSHIPS) {
            friendsA[count] = a;
            friendsB[count] = b;
            count++;
        } else {
            cerr << "Maximum number of friendships reached!" << endl;
            break;
        }
    }
    inputFile.close();

    cout << "Asymmetric friendship pairs:" << endl;
    for (int i = 0; i < count; ++i) {
        bool isAsymmetric = true;
        for (int j = 0; j < count; ++j) {

            if (friendsA[i] == friendsB[j] && friendsB[i] == friendsA[j]) {
                isAsymmetric = false;
                break;
            }
        }
        if (isAsymmetric) {
            cout << "(" << friendsA[i] << ", " << friendsB[i] << ")" << endl;
        }
    }

    return 0;
}
