#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* bubblesortll(node* head)
{
    node *i = head;

    while(i){
        node *j=head;
        node *prev=head;
        while(j->next)
        {
            node* temp=j->next;
            if(j->data>temp->data)
            {
                if(j==head)
                {
                    j->next=temp->next;
                    temp->next=j;
                    prev=temp;
                    head=prev;
                }
                else{
                    j->next=temp->next;
                    temp->next=j;
                    prev->next=temp;
                    prev=temp;
                }
                continue;
            }
            prev=j;
            j=j->next;

        }
        i=i->next;
    }
    return head;
}

node* inputdata()
{
    int data;
    cout<<"enter data else enter 0"<<endl;
    cin>>data;
    node* head=NULL,*tail=NULL;
 
    while(data!= 0){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void printll(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head= inputdata();
    head=bubblesortll(head);
    printll(head);
}

