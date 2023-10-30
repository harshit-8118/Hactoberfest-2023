#include<bits/stdc++.h>
using namespace std;

int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int n, m;
cin>>n>>m;
vector<int> a(n), b(m);
for(int i = 0; i < n; i++)
    cin>>a[i];
for(int j = 0; j < m; j++){
    cin>>b[j];
}

int i = 0, j = 0;
while(i < n and j < m){
    if(i > 0 and a[i] == a[i-1]){ i++; continue; }
    if(j > 0 and b[j] == b[j-1]){ j++; continue; }
    if(a[i] < b[j]) cout<<a[i++]<<" ";
    if(a[i] > b[j]) cout<<b[j++]<<" ";
    else{
        cout<<a[i]<<" ";
        i++; j++;
    }
}
while(i < n){
    if(i > 0 and a[i] == a[i-1]){ i++; continue; }
    cout<<a[i++]<<" ";
}
while(j < m){
    if(j > 0 and b[j] == b[j-1]){ j++; continue; }
    cout<<b[j++]<<" ";
}


return 0;
}