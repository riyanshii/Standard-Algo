#include <bits/stdc++.h>
using namespace std;

class Node {
      public:
       int data;
       Node *next;
};

 Node *head, *curr_node,*temp,*temp1;

int main() {

    int size, elem;

    cout<<"Enter size: ";
    cin>>size;
    cout<< "\n";

    head = new Node;
    head->data = 1000;
    head->next = NULL;

    for(int i = 1; i <= size; ++i) {
        cin>>elem;

        curr_node = new Node;
        curr_node->data = elem;

        if(curr_node->data < head->data) {

           curr_node->next = head;
           head = curr_node;

        } else {

          temp = head;
          temp1 = temp->next;

          while(temp1->data < elem) {

                temp = temp->next;
                temp1 = temp1->next;
          }

          temp->next = curr_node;
          curr_node->next = temp1;

        }

    }

    temp = head;
    cout<< "sorted is : ";
    while(temp->data != 1000) {

          cout<<temp->data<<" ";
          temp = temp->next;
    }

 return(0);
};
