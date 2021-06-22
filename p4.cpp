#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct process {
    int id, burst, art, tat, wt, rt { -1 }, ct { 0 };
};

void arrange(vector<process*>& list, int n, vector<int>& burstimes);
void setreadyqueue(vector<process*>& processes, vector<process*>& ready, int systime);
process* getprocess(vector<process*>& list);
void makegant(process* curprocess, vector<pair<int, int>>& chart, int sys);
void displayresults(vector<process*>& readyqueue, vector<int>& burstimes, vector<pair<int, int>>& gannt);

int main()
{
    int num, maxtime { 0 };

    vector<process*> processes;
    vector<process*> readyqueue;
    vector<pair<int, int>> gannt;
    vector<int> burstimes;

    cout << "Enter the number of processes: ";
    cin >> num;

    for(int i = 0; i < num; ++i) {
        process* temp = new process;

        cout << "Enter burst and arrival time for process " << i + 1 << ": ";
        cin >> temp->burst >> temp->art;
        temp->id = i + 1;
        maxtime = maxtime + temp->burst;
        processes.push_back(temp);
    }

    arrange(processes, num, burstimes);

    for(int i = 0; i < maxtime; ++i) {
        setreadyqueue(processes, readyqueue, i);

        if(readyqueue.size() > 0) {
            process* curprocess = getprocess(readyqueue);
            curprocess->burst = curprocess->burst - 1;

            if(curprocess->rt == -1)
                curprocess->rt = i - curprocess->art;

            curprocess->ct = i + 1;
            makegant(curprocess, gannt, i + 1);
        }
    }
    displayresults(readyqueue, burstimes, gannt);
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
        cout << "  P" << gannt[i].first << "  |";
    }
    cout << "\n0      ";
    for(int i = 0; i < gannt.size(); ++i) {
        cout << gannt[i].second << "      ";
    }
}

void makegant(process* curprocess, vector<pair<int, int>>& chart, int sys)
{
    pair<int, int> temp;
    if(chart.size() > 0) {
        int index = chart.size() - 1;

        if(chart[index].first == curprocess->id) {
            chart[index].second++;
            return;
        } else {
            temp.first = curprocess->id;
            temp.second = sys;
            chart.push_back(temp);
            return;
        }
    }
    temp.first = curprocess->id;
    temp.second = sys;
    chart.push_back(temp);
}

process* getprocess(vector<process*>& list)
{
    process* min;

    for(int i = 0; i < list.size(); ++i) {
        if(list[i]->burst > 0) {
            min = list[i];
            break;
        }
    }

    for(int i = 0; i < list.size(); ++i) {
        if(list[i]->burst > 0 && list[i]->burst <= min->burst) {
            min = list[i];
        }
    }
    return min;
}

void setreadyqueue(vector<process*>& processes, vector<process*>& ready, int systime)
{
    for(int i = 0; i < processes.size(); ++i) {
        if(processes[i]->art > systime)
            return;
        else {
            ready.push_back(processes[i]);
            processes.erase(processes.begin() + i);
        }
    }
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