#include<bits/stdc++.h>
using namespace std;

int arr[100];
int m, n;
int c;
int q, p, trait;
int t;



int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){        
        cin >> c;
        for (int j = 0 ; j < c ; j++){
            cin >> t;
            arr[i] |= (1<<t);
        }
    }


    cin >> q;
    for (int i = 0 ; i < q ; i++){
        trait = 0;
        cin >> p;
        int num = 0;
        for (int j = 0 ; j < p ; j++){
            cin >> t;
            trait |= (1<<t);
        }
        for (int j = 0 ; j < n ; j++){
            if (!(trait^(arr[j]&trait))){
                num++;
            }
        }
        cout << num << '\n';
    }
}
