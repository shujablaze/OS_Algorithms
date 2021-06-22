#include <iostream>
#include <vector>

using namespace std;

struct process{
    int id, burst, art, tat, wt, rt, ct;
};

void arrange(vector<process*>& list,int n);
process * getnextprocess(vector<process*>& list,int& totburst,int num);

int main(){
    int num,totburst{0};
    vector<process*> processes;
    vector<process*> readyqueue;
    
    cout<<"Enter the number of processes: ";
    cin>>num;
    
    for(int i=0; i<num; ++i)
    {
        process* temp = new process;
        
        cout<<"Enter burst and arrival time for process "<<i+1<<": ";
        cin>>temp->burst>>temp->art;
        temp->id = i+1;
        
        processes.push_back(temp);
        readyqueue.push_back(temp);
    }
    
    arrange(readyqueue,num);
    
    for(int i=0;i<num;++i)
    {
        process *executable = getnextprocess(readyqueue,totburst,num);
        //execute(executable);
        cout<<"P"<<executable->id<<"->";

    }
    cout<<"End\n";
    
}

void arrange(vector<process*>& list,int n)
{
    for (int i=0;i<n-1;++i)
    {
        for (int j=0;j<n-i-1;++j)
        {
            if (list[j]->art > list[j+1]->art)
                swap(list[j],list[j+1]);
        }
    }
}

process * getnextprocess(vector<process*>& list,int& totburst,int num)
{
    process * min = list[0];
    int i{1},min_index{0};
    
    while(i < num && totburst >= list[i]->art)
    {
        if(list[i]->burst < min->burst)
            {
                min = list[i];
                min_index=i;
            }
        ++i;
    }
    
    totburst = totburst+min->burst;
    list.erase(list.begin() + min_index);
    
    return min;
}

//void execute(process*proc)
//{
    
//}