#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  priority_queue<pair<long,int>> q;       //優先度付きキュー<longとintのPair>
  for(int i=0;i<n;i++){
    long long int a;
    cin>>a;
    q.push(make_pair(a,1));               //入力値を1個ずつ格納
  }
  for(int i=0;i<m;i++){
    int b;
    long long int c;
    cin>>b>>c;
    q.push(make_pair(c,b));               //cをb個ずつ格納
  }
  long long int ans=0;
  for(int i=0;i<n;i++){
    auto p=q.top();                       //大きいものがtopに
    q.pop();
    ans+=p.first;
    if(p.second>1){                       //個数(=b)が2個以上なら1つ減らしてもう一度格納(次のiでもう一度)
      p.second--;
      q.push(p);
    }
  }
  cout<<ans<<endl;
}



//要検討
//queue,priority_queueについて
//pairについて
//comparatorについて
