#include<iostream>
using namespace std;

int main(){
    int pos = 0;
    char myArr[50] = {'j', 'k', 'l', ' ' ,'m'};
    cout << myArr[5]<<endl;
    while(myArr[pos]){
        cout << myArr[pos] <<endl;
        pos++;
    }
    return 0;
}