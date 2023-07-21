#include<bits/stdc++.h>
using namespace std;

int n;

int board[20];
int ans;
int ind = 0;


// p: ↙攻擊, q: ↘攻擊, r: ↓攻擊
void dfs(int depth, int p, int q, int r){
    
    if (depth == n){ // 搜尋到底
        ans++;
        return;
    }

    int avail = ~(board[depth]|p|q|r)&(int)(pow(2, n)-1); // 計算安全範圍

    while (avail){
        int last = (avail & -avail); // low-bit
        dfs(depth+1, (p|last)<<1, (q|last)>>1, r|last); 
        avail ^= last; // eliminate
    }
}




int main(){

    ios_base::sync_with_stdio(0), cin.tie(0);
    while (cin >> n){

        if (!n) break;
        ind++;
        ans = 0;
        for (int i = 0 ; i < 20 ; i++){
            board[i] = 0;
        }

        for (int i = 0 ; i < n ; i++){
            char c;
            for (int j = 0 ; j < n ; j++){
                cin >> c;
                if (~(c^(~'.'))){ 
                    board[i] |= (1<<j);
                }
            }
        }
        
        dfs(0, 0, 0, 0);
        cout << "Case " << ind << ": " << ans << '\n';
    }
    return 0;
}