#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
}*start,*loc,*np;

void push(int val)
{
    np = new node ;
    np -> data = val;
    np -> next = NULL;

    if(start==NULL)
    {
        start = np;
    }
    else
    {
        loc=start;

        while(loc!=NULL)
        {
            if((loc -> next)== NULL)
            {
                loc -> next = np ;
                break ;
            }
            loc = loc -> next;
        }
    }
}

void pop()
{
    if(start == NULL)
    {
        cout<<"Empty List!!";
    }
    else if(start -> next == NULL)
    {
        cout<<"Value popped :"<<start -> data ;
        start = NULL ;
    }
    else
    {
        loc = start;

        while(loc!= NULL)
        {
            if((loc -> next -> next)==NULL)
            {
                cout<<"Value popped :"<<loc -> next -> data ;
                loc -> next = NULL ;
                break;
            }
            loc =loc -> next;
        }
    }
}

void display()
{
    loc=start;

    cout<<"\nStack From bottom to top :\n";

    while(loc!=NULL)
    {
        cout<<loc -> data<<" ";
        loc = loc -> next;
    }
}


int main()
{
    int value,opt;

    do
    {
        cout<<"\nEnter\n1.To push\n2.To pop\n3.To display\n4.To exit\n";
        cin>>opt;

        switch(opt)
        {
            case 1:cout<<"Enter value to push :";
                   cin>>value;
                   push(value);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                    break;
            default:cout<<"Wrong option";
                    break;
        }

    }while(opt!=4);

    return 0;
}
