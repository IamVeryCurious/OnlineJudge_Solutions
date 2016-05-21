#include <fstream>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
struct nodeT{
    int left,right;
};
class BinaryTree{
    public:
        nodeT *array;
        int size,root,censhu,cnt_last,cnt_last_one;
        bool the_last[100000];
        BinaryTree(int a[][2],int n){
            censhu=0;cnt_last = 0;
            bool visit[100005];
            memset(visit,0,sizeof(visit));
            memset(the_last,0,sizeof(the_last));
            array = new nodeT[n+1];
            size = n;
            array[0].left = 0;array[0].right = 0;
            for(int i=1;i<=n;i++){
                array[i].left = a[i][0];
                array[i].right = a[i][1];
                visit[a[i][0]]=1;visit[a[i][1]]=1;
            }
            for(int i=1;i<=n;i++){
                if(visit[i]==0){root = i;}
            }
            while(n>0){
                n/=2;censhu++;
            }
            censhu-=1;
        }
        void traverse(){
            //cout<<"root is"<<root<<" "<<"censhu is"<<censhu<<endl;
            for(int i=1;i<=size;i++){
                cout<<array[i].left<<" "<<array[i].right<<endl;
            }
        }
        void get_last(int n,int start_point){
            //cout<<"now is "<<start_point<<" censhu is "<<n<<endl;
            if(n==censhu){
                if(start_point!=0){cnt_last_one++;}
                the_last[cnt_last++] = start_point;
                return;
            }
            else{
                get_last(n+1,array[start_point].left);
                get_last(n+1,array[start_point].right);
            }
        }
        ~BinaryTree(){delete[]array;}
};
int main(){
    //ifstream cin("ha.txt");
    int n,a[100005][2],above;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    BinaryTree tree(a,n);
    tree.get_last(0,tree.root);
    above = pow(2,tree.censhu) - 1;
    //cout<<above+tree.cnt_last_one<<endl;
    if(tree.cnt_last_one+above!=n){cout<<"N"<<endl;return 0;}
    if(tree.the_last[0] ==0 ){cout<<"N"<<endl;return 0;}
    for(int i=1;i<tree.cnt_last;i++){
        if(tree.the_last[i]&&!tree.the_last[i-1]){cout<<"N"<<endl;return 0;}
    }
    cout<<"Y"<<endl;return 0;
 
}
