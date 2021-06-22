#include <iostream>
#include <string>

using namespace std;

int main()
{
    int space_occupied[25],total_space[25],process_size[25],fragmentation[25],block_name[25];
    string process_name[25],allocated[25];
    
    int num;
    int tif{0};//Total Internal Fragmentation
    
    cout<<"Enter the number of memory blocks: ";
    cin>>num;
    // Taking info on memory blocks
    for(short i=0;i<num;i++)
    {
        cout<<"Enter size of memory block "<<i+1<<" : ";
        block_name[i]=i+1;
        cin>>total_space[i];
        space_occupied[i]=0;
    }
    cout<<endl;
    // Taking info about processes
    for(short i=0;i<num;++i)
    {
        cout<<"Enter process name and size for process "<<i+1<<" : ";
        cin>>process_name[i]>>process_size[i];
        allocated[i]="Nil";
        fragmentation[i]=0;
    }
    //Best fit
    for(short i=0;i<num-1;++i)
        for(short j=0;j<num-i-1;++j)
        {
            if(total_space[j]>total_space[j+1])
            {
                swap(total_space[j],total_space[j+1]);
                swap(block_name[j],block_name[j+1]);
            }
        }

    for(short i=0;i<num;++i)
        for(short j=0;j<num;++j)
        {
            if(process_size[i]<=total_space[j] && space_occupied[j]==0)
            {
                allocated[i]=to_string(block_name[j]);
                space_occupied[j]=process_size[i];
                fragmentation[i]=total_space[j]-space_occupied[j];
                tif=tif+fragmentation[i];
                break;
            }
        }
    cout<<endl;
    
    cout<<"Process Name\tProcess Size\tBlock Allocated\t  Internal Fragmentation\n";
    
    for(short i=0;i<num;++i)
    {
        cout<<process_name[i]<<"\t\t"<<process_size[i]<<"\t\t"<<allocated[i]<<"\t\t  "<<fragmentation[i]<<endl;
    }
    
    int tef{0};
    //Checking for external fragmentation
    for(short i=0;i<num;++i) if(space_occupied[i]==0) tef=tef+total_space[i];
    
    cout<<endl;
    cout<<"Total Internal Fragmentation: "<<tif<<endl;
    cout<<"Total External Fragmentation: "<<tef<<endl<<endl;
}