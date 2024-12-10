#include <iostream>
#include <fstream>
using namespace std;
// Function to find the most popular student(s)
void findMostPopularStudents(string names[], int size, int& maxFriends, int& mostPopularStudent)
{maxFriends = 0;
    mostPopularStudent = -1;
    for (int i = 0; i < size; i++)
	{
        int friendCount = 0;
		 for (int j = 0; j < size-i-1; j++)
           {
			 if (names[j]==names[j+1]) {
                friendCount++;
			 }

         else{
            mostPopularStudent=1;

          }

		 }
        if (friendCount > maxFriends) {
            maxFriends = friendCount;
            mostPopularStudent = i;
        }

    }


}

int main() {
const int size=400;
       string names[size]={"Muhammad Ahmad", "Abdul Wasey", "Muhammad Samiullah", "Abdullah Bin Nazar", "Muhammad Haseeb Aslam",
        "Fahad Hameed", "Rehan Ahmad", "Muhammad Burhan Faisal", "Muhammad Anus Javed", "Muhammad Ahmad",
"Fahad Hameed","	Muhammad Haseeb Aslam","	Rehan Ahmad","	Laban Maseeh","	Muhammad Ahmad","	Muhammad Anus Javed",
"Muhammad Hussnain","	Abdullah Bin Nazar","	Mudassar Hassan","	Muhammad Ahmad","	Ahmad Hassan","	Zia Ur Rehman",
"	Muhammad Abdullah","	Hafsa Aslam","	Muhammad Faisal Ghaffar",	"Mohid Hussain","	Rana Mustehsin Hussain",
"Aiman Mahmood","	Nisma","Rafiah","Mehwish Samreen","	Seerat Ul Noor",	"Rimsha Ahmad",
"	Anus Khan Burki","	Abdul Wasey","	Rana Mustehsin Hussain	",
"Abdullah Bin Nazar",	"Mudassar Hassan","	Muhammad Hussnain","	Abdullah Bin Nazar",
"Warda Ali"	,"Rimsha Ahmad","	Adina Tariq	","Dua Fatima","	Tuba Rani","	Hafsa Aslam",
"Muhammad Anus Javed",	",Muhammad Hussain Abbas","	Muhammad Ahmad","	Farwah Tasleem",	"Rana Mustehsin Hussain","	Muhammad Samiullah","	Abdullah Bin Nazar","	Mudassar Hassan","	Anus Khan Burki",
"Nisma",	"Khadija Asghar	","Khadija Imam","	Farwah Tasleem",
"Seerat Ul Noor","	Aiman Mahmood","	Rafiah	Mehwish Samreen",
"Muhammad Ammar	","Muhammad Shehroz Hameed","	Muhammad Haseeb Aslam","	Fahad Hameed","	Muhammad Ahmad","	Zia Ur Rehman",
"Mehwish Samreen","	Seerat Ul Noor","	Rafiah","	Aiman Mahmood",
"Rafiah","	Seerat Ul Noor","	Mehwish Samreen","	Aiman Mahmood	",
"Zia Ur Rehman","	Laban Maseeh","	Abdullah Bin Nazar","	Muhammad Haseeb Aslam","	Muhammad Ammar","	Muhammad Shehroz Hameed",
"Muhammad Shehroz Hameed","	Muhammad Ammar"	,"Muhammad Ahmad","	Muhammad Haseeb Aslam",
"Aiman	","Aiman","	Bismah Raees","	Muqadas Fatima",
"Dua Fatima","	Warda Ali","	Khadija Imam","	Muqadas Fatima","	Shaiman Anwar","	Maheen Fatima",
"Khadija Asghar","	Farwah Tasleem","	Nisma","	Khadija Imam",
"Muhammad Abdullah",	"Muhammad Ahmad","	Rehan Ahmad","	Anus Khan Burki","	Muhammad Ammar","	Muhammad Shehroz Hameed",
"Mohid Hussain	","Muhammad Faisal Ghaffar","	Azhar Khan	","Muhammad Daniyal Idrees","	Muhammad Hussnain","	Ahmad Hassan",
"Farwah Tasleem	","Nisma","	Khadija Asghar","	Khadija Imam",
"Khadija Imam	","Muqadas Fatima","	Nisma","	Khadija Asghar","	Farwah Tasleem","	Zainab Sandhu",
"Muhammad Ahmad	","Muhammad Hussnain","	Zia Ur Rehman","	Muhammad Abdullah","	Muhammad Anus Javed","	Muhammad Haseeb Aslam",
"Ahmad Hassan	","Muhammad Hussnain","	Mohid Hussain","	Muhammad Ahmad","	Muhammad Muneeb Ur Rehman","	Abdullah Bin Nazar",

};





    // Find the most popular student(s)

    // Write the results to a file

    int maxFriends, mostPopularStudent;
    findMostPopularStudents(names,size, maxFriends, mostPopularStudent);
    cout << "Most popular student(s): " << names[mostPopularStudent] << " with " << maxFriends << " friends" << endl;

    ofstream outputFile("D:\Discrete project\Friends Dataset.csv",ios::out);
    outputFile << "Most popular student(s): " << names[mostPopularStudent] << " with " << maxFriends << " friends" << endl;

    outputFile.close();

    return 0;
}

