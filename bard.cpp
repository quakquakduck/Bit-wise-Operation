#include<bits/stdc++.h>
using namespace std;

int n, e, k;
int vil[105];
int v;
int pre; //bool
int allsong;
bool b = 0; // if 1 appear
int main(){
    cin >> n >> e;
    for (int i = 0 ; i < e ; i++){
        cin >> k;
        pre = 0;
        allsong = 0;
        b = 0;
        for (int j = 0 ; j < k ; j++){
            cin >> v;
            pre |= (1<<v);
            if (v == 1){
                b = 1;
                allsong = 0;  
                allsong |= (1<<i);
            }

            if (!b) allsong |= vil[v];   
        }
        k = 0;
        while (pre){
            pre >>= 1;
            k++;
            if (pre&1){
                vil[k] |= allsong;
            }
            
        }        
    }
    cout << 1 << '\n';
    for (int i = 2 ; i <= n ; i++){
        if (!(vil[i]^vil[1])){
            cout << i << '\n';
        }
    }
}