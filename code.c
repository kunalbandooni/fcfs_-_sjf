#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int id,val;
    struct node *next;
}nodetype;
int n=0;
void fcfs(nodetype *p){
    printf("\n\nFCFS Job Order:\n");
    printf("FCFS Jobs will be executed in the order they arrived:\n");
    printf("Linked List Contain the following values:\n");
    while(p!=NULL){
        printf("Node ID %d with value %d\n",p->id,p->val);
        p=p->next;
    }
    printf("FCFS Done\n\n");
}
nodetype* enqueue(nodetype *rear){
    nodetype *p;
    int m;
    printf("\nEnter an ID and a value for a node to add to the list, Enter -1 to stop: ");
    scanf("%d %d",&n,&m);
    if(n==-1)
        return rear;
    p=(nodetype *)malloc(sizeof(nodetype));
    if(p!=NULL){
        p->id=n;
        p->val=m;
        if(rear==NULL)
            rear=p;
        else{
            rear->next=p;
            rear=p;
        }
        rear->next=NULL;
    }
    return rear;
}
void sjf(nodetype *f){
    nodetype *current=f,*index = NULL;  
    int temp;  
    if(f==NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
            index = current->next;  
            while(index != NULL) {  
                if(current->val > index->val) {  
                    temp = current->val;  
                    current->val = index->val;  
                    index->val = temp;
                    temp = current->id;
                    current->id = index->id;
                    index->id=temp;
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }
    printf("\nSJF Jobs Order:\n");
    while(f!=NULL){
        printf("Shortest Job to Run next is with ID: %d and Time %d\n",f->id,f->val);
        f=f->next;
    }
    printf("SJF: All Jobs Completed");
}
int main(){
    nodetype *first=NULL,*last=NULL;
    while(n!=-1){
        last=enqueue(last);
        if(first==NULL)
            first=last;
    }
    fcfs(first);
    sjf(first);
    printf("\nAll Threads completed");
    return 0;
}
