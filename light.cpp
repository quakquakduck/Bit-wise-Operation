#include<bits/stdc++.h>
using namespace std;

int arr[100];
int m, n;
int c;
int q, p, ind;
int t;
int ans;



int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n ; i++){        
        cin >> c;
        for (int j = 0 ; j < c ; j++){
            cin >> t;
            arr[i] |= (1<<t);
        }
    }
    
    cin >> q;

    for (int i = 0 ; i < q ; i++){
        cin >> p;
        ans = 0;
        for (int j = 0 ; j < p ; j++){
            cin >> ind;
            ans ^= arr[ind];           
        }
        for (int j = 1 ; j <= m ; j++){
            cout << (bool)(ans&(1<<j));
        }
        cout << '\n';
    }
}