#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void clook(int a[],int n,int head,string direction){
    
    int seek=0,mid=n-1;
    
    for(int i=0;i<n-1;++i)
        for(int j=0;j<n-i-1;++j)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
            
    for(int i=0;i<n;++i) if(a[i]>head){mid=i;break;}
    
    cout<<"\n\nSequence: ";
    
    if(direction=="left"){
        for(int i=mid-1;i>=0;--i)
        {
            cout<<a[i]<<"\t";
            seek+=abs(head-a[i]);
            head=a[i];
        }
        
        seek+=abs(head-a[n-1]);
        head=a[n-1];
        cout<<head<<"\t";
       
        for(int i=n-2;i>=mid;--i)
        {
            cout<<a[i]<<"\t";
            seek+=abs(head-a[i]);
            head=a[i];
        }
    }
    else if(direction=="right"){
        for(int i=mid;i<n;++i)
        {
            cout<<a[i]<<"\t";
            seek+=abs(head-a[i]);
            head=a[i];
        }
        
        seek+=abs(head-a[0]);
        head=a[0];
        cout<<head<<"\t";
        
        for(int i=1;i<mid;++i)
        {
            cout<<a[i]<<"\t";
            seek+=abs(head-a[i]);
            head=a[i];
        }
    }

    cout<<"\n\nTotal Head Movement: "<<seek;
    cout<<"\n\nAverage Head Movement: "<<seek/(float)n<<"\n\n";
}

int main(){
    int head,n,a[50];
    string direction;
    
    cout<<"Enter the number of requests: ";
    cin>>n;
    cout<<"Enter the Values of sequences: ";
    for(int i=0;i<n;++i) cin>>a[i];
    cout<<"Enter initial head position: ";
    cin>>head;
    cout<<"Enter the initial direction of movement(left/right): ";
    cin>>direction;
    if(direction!="left" && direction!="right"){ cout<<"Invalid Direction\n";exit(0);}
    
    clook(a,n,head,direction);
}