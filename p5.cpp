#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct process {
    int id, burst, art, tat, wt, rt { -1 }, ct { 0 };
};

void arrange(vector<process*>& list, int n, vector<int>& burstimes);
void displayresults(vector<process*>& readyqueue, vector<int>& burstimes, vector<pair<int, int>>& gannt);

int main()
{
    int num, maxtime { 0 },quantum;

    vector<process*> processes;
    vector<process*> readyqueue;
    vector<pair<int, int>> gannt;
    vector<int> burstimes;

    cout << "Enter the number of processes and quantum time: ";
    cin >> num >> quantum;

    for(int i = 0; i < num; ++i) {
        process* temp = new process;

        cout << "Enter burst and arrival time for process " << i + 1 << ": ";
        cin >> temp->burst >> temp->art;
        temp->id = i + 1;
        maxtime = maxtime + temp->burst;
        processes.push_back(temp);
        readyqueue.push_back(temp);
    }

    arrange(processes, num, burstimes);
    int systime{0};
    
    while(readyqueue.size()!=0)
    {   int j=0;
        while( j<readyqueue.size())
        {   
            pair<int,int> temp;
            
            if(readyqueue[j]->rt==-1) readyqueue[j]->rt = systime - readyqueue[j]->art;
            
            if(readyqueue[j]->burst-quantum <= 0)
            {
                systime = systime + readyqueue[j]->burst;
                readyqueue[j]->burst = 0;
                //gannt
                temp.first = readyqueue[j]->id;
                //removing completed process
                readyqueue[j]->ct = systime;
                readyqueue.erase(readyqueue.begin()+j);
                j--;
            }
            else{
                systime =  systime + quantum;
                readyqueue[j]->burst -= quantum;
                temp.first = readyqueue[j]->id;
            }
            //gant
            temp.second = systime;
            gannt.push_back(temp);
            j++;
        }
    }
    displayresults(processes, burstimes,  gannt);
    
}

void displayresults(vector<process*>& readyqueue, vector<int>& burstimes, vector<pair<int, int>>& gannt)
{
    int wtime { 0 }, ctime { 0 }, rtime { 0 }, ttime { 0 };
    cout << "\nProcess ID\tBurst Time\tArrival time\tWaiting Time\tTurnaround Time\tCompletion time\tResponse Time\n";
    for(int i = 0; i < readyqueue.size(); ++i) {
        readyqueue[i]->wt = readyqueue[i]->ct - readyqueue[i]->art - burstimes[i];
        readyqueue[i]->tat = readyqueue[i]->ct - readyqueue[i]->art;

        cout << readyqueue[i]->id << "\t\t" << burstimes[i] << "\t\t" << readyqueue[i]->art << "\t\t"
             << readyqueue[i]->wt << "\t\t";
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
    for(int i = 0; i < gannt.size(); ++i) {
        cout << "  P" << gannt[i].first << "\t|";
    }
    cout << "\n0\t";
    for(int i = 0; i < gannt.size(); ++i) {
        cout << gannt[i].second << "\t";
    }
    cout<<endl;
}

void arrange(vector<process*>& list, int n, vector<int>& burstimes)
{
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(list[j]->art > list[j + 1]->art)
                swap(list[j], list[j + 1]);
        }
    }
    for(int i = 0; i < n; ++i) {
        burstimes.push_back(list[i]->burst);
    }
}