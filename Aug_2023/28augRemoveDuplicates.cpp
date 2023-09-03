#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node *removeDuplicates(Node *root);
int main()
{
    int t;
    cin>>t;

    while(t--){
        int k;
        cin>>k;
        Node *head = NULL;
        Node *temp = head;

        for(int i=0; i<k; i++){
            int data;
            cin>>data;

            if(head == NULL){
                head = temp = new Node(data);
            }
            else{
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Node *result = removeDuplicates(head);
        print(result);
        cout<<endl;
    }
    return 0;
}
Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}