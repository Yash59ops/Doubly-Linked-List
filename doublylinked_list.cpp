#include<iostream>
using namespace std;
class dll {
  private:
    struct node {
        int data;
        node*prev;
        node*next;
    };
    node*start;
  public:
    dll() {
        start=NULL;
    }
    void insertatfirst(int data) {
        node*n=new node;
        n->data=data;
        n->next=start;
        n->prev=NULL;
        if(start==NULL) {
            start=n;
        } else {
            start->prev=n->next;
        }

    }
    void insertatlast(int data) {
        node*n=new node;
        n->data=data;
        n->next=NULL;
        if(start==NULL) {
            n->prev=NULL;
            start=n;
        } else {
            node*t=start;
            while(t->next!=NULL) {
                t=t->next;
            }
              t->next=n;
              n->prev=t;
        }
    }
    void delatfirst(){
    node*t=start;
    if(start==NULL){
        cout<<"underflow";
    }else{
    if(t->next==NULL){
        start=NULL;
        delete t;
    }else{
    start=t->next;
     start->prev=NULL;
     delete t;
    }
    }

    }

    void display(){
    node*t=start;
    while(t){
        cout<<t->data;
        t=t->next;
    }

    }
};
int main() {
dll obj;
obj.insertatlast(1);
obj.insertatlast(2);
obj.insertatlast(3);
obj.insertatlast(4);
obj.insertatlast(5);
obj.display();

    return 0;
}
