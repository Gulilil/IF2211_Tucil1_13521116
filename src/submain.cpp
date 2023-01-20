#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
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

float operate(int key, float a, float b){
    // Melakukan operasi dengan key yang telah ditentukan
    if (key == 0){
        return a + b;
    } else if (key == 1){
        return a - b ;
    } else if (key == 2){
        return a * b;
    } else {
        return a / b;
    }
}

/*
5 jenis pengurungan
((a x b) y c) z d
( a x (b y c))z d
( a x b) y (c z d)
a x ((b y c) z d )
a x (b y (c z d ))

ket : a, b, c, d => angka (integer) | x, y, z => operator
*/

float calculate1(int x, int y, int z, int arr[4]){
    // Melakukan perhitungan jenis pengurungan 1
    return operate(z, (operate(y, (operate(x, arr[0], arr[1])), arr[2])), arr[3]);
}

float calculate2(int x, int y, int z, int arr[4]){
    // Melakukan perhitungan jenis pengurungan 2
    return operate(z, (operate(y, arr[0], (operate(y, arr[1], arr[2])))), arr[3]);
}

float calculate3(int x, int y, int z, int arr[4]){
    // Melakukan perhitungan jenis pengurungan 3
    return operate(y, (operate(x, arr[0], arr[1])) ,(operate(z, arr[2], arr[3])) );
}

float calculate4(int x, int y, int z, int arr[4]){
    // Melakukan perhitungan jenis pengurungan 4
    return operate(x, arr[0], (operate(z, (operate(y, arr[1], arr[2])), arr[3])));
}

float calculate5(int x, int y, int z, int arr[4]){
    // Melakukan perhitungan jenis pengurungan 5
    return operate(x, arr[0], (operate(y, arr[1], (operate(x, arr[2], arr[3])))));
}

char keyToOpr(int x){
    // Mengubah integer key menjadi sebuah char operasi
    switch (x){
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return '*';
            break;
        default:
            return '/';
            break;
    }
}

string makeOpr(int x, int y, int z, int arr[4], int type){
    // Membuat string operasi dengan pengurungan
    string res = "";
    char a = keyToOpr(x);
    char b = keyToOpr(y);
    char c = keyToOpr(z);
    if (type == 1){
        // ((a x b) y c) z d
        res += "((" + to_string(arr[0]) + a + to_string(arr[1]) + ')';
        res += b + to_string(arr[2]) + ')';
        res += c + to_string(arr[3]);
        return res;
    } else if (type == 2){
        // ( a x (b y c))z d
        res += '(' + to_string(arr[0]) + a + '(';
        res +=  to_string(arr[1]) + b + to_string(arr[2]) + "))";
        res += c + to_string(arr[3]);
        return res; 
    } else if (type == 3){
        // ( a x b) y (c z d)
        res += '(' + to_string(arr[0]) + a + to_string(arr[1]) + ')';
        res += b;
        res +=  '('+ to_string(arr[2]) + c + to_string(arr[3]) + ')';
        return res;         
    } else if (type == 4){
        // a x ((b y c) z d )
        res += to_string(arr[0])+a+"((";
        res += to_string(arr[1])+ b+ to_string(arr[2]) + ')';
        res += c + to_string(arr[3]) + ')';
        return res;
    } else {
        // a x (b y (c z d ))
        res += to_string(arr[0]) + a + '(';
        res += to_string(arr[1]) + b + '(';
        res += to_string(arr[2]) + c + to_string(arr[3]) + "))";
        return res;
    }
    
}




