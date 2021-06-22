#include <iostream>
#include <vector>

using namespace std;

struct process {
    int id, burst, art,priority, tat, wt, rt { -1 }, ct { 0 };
};

void arrange(vector<process*>& list, int n);
void displayresults(vector<process*>& readyqueue);
process * getnextprocess(vector<process*>& list,int& totburst,int num);

int main()
{
    int num,systime{0};

    vector<process*> processes;
    vector<process*> readyqueue;
    
    cout << "Enter the number of processes: ";
    cin >> num ;

    for(int i = 0; i < num; ++i) {
        process* temp = new process;

        cout << "Enter burst , arrival time , priority for process " << i + 1 << ": ";
        cin >> temp->burst >> temp->art >> temp->priority;
        temp->id = i + 1;
        processes.push_back(temp);
    }

    arrange(processes, num);
    
    for(int i=0;i<num;++i)
    {
        process *executable = getnextprocess(processes,systime,num);
        executable->ct = systime;
        readyqueue.push_back(executable);

    }
    displayresults(readyqueue);

}

void displayresults(vector<process*>& readyqueue)
{
    int wtime { 0 }, ctime { 0 }, rtime { 0 }, ttime { 0 };
    cout << "\nProcess ID\tBurst Time\tArrival time\tPriority\tWaiting Time\tTurnaround Time\tCompletion time\tResponse Time\n";
    for(int i = 0; i < readyqueue.size(); ++i) {
        readyqueue[i]->wt = readyqueue[i]->ct - readyqueue[i]->art - readyqueue[i]->burst;
        readyqueue[i]->tat = readyqueue[i]->ct - readyqueue[i]->art;

        cout << readyqueue[i]->id << "\t\t" << readyqueue[i]->burst << "\t\t" << readyqueue[i]->art << "\t\t"<<
        readyqueue[i]->priority<<"\t\t"<< readyqueue[i]->wt << "\t\t";
        cout << readyqueue[i]->tat << "\t\t" << readyqueue[i]->ct << "\t\t" << readyqueue[i]->rt << endl;

        wtime = readyqueue[i]->wt + wtime;
        ctime = readyqueue[i]->ct + ctime;
        rtime = readyqueue[i]->rt + rtime;
        ttime = readyqueue[i]->tat + ttime;
    }
    cout << "\nAverage waiting time:" << wtime / (float)readyqueue.size() << endl;
    cout << "Average completion time:" << ctime / (float)readyqueue.size() << endl;
    cout << "Average turn-around time:" << ttime / (float)readyqueue.size() << endl;
    cout << "Average response time:" << rtime / (float)readyqueue.size() << endl;

    cout << "\nGannt Chart\n\n";
    cout << "|";
    for(int i = 0; i < readyqueue.size(); ++i) {
        cout << "  P" << readyqueue[i]->id << "\t|";
    }
    cout << "\n0\t";
    for(int i = 0; i < readyqueue.size(); ++i) {
        cout << readyqueue[i]->ct << "\t";
    }
    cout<<endl;
}


process * getnextprocess(vector<process*>& list,int& totburst,int num)
{
    process * max_p = list[0];
    int i{1},min_index{0};
    
    while(i < num && totburst >= list[i]->art)
    {
        if(list[i]->priority < max_p->priority)
            {
                max_p = list[i];
                min_index=i;
            }
        ++i;
    }
    max_p->rt = totburst-max_p->art;
    totburst = totburst+max_p->burst;
    list.erase(list.begin() + min_index);
    
    return max_p;
}

void arrange(vector<process*>& list, int n)
{
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(list[j]->art > list[j + 1]->art)
                swap(list[j], list[j + 1]);
        }
    }
}