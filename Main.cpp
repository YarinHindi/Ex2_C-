#include <iostream>
#include <stdexcept>
#include  <cmath>
#include "mat.hpp"
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
using namespace ariel;


// func to check if the string can be casted to an int
// and if so the number we send to thr function will be updated.
bool getNum(const string& str,int *castedNumber)
{
    int len = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] -'0';
        if (i==0){
            if (val==0){
                return false;
            }
        }
        if (val< 0|| val >9){
            return false;
        }
        else{
            *castedNumber+= val*pow(10,len-1);
            len--;

        }
        }
    return true;
    }


int main() {
    cout << "The numbers must be  bigger than 0 and odd \n";
    cout << "The char could be any valid one length character on the keyboard" << endl;
    int columns=0;//the columns number after we will cast the string into integer
    int rows = 0;//the rows number after we will cast the string into integer
    string s1, s2; // for the numbers input
    string sc1, sc2; // for the characters input
    char ch1, ch2; // for the mattress characters
    bool finish= false;
    while (!finish) {
        cout << "Enter a valid number: ";
        cin >> s1;
        while (!(getNum(s1,&columns))) {
            cout << "The input was not correct, Enter a valid number: ";
            cin >> s1;
        }
        cout << "Please Enter another valid number: ";
        cin >> s2;
        while (!(getNum(s2,&rows))) {
            cout << "The input was not valid, Enter a valid number: ";
            cin >> s2;
        }
        cout << "Enter a valid char: ";
        cin >> sc1;
        while (sc1.length() != 1) {
            cout << "The input was not correct, Enter a valid character: ";
            cin >> sc1;
        }
        ch1 = *sc1.c_str();
        cout << "Enter another valid char: ";
        cin >> sc2; // getting the input from the user
        while (sc2.length() != 1) {
            cout << "The input was not valid, Enter a valid character: ";
            cin >> sc2;
        }
        ch2 = *sc2.c_str();
        try {
            cout << mat(columns, rows, ch1, ch2) << endl;
            finish = true;
        }
        catch (invalid_argument err) {
            cout << "\n" << err.what();
            cout << "\nPlease try again !\n" << endl;
        }
    }
    cout << "\n Done!" << endl;
}