#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
#define studentsize 80
#define namesize 50
#define scoresize 5
using namespace std;

int main () {
    char names[studentsize][namesize], tempname[namesize];
    float score[studentsize][scoresize], sum[studentsize], avarage[studentsize],temptest,tempsum,tempavarage;
    int n;
    
    do {
        cout << "enter the number of student: ";
        cin >> n;

        if (n < 0 || n > studentsize){
            cerr << "ERROR! number of students should be 1 - 80\n";
        }
    }while(n < 0 || n > studentsize);

    //accepting name and the test of each student
    for (int i = 0; i < n; i++){
        cin.ignore(INT_MAX, '\n');
        cout << i + 1<<". name: ";
        cin.getline(names[i], namesize - 1);

        for (int j = 0; j < 3; j++){

            do{//accepting the tests
                cout << names[i] << "\ntest" << j +1 << ": ";
                cin >> score[i][j];
                if (score[i][j] < 0 || score[i][j] > 100){
                    cerr << "ERROR- The test score must be between 1 - 100\n";
                }
            }while(score[i][j] < 0 || score[i][j] > 100);
            sum[i] += score[i][j];
        }
        avarage[i] = sum[i] /3;
    }
    //sorting the names and tests

    for (int i = 0; i < n - 1; i++){
        for (int j = i +1; j < n; j++){
            if (strcmp(names[i],  names[j]) > 0){
                //swaping the names
                strcpy(tempname, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], tempname);
                //swaping the scores
                for (int k = 0; k < scoresize; k++){
                    temptest = score[i][k];
                    score[i][k] = score[j][k];
                    score[j][k] = temptest;               
                }
                //swap sum
                tempsum = sum[i];
                sum[i] = sum[j];
                sum[j] = tempsum;

                //swap avarages
                tempavarage = avarage[i];
                avarage[i] = avarage[j];
                avarage[j] = tempavarage;
            }
        }
    }

    
    //display table
    cout << setw(60) << setfill('_') << ""<<setfill(' ') << endl;
    cout << left <<setw(20) << "FULL NAME" << setw(8) << "TEST[1]" << setw(8) << "TEST[2]" << setw(8) << "TEST[3]" << setw(8) << "SUM" << setw(8) << "AVARAGE" << endl;
    cout << setw(60) << setfill('_') << ""<<setfill(' ') << endl;
    for (int i = 0; i < n; i++){
        cout << left <<setw(20) << names[i] << setw(8) << score[i][0] << setw(8) << score[i][1]  << setw(8) << score[i][2]  << setw(8) << sum[i] << setw(8) << avarage[i] << endl;
    }
    cout << setw(60) << setfill('_') << ""<<setfill(' ') << endl;
    return 0;
}
