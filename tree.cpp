#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1;

struct Node{
  int parent;
  int left;   //左子
  int right;  //右兄弟
};
struct Node T[MAX];
int D[MAX];   //節点の深さ
int n;        //節点の数

void print(int node){
  int c=T[node].l;
  cout<<"node "<<node<<": ";
  cout<<"parent="<<T[node].p<<",";
  cout<<"depth="<<D[node]<<",";
  if(T[node].p==NIL) cout<<"root,";
  else if(T[node].l==NIL) cout<<"leaf,";
  else cout<<"internal node,";
  cout<<"children=[";
  for(int i=0;c!=NIL;c==T[c].r){
    if(i) cout<<",";
    cout<<c;
  }
  cout<<"]"<<endl;
}

int setDepth(int node,int p){
  D[u]=p;
  if(T[node].r!=NIL) setDepth(T[u].r,p);
  if(T[node].l!=NIL) setDepth(T[u].l,p-1);
}

int main(){
  int a;    //node番号
  int cnum; //子の数
  int c;    //子要素
  int r;    //根のnode番号
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>cnum;
    for(int j=0;j<cnum;j++){
      cin>>c;
      if(j==0)　T[a].l=c;  //一番左の子に設定
      else T[l].r=c;　　　 //一番右の子の右の兄弟に設定
      l=c;　　　　　　　　  //一番右の子
      T[c].p=a;　　　　　　 //親要素をaにする
    }
  }
  for(int i=0;i<n;i++){
    if(T[i].p==NIL) r=i;   //根を設定
  }
  setDepth(r,0);     //各節点の深さを設定
  for(int i=0;i<n;i++) print(i);
  return 0;
}
