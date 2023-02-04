#include<bits/stdc++.h>

using namespace std;

int check[15];

void Try(int cur, int n, vector<int> &arr, int &k){
    for(int i=1; i<=n; i++){
        if(check[i]) continue;
        if(k==0) return;
        arr[cur] = i;
        if(cur == n-1){
            k--;
            //else k--;
            // else{
            //     cout<<k <<" ";
            //     for(int j=0; j<n; j++){
            //         cout<<arr[j];
            //     }
            //     cout<<endl;
            // }
        }
        else {
            check[i] = 1;
            Try(cur+1, n, arr, k);
            check[i] = 0;
        }

    }
}

vector<int> nthPermutation(int n, int k){
    vector<int> ans;
    for(int i=0; i<=n; i++){
        ans.push_back(i);
    }
    Try(0, n, ans, k);
    return ans;
}

int main(){
    int n, k;
    cin>> n>> k;
    vector<int> ans = nthPermutation(n, k);
    for(int i=0; i<n; i++)
        cout<<ans[i];
    return 0;
}