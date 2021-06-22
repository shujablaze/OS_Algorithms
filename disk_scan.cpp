#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void scan(int a[],int n,int head,string direction,int size){
    
    int seek=0,mid=n-1,mid_seq=0,count=0;
    
    if(direction=="right") mid_seq=size-1;
    
    for(int i=0;i<n-1;++i)
        for(int j=0;j<n-i-1;++j)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
            
    for(int i=0;i<n;++i) if(a[i]>head){mid=i;break;}
    
    cout<<"\n\nSequence: ";
    
    while(count!=2){
        if(direction=="left"){
            for(int i=mid-1;i>=0;--i)
            {
                cout<<a[i]<<"\t";
                seek+=abs(head-a[i]);
                head=a[i];
            }
            if(mid_seq==0){cout<<"0\t";seek+=head;head=0;}
            direction="right";
        }
        else if(direction=="right"){
            for(int i=mid;i<n;++i)
            {
                cout<<a[i]<<"\t";
                seek+=abs(head-a[i]);
                head=a[i];
            }
            if(mid_seq!=0){cout<<mid_seq<<"\t";seek+=abs(head-mid_seq);head=mid_seq;}
            direction="left";
        }
        ++count;
    }
    cout<<"\n\nTotal Head Movement: "<<seek;
    cout<<"\n\nAverage Head Movement: "<<seek/(float)n<<"\n\n";
}

int main(){
    int size,head,n,a[50];
    string direction;
    
    cout<<"Enter the size of the disk: ";
    cin>>size;
    cout<<"Enter the number of requests: ";
    cin>>n;
    cout<<"Enter the Values of sequences between 1-"<<size-1<<": ";
    for(int i=0;i<n;++i) cin>>a[i];
    cout<<"Enter initial head position: ";
    cin>>head;
    cout<<"Enter the initial direction of movement(left/right): ";
    cin>>direction;
    if(direction!="left" && direction!="right"){ cout<<"Invalid Direction\n";exit(0);}
    
    scan(a,n,head,direction,size);
}