#include<bits/stdc++.h>

using namespace std;

int ans;
int got[10005];
int used[10005];

void BackTrack(int cur, int n, int k, int sum, vector<int> arr){
    // for(int i=0; i<n; i++){
    //     cout<<used[arr[i]]<<" ";
    // }
    // cout<<sum<<endl;
    if(cur == n){
        if(sum == k) {
            ans++;
            //cout<<"get"<<endl;
        }
        return;
    }
    if(cur != 0 && (arr[cur] == arr[cur-1])){
        // cout<<cur+1<<" "<<" "<<sum<< " ";
        //     for(int j=0; j<n; j++){
        //     cout<<used[arr[j]]<<" ";
        //     }
        //     cout<<endl;
        BackTrack(cur+1, n, k, sum, arr);
    }
    else{
        for(int i=0; i<=got[arr[cur]]; i++){
            used[arr[cur]] = i;
            // cout<<cur+1<<" "<<sum + arr[cur] * used[arr[cur]]<<" ";
            //     for(int j=0; j<n; j++){
            //     cout<<used[arr[j]]<<" ";
            //     }
            //     cout<<endl;
            BackTrack(cur+1, n, k, sum + arr[cur] * used[arr[cur]], arr);
        }
        used[arr[cur]] = 0;
    }
}

void PreProcess(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    for(int i=0; i<= n-1; i++)
        got[arr[i]]++;
}

int combinationSum(vector<int> arr, int k){
    int n = arr.size();
    PreProcess(arr, n);
    BackTrack(0, n, k, 0, arr);
    return ans;
}

int main(){
    freopen("combinationSum.inp", "r", stdin);
    //freopen("combinationSum.out", "w", stdout); 
    int n;
    vector<int> arr;
    int k;
    cin>> n;
    for(int i=1; i<=n; i++){
        int x;
        cin>> x;
        arr.push_back(x);
    }
    cin>>k;
    cout<<combinationSum(arr, k);
}