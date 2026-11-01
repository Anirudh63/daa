#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int fr;
    node *left,*right;
    node(char c,int f){
        ch=c;
        fr=f;
        left=NULL;
        right=NULL;
    }
};

struct compare{
    bool operator()(node *a,node *b){
        return a->fr > b->fr;
    }
};

void printcodes(node *temp,string code=""){
    if(temp==NULL) return ;
    if(!temp->left && !temp->right){
        cout<<temp->ch<<" "<<code<<endl;
        return ;    
    }
    printcodes(temp->left, code + "0");
    printcodes(temp->right, code + "1");
}

int main(){
    int n;
    cin >> n;
    priority_queue<node*,vector<node*>,compare>pq;
    for(int i=0 ; i<n ; i++){
        char ch;
        int fr;
        cin >> ch >> fr;
        pq.push(new node(ch,fr));
    }    
    while(pq.size()>1){
        node *le=pq.top();
        pq.pop();
        node*ri=pq.top();
        pq.pop();

        node * parent=new node('$',le->fr + ri->fr);
        parent->left=le;
        parent->right=ri;
        pq.push(parent);
    }
    printcodes(pq.top(),"");
}