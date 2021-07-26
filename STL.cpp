#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    private:
        int iSize;
        struct node<T> *Head;
    
    public:
        SinglyLL();
        ~SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        // void InsertAtPos(T,int);
        // void DeleteFirst();
        // void DeleteLast();
        // void DeleteAtPos(int);
        int Count();
        void Display();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    iSize = 0;
    Head = NULL;
}

template<class T>
SinglyLL<T>::~SinglyLL()
{
    struct node<T> *temp = Head;
    while(Head != NULL)
    {
        Head = Head->next;
        delete temp;
        temp = Head; 
    }
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = new(struct node<T>);
    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    iSize++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = new(struct node<T>);
    newn->data = no;
    newn->next = NULL;

    if(iSize == 0)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int SinglyLL<T>::Count()
{
    return iSize;
}

int main()
{
    int iChoice = 1, iRet = 0, iValue = 0, iPos;
    SinglyLL<int> obj;

    while(iChoice != 0)
    {
        cout<<"Enter Your Choice :\n";
        cout<<"1. Insert Element At First position\n";
        cout<<"2. Insert Element At Last position\n";
        cout<<"3. Insert Element At Given position\n";
        cout<<"4. Delete First Element\n";
        cout<<"5. Delete Last Element\n";
        cout<<"6. Delete Element at given position\n";
        cout<<"7. Display All Elements\n";
        cout<<"0. Count Number of elements\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter :";
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter :";
                cin>>iValue;
                obj.InsertLast(iValue);
                break;
            
            case 3:
                cout<<"Enter :";
                cin>>iValue;
                cout<<"Enter the Position :";
                cin>>iPos;
                // obj.InsertAtPos(iValue,iPos);
                break;
            
            case 4:
                // obj.DeleteFirst();
                break;
            
            case 5:
                // obj.DeleteLast();
                break;
            
            case 6:
                cout<<"Enter the Position :";
                cin>>iPos;
                // obj.DeleteAtPos(iPos);
                break;
            
            case 7:
                cout<<"Elements are :\n";
                obj.Display();
                break;
            
            case 8:
                iRet = obj.Count();
                cout<<"Number of elements is : "<<iRet<<"\n";
                break;

            case 0:
                cout<<"Thank You for using application !\n";
                break;
            
            default:
                cout<<"Invalid Choice !!\n";
                break;
        }// End of Switch
    }// End of While
    return 0;
}// End of Main
