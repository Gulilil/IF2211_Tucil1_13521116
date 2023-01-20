#include <iostream>
#include "submain.cpp"
using namespace std;

int main () {
    // Variables Declaration
    int i, j , k;
    int x;
    int arr[4];
    int allValid = 1;
    int nSolutions = 0;
    string tempOpr1, tempOpr2, tempOpr3, tempOpr4, tempOpr5;
    string arrSolutions[50];
    
    // Reading Input
    int ans;
    float temp;
    cout << "Please insert (1) to input the numbers yourself or " << endl;
    cout << "(2) to automatically generate random numbers. " << endl;
    cin >> ans;
    while (ans > 2 || ans < 1){
        cout << "The answer you just inputed is invalid. Please insert an appropriate input." << endl;
        cin >> ans;
    }

    if (ans == 1){
        cout << "Please insert the desired numbers. List of valid inputs:" << endl;
        cout << "A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K." << endl;
        string a, b, c, d;
        cout << "=> " ;
        cin >> a >> b >> c >> d;
        arr[0] = integerConvert(a);
        arr[1] = integerConvert(b);
        arr[2] = integerConvert(c);
        arr[3] = integerConvert(d);

        for (i = 0; i < 4; i++){
            if (arr[i] == -999){
                allValid = 0;
            }
        }

        // Error handling
        while (!allValid){
            cout << "The program has detected (an) invalid input(s). Please insert the suitable ones." << endl;
            allValid = 1;
            cout << "=> " ;
            cin >> a >> b >> c >> d;
            arr[0] = integerConvert(a);
            arr[1] = integerConvert(b);
            arr[2] = integerConvert(c);
            arr[3] = integerConvert(d);
            
            for (i = 0; i < 4; i++){
                if (arr[i] == -999){
                    allValid = 0;
                }
            }
        }
    } else {
        // Random Number Generator
        cout << "The program will generate random inputs for you." << endl;

        srand(time(0));
        for (i = 0 ; i < 4; i++){
            arr[i] = (rand() % 13) +1;
        }
    }

    cout << "Here are your numbers : ";
    printArr(arr);

    // Solving Algorithm
    for (i = 0; i < 4 ; i++){
        for (j = 0; j < 4 ; j++){
            for (k = 0; k < 4; k++){
                temp = calculate1(i,j,k, arr);
                cout << i << j << k << endl;
                // cout << temp << "|1|" <<endl; // Hanya untuk mengecek
                if (temp == 24){
                    tempOpr1 = makeOpr(i, j, k, arr, 1);
                    arrSolutions[nSolutions] = tempOpr1;
                    nSolutions++;
                }
                temp = calculate2(i,j,k, arr);
                //cout << temp << "|2|" <<endl; // Hanya untuk mengecek
                if (temp == 24){
                    tempOpr2 = makeOpr(i, j, k, arr, 2);
                    arrSolutions[nSolutions] = tempOpr2;
                    nSolutions++;
                }
                temp = calculate3(i,j,k, arr);
                // cout << temp << "|3|" <<endl; // Hanya untuk mengecek
                if (temp == 24){
                    tempOpr3 = makeOpr(i, j, k, arr, 3);
                    arrSolutions[nSolutions] = tempOpr3;
                    nSolutions++;
                }
                temp = calculate4(i,j,k, arr);
                //cout << temp << "|4|" <<endl; // Hanya untuk mengecek
                if (temp == 24){
                    tempOpr4 = makeOpr(i, j, k, arr, 4);
                    arrSolutions[nSolutions] = tempOpr4;
                    nSolutions++;
                }
                temp = calculate5(i,j,k, arr);
                // cout << temp << "|5|" <<endl; // Hanya untuk mengecek
                if (temp == 24){
                    tempOpr5 = makeOpr(i, j, k, arr, 5);
                    arrSolutions[nSolutions] = tempOpr5;
                    nSolutions++;
                }
            }
        }
    }
    cout << "The amount of solutions: " << nSolutions << endl;
    for (i = 0; i < nSolutions; i++){
        cout << arrSolutions[i] << endl;
    }


    return 0;
}
