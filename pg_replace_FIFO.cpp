#include <iostream>
#include <string>

using namespace std;

void replace_page(char *arr,int num,int& front,int& tail,char value)
{
    front = (front + 1) % num;  // REMOVING PAGE AT FRONT OF QUEUE (NOT NECESSARY AS WE DISPLAY QUEUE IN THE SAME ORDER, DOIN IT ANYWAY)
    tail = (tail + 1) % num;    // MOVING TAIL
    *(arr+tail) = value;        // REPLACING THE FRONT VALUE TO GET A NEW TAIL(CIRCULAR QUEUE ORDER FRONT--->TAIL)
}

void make_table(char *arr,int num,int curr_page,bool islast,int tot_page)
{
    char table[50][50];
    if(!islast) // MAKING THE TABLE
        for(short i=0;i<num;++i) table[i][curr_page]=*(arr+i);
    else
    {   //PRINTING THE TABLE AFTER LAST ITERATION
        for(short i=0;i<num;++i){
            cout<<"FRAME["<<i<<"]\t";
            for(short j=0;j<tot_page;++j) cout<<table[i][j]<<"\t";
            cout<<"\n";
        }
    }
}

bool in_ram(char *arr,int num,char value){
    for(short i=0;i<num;++i) if(*(arr+i)==value) return true;
    return false;
}

int main(){
    int num,front{0},tail,pg_fault{0},pg_num;
    char ref_string[50];
    string outcomes[50];
    
    cout<<"Enter The Number of Frames: ";
    cin>>num;
    tail=num-1;
    
    cout<<"Enter The Total Number of Pages: ";
    cin>>pg_num;
    
    cout<<"Enter The Reference String: ";
    for(short i=0;i<pg_num;++i) cin>>ref_string[i];
    
    char ram[50];
    for(short i=0;i<num;i++) ram[i]='X';
    
    short i{0};
    for(i=0;i<pg_num;++i){
        string result="MISS";
        if(in_ram(ram,num,ref_string[i])) result="HIT";
        else{
            replace_page(ram,num,front,tail,ref_string[i]);
            pg_fault++;
        }
        make_table(ram,num,i,0,pg_num);
        outcomes[i]=result;
    }
    //OUTPUT FORMATTINGS
    cout<<"\nPAGE\t\t";
    for(short i=0;i<pg_num;++i) cout<<ref_string[i]<<"\t";
    cout<<"\n\n";
    make_table(ram,num,i,1,pg_num);
    cout<<"\nOUTCOME\t\t";
    for(short i=0;i<pg_num;++i) cout<<outcomes[i]<<"\t";
    cout<<"\n\nPage Faults = "<<pg_fault;
    cout<<"\nHits = "<<pg_num-pg_fault;
    cout<<"\nAvgerage Page Faults = "<<pg_fault/(float)pg_num;
    cout<<"\n\n";
}