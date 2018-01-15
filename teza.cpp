#include<iostream>
using namespace std;
struct Duble{
    int value;
    Duble * prev, * next;
};
struct Stack{
    int length;
    Duble *start, *current, *last;
};
Stack *mystack = new Stack;
int init(){
    mystack->length = 0;
    mystack->start = mystack->current = mystack->last = NULL;
}
int push(int toadd, int direction){
    if(mystack->length == 0){
        Duble *morty = new Duble;
        morty->value = toadd;
        mystack->start = mystack->current = mystack->last = morty;
        mystack->start->prev = NULL;
        mystack->last->next = NULL;
        mystack->length++;
        return 0;
    }
    Duble *morty = new Duble;
    morty->value = toadd;
    if(direction == 0){
            if(mystack->current == mystack->start){
                morty->next = mystack->start;
                morty->prev = NULL;
                mystack->start->prev = morty;
                mystack->start = morty;
                mystack->length++;
            }
            else{
                morty->next = mystack->current;
                morty->prev = mystack->current->prev;
                mystack->current->prev->next = morty;
                mystack->current->prev = morty;
                mystack->length++;
            }
    }
    else if (direction == 1){
        if(mystack->current == mystack->last){
            morty->next = NULL;
            morty->prev = mystack->current->prev;
            mystack->current->next = morty;
            mystack->last = morty;
            mystack->length++;
        }
        else{
            morty->prev = mystack->current;
            morty->next = mystack->current->next;
            mystack->current->next->prev = morty;
            mystack->current->next = morty;
            mystack->length++;
        }
    }
}
int pop(int old, int direction){
    if(mystack->length == 0){
        cout<<"stiva este goala.."<<endl;
        return 0;
    }
    if(mystack->length == 1){
        old = mystack->current->value;
        mystack->current = mystack->last = mystack->start = NULL;
        mystack->length--;
        cout<<"am scos "<<old<<endl;
        return 0;
    }
    mystack->current->prev->next = mystack->current->next;
    mystack->current->next->prev = mystack->current->prev;
    old = mystack->current->value;
    if(direction == 0){
            mystack->current = mystack->current->prev;
            cout<<"am scos "<<old;
    }
    if(direction == 1){

    }
}
int main()
{
    init();
    push(1,0);
    cout<<mystack->start->value<<endl;
    push(2,1);
    cout<<mystack->start->value<<" "<<mystack->start->next->value<<endl;
    push(3,0);
    cout<<mystack->start->value<<" "<<mystack->start->next->value<<" "<<mystack->start->next->next->value<<endl;
}
