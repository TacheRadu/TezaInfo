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
    if(direction == 0){  //0 inseamna ca punem in stanga
            if(mystack->current == mystack->start){
                morty->next = mystack->start;
                morty->prev = NULL;
                mystack->start->prev = morty;
                mystack->start = morty;
                mystack->current = mystack->start;
                mystack->length++;
            }
            else{
                morty->next = mystack->current;
                morty->prev = mystack->current->prev;
                mystack->current->prev->next = morty;
                mystack->current->prev = morty;
                mystack->current = mystack->current->prev;
                mystack->length++;
            }
    }
    else if (direction == 1){  //1 inseamna ca punem in dreapta
        if(mystack->current == mystack->last){
            morty->next = NULL;
            morty->prev = mystack->current;
            mystack->current->next = morty;
            mystack->last = morty;
            mystack->current = mystack->last;
            mystack->length++;
        }
        else{
            morty->prev = mystack->current;
            morty->next = mystack->current->next;
            mystack->current->next->prev = morty;
            mystack->current->next = morty;
            mystack->current = mystack->current->next;
            mystack->length++;
        }
    }
}
int pop(int direction){

    if(mystack->length == 0){
        cout<<"stiva este goala.."<<endl;
        return 0;
    }
    int old;
    if(mystack->length == 1){
        old = mystack->current->value;
        delete mystack->current;
        mystack->length--;
        cout<<"am scos "<<old<<endl;
        return 0;
    }
    old = mystack->current->value;
    Duble *morty = new Duble;
    morty = mystack->current;
    if(direction == 0){  //0 inseamna ca mutam current-ul in stanga
        if(mystack->current == mystack->start){
            mystack->current->next->prev = NULL;
        }
        else if(mystack->current == mystack->last){
            mystack->current->prev->next = NULL;
        }
        else{
            mystack->current->prev->next = mystack->current->next;
            mystack->current->next->prev = mystack->current->prev;
        }
        if(mystack->current == mystack->start){
            mystack->current = mystack->current->next;
            mystack->start = mystack->current;
        }
        else{
            mystack->current = mystack->current->prev;
        }
        delete morty;
        mystack->length--;
        cout<<"am scos "<<old<<endl;
    }
    if(direction == 1){  //1 inseamna ca mutam current-ul in dreapta
        if(mystack->current == mystack->start){
            mystack->current->next->prev = NULL;
            mystack->current = mystack->current->next;
            mystack->start = mystack->current;
        }
        else if(mystack->current == mystack->last){
            mystack->current->prev->next = NULL;
            mystack->current = mystack->current->prev;
            mystack->last = mystack->current;
        }
        else{
            mystack->current->prev->next = mystack->current->next;
            mystack->current->next->prev = mystack->current->prev;
            mystack->current = mystack->current->next;
        }
        delete morty;
        mystack->length--;
        cout<<"am scos "<<old<<endl;
    }
}
int show(int direction){
    Duble *morty = new Duble;
    if(direction == 1)
    {
        morty = mystack->start;
        for(int i = 0; i < mystack->length; i++){
            cout<<morty->value<<" ";
            morty = morty->next;
        }
    }
    else if(direction == 0){
        morty = mystack->last;
        for(int i = 0; i < mystack->length; i++){
            cout<<morty->value<<" ";
            morty = morty->prev;
        }
    }
    cout<<endl;
    return 0;
}
int main()
{
    init();
    push(1,0);                     //aici nu prea are sens, nefiind nimic
    show(1);
    push(2,1);                     //punem 2 in dreapta lui 1
    show(1);
    push(3,0);                     //punem 3 in stanga lui 2
    show(1);
    push(4,1);                     //punem 4 in dreapta lui 3
    show(1);
    pop(0);                        //scoatem 4, care e current, si setam nou current vecinul din stanga
    show(1);
    pop(1);                        //scoatem 3, noul-setat current, si setam current-ul vecinul din dreapta
    show(1);
    cout<<mystack->current->value; //demonstram ca pop-ul a mutat corect noul current
}
