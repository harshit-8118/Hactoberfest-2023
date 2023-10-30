#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int h){
    int pivot = v[l];
    int p = l - 1;
    for(int i = l; i <= h; i++){
        if(v[i] <= pivot){
            ++p;
            swap(v[i], v[p]);
        }
    }
    swap(v[l], v[p]);
    return p;
}

void quickSort(vector<int> &v, int s, int e){
    if(s < e){
        int p = partition(v, s, e);
        quickSort(v, s, p-1);
        quickSort(v, p+1, e);
    }
}

int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int n; cin>>n;
vector<int> v(n);

for(auto &x: v) cin>>x;
quickSort(v, 0, n-1);

for(auto x: v){
    cout<<x<<" ";
}

return 0;
}