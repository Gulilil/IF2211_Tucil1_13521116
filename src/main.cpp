#include <iostream>
#include <chrono>
#include "calc.cpp"
#include "io.cpp"
using namespace std;
using namespace std::chrono;

int main () {
    // Variables Declaration
    int i, j , k;
    int w, x, y, z;
    int arr[4];
    int allValid = 1;
    int nSolutions = 0;
    string tempOpr;
    string arrSolutions[500];
    int permuteArr[24][4];
    int nPermutes = 0;

    // Display Ascii Art
    displayArt();
    
    // Reading Input
    char ans;
    float temp;
    cout << "Hi there! Welcome to 24 card game solver! " << endl;
    cout << "Here are the options you can use to run the program: " << endl;
    cout << "(1) to manually insert your desired numbers. " << endl;
    cout << "(2) to automatically generate random numbers. " << endl;
    cout << "=> " ;
    cin >> ans;
    cin.clear();
    cin.ignore(100,'\n');

    while (ans > '2' || ans < '1'){
        cout << "The answer you just inputted is invalid. Please insert an appropriate input." << endl;
        cout << "=> " ;
        cin >> ans;
        cin.clear();
        cin.ignore(100,'\n');
    }

    if (ans == '1'){
        cout << "Please insert the desired numbers. List of valid inputs:" << endl;
        cout << "A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K. (e.g. 10 A 3 J)" << endl;
        string a, b, c, d;
        cout << "=> " ;
        cin >> a >> b >> c >> d;
        cin.clear();
        cin.ignore(100,'\n');

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
            cin.clear();
            cin.ignore(100,'\n');

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
    cout << "The program starts to solve..." << endl;

    // Starting the timer
    auto start = high_resolution_clock::now();

    for (w = 0; w < 4; w++){
        for (x = 0; x < 4 ; x++){
            for (y = 0; y < 4; y++){
                for (z = 0; z< 4; z++){
                    if (w != x && w != y && w != z && x != y && x != z && y != z){
                        int newArr[4];
                        newArr[0] = arr[w];
                        newArr[1] = arr[x];
                        newArr[2] = arr[y];
                        newArr[3] = arr[z];

                        // Make sure multiple same numbers are not processed multiple times
                        if (!isUsedPermute(newArr, permuteArr, nPermutes)){

                            // Every valid permutation will be stored in the array
                            // the index of permutation array will increase
                            for (i = 0; i < 4; i++){
                                permuteArr[nPermutes][i] = newArr[i];
                            }
                            nPermutes++;

                            // 4x4x4 loops represents 4 options for 3 operations that are used in calculations
                            for (i = 0; i < 4 ; i++){
                                for (j = 0; j < 4 ; j++){
                                    for (k = 0; k < 4; k++){
                                        temp = calculate1(i,j,k, newArr);

                                        // cout << temp << "|1|" <<endl; // Hanya untuk mengecek
                                        if (temp == 24){
                                            tempOpr = makeOpr(i, j, k, newArr, 1);
                                            // cout << tempOpr << endl;
                                            arrSolutions[nSolutions] = tempOpr;
                                            if(nSolutions < 500){
                                                nSolutions++;
                                            }
                                        }
                                        temp = calculate2(i,j,k, newArr);
                                        //cout << temp << "|2|" <<endl; // Hanya untuk mengecek
                                        if (temp == 24){
                                            tempOpr = makeOpr(i, j, k, newArr, 2);
                                            // cout << tempOpr << endl;
                                            arrSolutions[nSolutions] = tempOpr;
                                            if(nSolutions < 500){
                                                nSolutions++;
                                            }
                                        }
                                        temp = calculate3(i,j,k, newArr);
                                        // cout << temp << "|3|" <<endl; // Hanya untuk mengecek
                                        if (temp == 24){
                                            tempOpr = makeOpr(i, j, k, newArr, 3);
                                            // cout << tempOpr << endl;
                                            arrSolutions[nSolutions] = tempOpr;
                                            if(nSolutions < 500){
                                                nSolutions++;
                                            }
                                        }
                                        temp = calculate4(i,j,k, newArr);
                                        //cout << temp << "|4|" <<endl; // Hanya untuk mengecek
                                        if (temp == 24){
                                            tempOpr = makeOpr(i, j, k, newArr, 4);
                                            // cout << tempOpr << endl;
                                            arrSolutions[nSolutions] = tempOpr;
                                            if(nSolutions < 500){
                                                nSolutions++;
                                            }
                                        }
                                        temp = calculate5(i,j,k, newArr);
                                        // cout << temp << "|5|" <<endl; // Hanya untuk mengecek
                                        if (temp == 24){
                                            tempOpr = makeOpr(i, j, k, newArr, 5);
                                            // cout << tempOpr << endl; 
                                            arrSolutions[nSolutions] = tempOpr;
                                            if(nSolutions < 500){
                                                nSolutions++;
                                            }
                                        }
                                    }
                                }
                            }


                        }


                    }
                }
            }
        }
    }

    // Stopping the timer1 (calculation only)
    auto stop1 = high_resolution_clock::now();
    
    // Displaying Solutions
    string hBorder;
    for (i = 0; i < (tempOpr.length()+8) ; i++){
        hBorder += "=";
    }
    cout << "The amount of solutions: " << nSolutions << endl;


    if (nSolutions == 0){
        cout << " []========================================================[]" << endl;
        cout << " || No equation can be showed since there is no solution. ||" << endl;
        cout << " []========================================================[]" << endl;
    } else {
        cout << "  []"<< hBorder <<"[]  " << endl;
        cout << "          Solutions" << endl;
        cout << "  []"<< hBorder <<"[]  " << endl;
        for (i = 0; i < nSolutions; i++){
            cout << "  ||    " <<arrSolutions[i] << "    ||  " << endl;
        }
        cout << "  []"<< hBorder <<"[]  " << endl;
    }
    

    // Stopping the timer2 (calculation + displaying result)
    auto stop2 = high_resolution_clock::now();
    
    auto duration1 = duration_cast<microseconds>(stop1-start);
    auto duration2 = duration_cast<microseconds>(stop2-start);

    cout << "Execution time for BF Algorithm only: " << duration1.count() << " microseconds" << endl;
    cout << "Execution time including displaying the result: " << duration2.count() << " microseconds" << endl;

    // Saving the results in a file
    char save;
    cout << "Do you wish to save the result in a file? (y/n)" << endl ;
    do {
        cout << "=> " ;
        cin >> save;
        cin.clear();
        cin.ignore(100,'\n');
        save = capitalize(save);
        if (save != 'Y' && save != 'N'){
            cout << "Invalid input detected. Please insert again: " << endl;
        }
    } while (save != 'Y' && save != 'N');

    if (save == 'Y'){
        string fileName;
        cout << "Please insert the file name: " << endl;
        cout << "=> " ;
        cin >> fileName;
        writeOnFile(arrSolutions, fileName, nSolutions);
        cout << fileName << ".txt has been saved and stored inside the 'test' folder!" << endl;
    }

    cout << "The program has been stopped." << endl;

    return 0;
}
