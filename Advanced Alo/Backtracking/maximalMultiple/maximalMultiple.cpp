//-----LuvU-------
#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a; i<=b; ++i)


using namespace std;

int ans = -999999999;
int bit[100005];

int Calculate(int n, vector<int> arr){
    int sum[2], check[2];
    sum[0] = 0;
    sum[1] = 0;
    check[0] = 0;
    check[1] = 0;
    forr(i, 1, n){
        sum[bit[i]]+= arr[i-1];
        check[bit[i]]++;
    }
    if(!check[0] || !check[1])
        return -99999999;
    return sum[0] * sum[1];
}

void Try(int cur, int n, vector<int> arr){
    for(int i=0; i<=1; ++i){
        bit[cur] = i;
        if(cur == n){
            ans = max(ans , Calculate(n, arr));
            return;
        }
        Try(cur+1, n, arr);
    }
    return ;
}

int maximalMultiple(vector<int> arr){
    int n = arr.size();
    Try(1, n, arr);
    return ans;
}

int main(){
    int n;
    vector<int> arr;
    cin>>n;
    forr(i,1, n){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<< maximalMultiple(arr);
    return 0;
}