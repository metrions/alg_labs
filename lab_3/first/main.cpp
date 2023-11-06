#include <iostream>

#include "lcs.h"

#include <string>
#include <chrono>

using namespace std::chrono;

using namespace std;

string rand_string(int len){
    string str = "";
    string m = "assasfasgmlmvokmsdoafmqaslkmspamvoafsagkdbmomsbpmpoge";
    for (int i=0; i<len; i++){
        str += m[(random()%20)];
    }
    return str;
}


int main() {
    int N = 20;
    int M = 15;
    string str1 = rand_string(N);
    string str2 = rand_string(M);
    // for (int i=0; i<str1.size(); i++){
    //     std::cout << str1[i] << " ";
    // }
    auto t_1 = steady_clock::now();
    auto q = lcs(str1, str2);
    auto t_2 = steady_clock::now();
    cout << "N: " << N << " M:" << M << "\n";
    cout << "fast - " << duration<double>(t_2 - t_1).count() << endl;
    t_1 = steady_clock::now();
    q = lcs_slow(str1, str2);
    t_2 = steady_clock::now();
    cout << "slow - " << duration<double>(t_2 - t_1).count() << endl;
    return 1;
}
