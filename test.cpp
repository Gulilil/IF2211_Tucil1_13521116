#include <iostream>
using namespace std;

int main (){
    int i, j , k;
    for (i = 0; i < 4 ; i++){
        for (j = 0; j < 4 ; j++){
            for (k = 0; k < 4; k++){
                cout << i << j << k << endl;
            }
        }
    }
}