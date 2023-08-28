'''
Node *curr=head;
 Node*temp=head;
 while(curr->next!=NULL){
    if(curr->data !=curr->next->data){
        temp->next=curr->next;
        temp=curr->next;
    } 
    
    curr=curr->next;
 }
 temp->next=NULL;
 return head;	
 '''	