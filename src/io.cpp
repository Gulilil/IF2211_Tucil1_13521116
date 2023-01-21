#include <iostream>
#include <fstream>
using namespace std;

char capitalize(char C){
    // Digunakan untuk memastikan bahwa input user untuk Char adalah huruf Kapital
    if ( C >= 97 && C <= 122){
        return (C-32);
    }
}

int integerConvert(string S){
    // Digunakan untuk mengubah nilai A menjadi 1, J menjadi 11, Q menjadi 12, dan K menjadi 13
    if (S.length() > 2){
        return -999;
    } else if (S.length() == 2){
        if (S[0] == '1' && S[1] == '0'){
            return 10;
        } else {
            return -999;
        }
    } else {
        char temp = capitalize(S[0]);
        if ( temp >= 50 && temp <= 57){ // Angka
            return (temp-48);
        } else {
            if (temp == 65){ // Ace
                return 1;
            } else if ( temp == 74){ // Jack
                return 11;
            } else if (temp == 81){ // Queen
                return 12; 
            } else if (temp == 75){ // King
                return 13;
            } else { // Untuk kasus dimana input tidak valid
                return -999;
            }
        }
    }

}

void printArr(int arr[4]){
    // Melakukan print atas nilai-nilai yang dikandung pada array
    int i;
    for( i = 0 ; i < 4; i++){
        switch (arr[i]){
            case 1:
                cout << 'A' << ' ';
                break;
            case 11:
                cout << 'J'<< ' ';
                break;
            case 12:
                cout << 'Q'<< ' ';
                break;
            case 13:
                cout << 'K'<< ' ';
                break;
            default:
                cout << arr[i]<< ' ';
                break;
        }
    }
    cout << endl;
}

void writeOnFile(string strArr[500], string fileName, int n){
    ofstream outputFile;
    string path = "test/"+fileName+".txt";
    outputFile.open(path);

    outputFile << n << endl;
    if (n == 0){
        outputFile << "No equation can be showed since there is no solution." << endl;
    } else {
        for (int i = 0; i < n; i++){
            outputFile << strArr[i] << endl;
        }
    }
    outputFile.close();
}