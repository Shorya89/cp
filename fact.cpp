#include <iostream>
using namespace std;

long long fact(long long n){
    if(n == 1){
        return 1;
    }

    return n * fact(n-1);
}

int main(){
    long long n;
    cin >> n;

    if(n > 100){
        cout << fact(n);
    }else{
        cout << "INVALID";
    }

    return 0;
}