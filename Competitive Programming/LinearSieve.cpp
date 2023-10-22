#include<bits/stdc++.h>
using namespace std;

int N = 100000000;
int lp[100000005];
vector<int> pr;

void LinearSieve(){
    for (int i=2; i <= N; ++i) {
        if(lp[i] == 0){
            pr.push_back(i);
            lp[i] = i;
        }
        for(int j = 0; i * pr[j] <= N ; j++){
            lp[i * pr[j]] = pr[j];
            if(pr[j] == lp[i]){
                break;
            }
        }
    }
}

int main(){
    
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

LinearSieve();

// print with 100th jump
int i = 0;
while(i < pr.size()){
    cout<<pr[i]<<endl;
    i += 100;
}

return 0;
}