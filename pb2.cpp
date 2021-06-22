#include <iostream>
#include <iomanip>

using namespace std;

void display(int fields[15][7],int num,int ttime,int waittime,int comtime,int restime,int totburst);

int main(){
    
    int num;
    int ttime{0},waittime{0},comtime{0},restime{0},totburst{0};
    int fields[15][7];
    
    cout<<"Enter the number of Processes: ";
    cin>>num;
    //Inputting th values
    for(short i = 0; i < num; ++i){
        cout<<"Enter burst and arrival time for process "<<i+1<<" : ";
        //name of process
        fields[i][0] = i+1;
        
        for(short j = 1; j<3;++j){
            cin>>fields[i][j];
        }
    }
    //Making output table
    for(short i=0;i<num;++i){
        
        if(i==0){
            //i1=Burst time     i3=waiting time      i4=response time     i5=turnaround       i6=completion time
            fields[i][3] = 0;
            fields[i][4] = fields[i][3];
            fields[i][5] = fields[i][1];
            fields[i][6] = fields[i][5] +fields[i][2];
            //Initiatizing totals for average
            ttime = ttime + fields[i][5];
            waittime = waittime + fields[   i][3];
            totburst = fields[i][1];
            restime = waittime;
            comtime = comtime + fields[i][6];
        }
        else{
            //Waiting time = Previous bursts - Arrival time
            fields[i][3] = totburst - fields[i][2];
            if (fields[i][3]<0){
                fields[i][3] = 0;
            }
            fields[i][4] = fields[i][3];
            //turnaround = burst time + waiting time
            fields[i][5] = fields[i][1] + fields[i][3];
            //completion time = arrival + turnaround
            fields[i][6] = fields[i][2] + fields[i][5];
        
            //Calculating the final total values of columns
            ttime = ttime + fields[i][5];
            waittime = waittime + fields[i][3];
            totburst = totburst + fields[i][1];
            restime = waittime;
            comtime = comtime + fields[i][6];
        }
    }
    display(fields,num,ttime,waittime,comtime,restime,totburst);
}

void display(int fields[15][7],int num,int ttime,int waittime,int comtime,int restime,int totburst)
{
    cout<<endl;
    cout<<setw(17)<<"Processes |"<<setw(17)<<"Burst time |"<<setw(17)<<"Arrival Time |"<<setw(17)<<"Waiting Time |"<<setw(15)<<" Response Time |"<<setw(15)<<"Turn around |"<<setw(15)<<" Completion time  |"<<endl;
    cout<<endl;
    for(short i=0;i<num;++i)
    {
        for(short j=0;j < 7;++j){
            cout<<setw(15)<<fields[i][j];
        }
            cout<<endl<<endl;;
    }
    
    
    cout<<"Average wait time = "<<(float)waittime/(float)num<<endl;
    cout<<"Average turn-around time = "<<(float)ttime/(float)num<<endl;
    cout<<"Average response time = "<<(float)restime/(float)num<<endl;
    cout<<"Average completion time = "<<(float)comtime/(float)num<<endl;
    
    cout<<"\nGANTT CHART"<<endl<<endl;
    
    totburst = fields[0][1];
    cout<<"|0";
    for(short i=0;i<num;++i)
    {   
        cout<<"    "<<"P"<<fields[i][0]<<"    "<<totburst<<"|"<<totburst;
        totburst = totburst+fields[i+1][1];
    }
    cout<<endl;
}