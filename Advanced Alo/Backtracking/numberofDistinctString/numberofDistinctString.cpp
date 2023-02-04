#include<bits/stdc++.h>

using namespace std;

char allString[30][5005];
int bit[30];
int allStringPos;
int MAXLENGTH = 9;
int DEFAULT_TEXT = '@';

// void printAllString(){
//     for(int i=1; i<=allStringPos; i++){
//         cout<<i<<" ";
//         for(int j=0; j<=MAXLENGTH; j++)
//             cout<<(allString[j][i]);
//         cout<<endl;
//     }
// }

int cmpString(string &s1, int pos){
    //1 la khac, 0 la giong
    for(int i=0; i<MAXLENGTH; i++){
        if(s1[i] != allString[i][pos])
            return 1;
    }
    return 0;
}

void Check(string &str){
    for(int i=1; i<=allStringPos; i++){
        if(!cmpString(str, i)) return;
    }
    allStringPos++;
    for(int i=0; i<MAXLENGTH; i++){
        allString[i][allStringPos] = str[i];
    }
    return;
}

void Record(int n, int bit[], string s, string c){
    string current;
    for(int i=0; i<MAXLENGTH; i++){
        current[i] = DEFAULT_TEXT;
    }
    int pos = 0;
    for(int i=0; i<n; i++){
        //cout<<bit[i];
        if(bit[i] == 1)
            current[pos++] = c[0];
        current[pos++] = s[i];
    }
    // for(int i=0; i<MAXLENGTH; i++)
    //     cout<<current[i];
    // cout<<endl;
    Check(current);
}

void Try(int cur, int n, string s, string c){
    for(int i=0; i<=1; i++){
        bit[cur] = i;
        if(cur == n){
            Record(n, bit, s,c);
            return;
        }
        Try(cur+1, n, s, c);
    }
}

int numberOfDistinctString(string s, string c)
{
    for(int i=0; i<=21; i++){
        for(int j=0; j<=500; j++){
            allString[i][j] = DEFAULT_TEXT;
        }
    }
    int n = (s.length());
    n++;
    Try(0, n, s, c);
    //printAllString();
    return allStringPos;
}

int main(){
    string s, c;
    cin>> s >> c;
    cout<< numberOfDistinctString(s, c) ;
    return 0;
}