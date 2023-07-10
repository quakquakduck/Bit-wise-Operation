#include<bits/stdc++.h>
using namespace std;


int pluss(const int &x, const int &y){
    int a, b, m, n;
    a = x, b = y;
    while (a){
        m = (a&b)<<1;
        n = (a^b);
        a = m;
        b = n;
    }
    return b;
}

int minuss(const int &x, const int y){
    return pluss(x, pluss(~y, 1));
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << minuss(x, y);
}