#include<iostream>
#include<cstdlib>

using namespace std;

void fcfs(int a[],int n,int head)
{
	int head_mov=0,distance=0,cur_track;
	for(int i=0;i<n;i++)
	{
		cur_track=a[i];
		distance=abs(head-cur_track);
		head=cur_track;
		head_mov+=distance;
	}
	
	cout<<"\nSeek Sequence:";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
    cout<<"\n\nTotal head movement or seek time:"<<head_mov;
	cout<<"\nAverage Head Movement:"<<head_mov/(float)n;
    cout<<"\n\n";
}

int main()
{
	int n,head,a[50];
	cout<<"Enter The Total Number of Requests:";
	cin>>n;
	cout<<"Enter The Value of Requests:";
	for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter The Value of Head:";
	cin>>head;
	fcfs(a,n,head);
}
