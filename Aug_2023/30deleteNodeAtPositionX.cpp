// We have to delete the node which is at Xth position 

Node *deleteNode(Node *head, int x){
    if(x == 1) //if position is 1 then simple head ko head ke next pr kr do
    {
        head = head->next;
    }
    int pos = 0; //To count the position 
    Node *temp = head; //temporary pointer which will traverse in the lindexlist
    while(temp->next != NULL){
        pos += 1;
        if(pos == x-1){  //agr jis position ke element ko delete krna hai, us position se pehle aap poch gae ho to vahi se uske next ko next ka next krdo
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;  //otherwise simply ek aage badh jao
        }
    }
    return head;
}