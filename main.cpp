#include <iostream>
#include <string>
using namespace std;

void calculate();
bool check_is_same(long n1, long n2);

int main()
{
//cout << check_is_same(1100, 1001) << endl;
    calculate();
    return 0;
}

void calculate(){
    bool* flags = new bool[5];
    for(long i = 1;; i++){
        for(int j = 2; j <= 6; j++){
            if(check_is_same(i, i * j)){
                    flags[j-2] = true;
            }
            else{
                flags = new bool[5];
                break;
            }
            if(j == 6){
                    cout << i << endl;
            }
        }
    }
}

bool check_is_same(long n1, long n2){
    string dig_n1 = std::to_string(n1);
    string dig_n2 = std::to_string(n2);
    if(dig_n1.size() != dig_n2.size()){
        return false;
    }
    bool* chkc1 = new bool[dig_n1.size()];
    bool* chkc2 = new bool[dig_n2.size()];
    for(int i = 0; i < dig_n1.size(); i++){
            chkc1[i] = chkc2[i] = false;
    }
    int c = 0;
    for(int i = 0; i < dig_n1.size(); i++){
        for(int j = 0; j < dig_n2.size(); j++){
                if(dig_n1[i] == dig_n2[j] && chkc1[i] == false && chkc2[j] == false){
                        chkc2[j] = chkc1[i] = true;
                        c++;
                }
        }
    }
    if(c == dig_n1.size()){
        return true;
    }
    return false;
}
