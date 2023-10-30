#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE     //     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/debug.h"
#include "Algo/debug.h"
#else
#define fix(x)
#endif

void countSort(vector<int> &v, int exp){
    int n = v.size();
    vector<int> count(10), output(n);
    for(int i = 0; i < n; i++){
        count[(v[i]/exp)%10]++;
    }
    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    for(int i = n-1; i >= 0; i--){
        output[count[(v[i]/exp)%10] - 1] = v[i];
        count[(v[i]/exp)%10]--;
    }
    v = output;
}

void radixSort(vector<int> &v){
    int mxele = *max_element(v.begin(), v.end());
    for(int e = 1; mxele / e > 0; e *= 10){
        countSort(v, e);
        fix(v)
    }
}


int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

#ifndef ONLINE_JUDGE     //     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    #include "Algo/config.h"
#endif

int n; cin>>n;
vector<int> v(n);

for(auto &x: v) cin>>x;
radixSort(v);

for(auto x: v){
    cout<<x<<" ";
}


return 0;
}