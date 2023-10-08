#include "lcs.h"
#include <map>
#include <iostream>

using namespace std;

string lcs(const string &first, const string &second) {
    string t = "";
    if (first.length() !=0 && second.length() !=0){
        string **mas = new string*[first.length()];
        for (int i=0; i<first.length(); i++){
            mas[i] = new string[second.length()];
            for (int j=0; j<second.length(); j++){
                if (i == 0 || j==0){
                    if (first[i] == second[j]){
                        mas[i][j] = first[i];
                    }
                    else{
                        if (i != 0){
                            mas[i][j] = mas[i-1][j];
                        }
                        else if (j != 0) mas[i][j] = mas[i][j-1];
                        else{
                            mas[i][j] = "";
                        }
                    }
                }
                else if (first[i] == second[j]){
                    mas[i][j] = mas[i-1][j-1] + first[i];
                }
                else{
                    mas[i][j] = ((mas[i-1][j]).length() >= (mas[i][j-1]).length()) ? mas[i-1][j] : mas[i][j-1];
                }
            }
        }
        string t = mas[first.length()-1][second.length()-1];
        for (int i=0; i<first.length(); i++){
            delete[] mas[i];
        }
        delete[] mas;
        return t;
        }
    return t;
}





