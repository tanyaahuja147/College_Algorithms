#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
}*start,*rear,*np,*loc;

void insertion(int dat)
{
    np = new node ;
    np -> data = dat ;
    np -> next = NULL ;

    if(start == NULL)
    {
        start = np;
        start -> next = np;
        rear = start;
    }
    else
    {
        rear -> next = np ;
        rear = np;
        np -> next = start;
    }

}

void deletion()
{
    if(start == NULL)
    {
        cout<<"\nEmpty List!!\n";
    }
    else if(start -> next == start)
    {
        cout<<"Value deleted : " << start -> data<<"\n";
        start = NULL ;
    }
    else
    {
        cout<<"Value deleted : " << start -> data<<"\n";
        rear -> next = start -> next ;
        start = start -> next ;
    }
}

void display()
{
    loc = start;

    if(start == NULL)
    {
        cout<<"\nEmpty List!!\n";
    }
    else
    {
        do
        {
            cout<< loc -> data<<" " ;
            loc = loc -> next ;
        }while(loc != start);
        cout<<"\n";
    }
}

void search(int value)
{
    loc = start ;

    int locval = 0 ;

    if(start == NULL)
    {
        cout<<"\nEmpty List!!\n";
    }
    else
    {
        do
        {
            locval++;

            if(loc -> data == value)
            {
                cout<<"\nPosition : "<< locval <<"\n";
            }
            loc = loc -> next ;
        }while(loc != start);
    }
}

int main()
{
    int opt,val;

    cout<<"Enter\n1.For Insertion\n2.For Deletion\n3.For Display\n4.For Searching\n5.For Exit \n";

    do
    {
        cout<<"\nEnter menu option : ";
        cin>>opt;

        switch(opt)
        {
            case 1 : cout<<"Enter value for insertion :";
                    cin>>val;
                    insertion(val);
                    break;

            case 2 : deletion();
                    break;

            case 3 : display();
                    break;

            case 4 : cout<<"Enter value for searching : ";
                    cin>>val;
                    search(val);
                    break;

            case 5:exit(1);

            default : cout<<"\nWrong Option!!";
        }
    }while(opt!=5);

    return 0;
}
