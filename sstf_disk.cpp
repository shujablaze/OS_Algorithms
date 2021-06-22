#include <iostream>
#include <cstdlib>

using namespace std;

void sstf(int a[],int n,int head){
    int min=0,seek=0;
    cout<<"\nSequence: ";
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j){
            if(abs(head-a[min])>abs(head-a[j])) min=j;
        }
        seek+=abs(head-a[min]);
        head=a[min];
        cout<<head<<"\t";
        a[min]=10000;
    }
    //cout<<head;
    cout<<"\n\nTotal Head Movement: "<<seek;
    cout<<"\nAverage Head Movement: "<<seek/(float)n<<"\n\n";
}

int main(){
    int n,head,a[50];
	cout<<"Enter The Total Number of Requests:";
	cin>>n;
	cout<<"Enter The Value of Requests:";
	for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter The Value of Head:";
	cin>>head;
	sstf(a,n,head);
}