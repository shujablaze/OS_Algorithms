#include <iostream>
#include <string>

using namespace std;

struct node * addProcess(struct node *head);
void display(struct node *head);
struct node * execute(struct node *head);

struct node{
    string process;
    int priority;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    int choice;
    
    while(true)
    {
        cout<<"\n------Menu------\n";
        cout<<"1.Add Process\n2.Execute\n3.Exit"<<endl;
        cin>>choice;
    

        switch(choice)
        {
            case 1:
                    head = addProcess(head);
                    display(head);
                    break;
            case 2:
                    head = execute(head);
                    display(head);
                    break;
            case 3:
                    exit(10);
                    
            default:cout<<"Invalid\n";
        }
        
    }
}

struct node * execute(struct node *head)
{
    if(head == NULL)
    {
        cout<<"No process pending"<<endl;
        return head;
    }
    cout<<head->process<<" was executed. ";
    
    return head->next;
}

struct node * addProcess(struct node *head)
{
    struct node *temp = new node;
    
    temp->next = NULL;
    
    cout<<"Enter the name of process and priority: ";
    cin>> temp->process >> temp->priority;
    
    if (head==NULL)
    {
        head = temp;
        return head;
    }
    else if(temp->priority < head->priority)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    else
    {
        struct node *p1=head;
        
        while(p1->next != NULL)
        {
        
            if(temp->priority < p1->next->priority)
            {
                temp->next = p1->next;
                p1->next = temp;
                return head;
            }
            p1 = p1->next;
        }
        p1->next = temp;
        return head;
    }
    return head;
}

void display(struct node *head)
{
    struct node* temp = head;
    
    cout<<"\nProcess queue: ";
    while(temp!=NULL)
    {
        cout<<"["<<temp->process<<"|"<<temp->priority<<"]"<<"-->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}