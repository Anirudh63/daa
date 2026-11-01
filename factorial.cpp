#include<bits/stdc++.h>
using namespace std;

int factrec(int n){
    if(n<=1) return n;
    return factrec(n-1)+factrec(n-2);
}

int factiter(int n){
    int a=0,b=1,c=1;
    if(n<=1) return n;
    for(int i=2 ; i<=n ; i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    n--;
    cout<<factrec(n)<<endl;
    cout<<factiter(n)<<endl;
}