#include<bits/stdc++.h>
using namespace std;

// max-heapify
void heapify(vector<int> &v, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n and v[largest] < v[left]){
        largest = left;
    }
    if(right < n and v[largest] < v[right]){
        largest = right;
    }
    if(largest != i){
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void buildheap(vector<int> &v, int n){
    for(int i = (n-2)/2; i >= 0; i--){
        heapify(v, n, i);
    }
}

void heapsort(vector<int> &v, int n){
    buildheap(v, n);
    for(int i = n-1; i >= 0; i--){
        swap(v[i], v[0]);
        heapify(v, i, 0);
    }
}

int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int n; cin>>n;
vector<int> v(n);
for(auto &x: v) cin>>x;

heapsort(v, n);

for(auto x: v){
    cout<<x<<" ";
}

return 0;
}