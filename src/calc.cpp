#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;


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

int isSamePermute(int arr1[4], int arr2[4]){
    // Melakukan cek apakah sebuah array yang berisikan sebuah permutasi adalah array yang sama
    // Digunakan untuk menunjang pengecekan permutasi berulang
    int i;
    for (i = 0; i < 4; i++){
        if (arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}

int isUsedPermute(int arr[4], int permArr[24][4], int n){
    // Melakukan cek apakah permutasi yang serupa telah dilakukan sebelumnya. 
    // Hal ini digunakan untuk menghindari pengulangan untuk urutan angka yang serupa
    int i;
    int used;
    for (i = 0; i < n; i++){
        if (isSamePermute(arr, permArr[i])){
            return 1;
        }
    }
    return 0;
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
    return operate(z, (operate(x, arr[0], (operate(y, arr[1], arr[2])))), arr[3]);
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
    return operate(x, arr[0], (operate(y, arr[1], (operate(z, arr[2], arr[3])))));
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




