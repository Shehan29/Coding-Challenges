#include<iostream>
#include<string>
#include<cassert>
using namespace std;

struct Qnode {
    string name;
    Qnode* next;
};
struct Queue {
    Qnode* first;
    Qnode* last;
    int size;
};
void initQ (Queue& q) {
    q.first = nullptr;
    q.last = nullptr;
    q.size = 0;
}
bool isEmptyQ (const Queue& q)
{
    return (nullptr == q.first);
}
int sizeQ (const Queue& q)
{
    return q.size;
}
void enterQ (Queue& q, string name) {
    Qnode* p = new Qnode;     //create new node for insertion
    p->name = name;
    p->next = nullptr;
    if (isEmptyQ(q))
    {
        q.first = p;
    }
    else
    {
        q.last->next = p;
    }
    q.last = p;
    q.size++;
}

string firstQ (const Queue& q) {
    if (isEmptyQ(q))
    {
        cerr << "Error, queue is empty." << endl;
        assert(false);
    }
    else
    {
        return q.first->name;
    }
}
void leaveQ (Queue& q)
{
    if (isEmptyQ (q))
    {
        cerr << "Error, queue is empty." << endl;
        assert(false);
    }
    else
    {
        Qnode *p = q.first;          //temp node to hold onto first element for deletion
        q.first = q.first->next;    //shift first element to second element
        if (nullptr == q.first)
        {
            q.last = nullptr;       //empty queue
        }
        delete p;                   //delete temp node
        q.size--;
    }
}
void printQ (const Queue& q) {
    Qnode *temp = q.first;
    while (temp != nullptr)
    {
        cout<<temp->name<<endl;
        temp = temp->next;
    }
}

struct PQnode {
    int priority;
    int size;
    Queue* q;
    PQnode* next;
};

// Free samples :-)
typedef PQnode* PQ;

void initPQ (PQ& pq)
{
    pq = nullptr;
}

bool isEmptyPQ (const PQ& pq)
{
    return (nullptr == pq);
}

void enterPQ (PQ& pq, string name, int priority)
{
    PQnode * temp = pq;
    while (temp != nullptr && temp->priority != priority)
    {
        temp = temp->next;
    }
    if (temp != nullptr)
    {
        enterQ(*temp->q, name);
        temp->size++;
    }
    else if (!isEmptyPQ(pq) && priority < pq->priority)
    {
        PQnode * newPQ = new PQnode;
        newPQ->priority = priority;
        Queue * q  = new Queue;
        initQ(*q);
        //cout<<"error"<<endl;
        enterQ(*q, name);
        newPQ->q = q;
        newPQ->size = 1;
        newPQ->next = pq;
        pq = newPQ;
        //cout<<pq->priority<<endl;
    }
    else
    {
        PQnode * newPQ = new PQnode;
        newPQ->priority = priority;
        Queue * q  = new Queue;
        initQ(*q);
        enterQ(*q, name);
        newPQ->q = q;
        newPQ->size = 1;
        if (isEmptyPQ(pq))
        {
            newPQ->next = nullptr;
            pq = newPQ;
        }
        else
        {
            PQnode * find = pq;
            while (find->next != nullptr && priority >= find->next->priority)
            {
                find = find->next;
            }
            newPQ->next = find->next;
            find->next = newPQ;
        }
    }
}

int firstPQ (const PQ& pq)
{
    if (isEmptyPQ(pq))
    {
        cerr << "Error, priority queue is empty." << endl;
        assert(false);
    }
    else
    {
        return abs(pq->priority);
    }
}

void leavePQ (PQ& pq)
{
    if (isEmptyPQ(pq))
    {
        cerr << "Error, priority queue is empty." << endl;
        assert(false);
    }
    else
    {
        if (sizeQ(*pq->q) == 1)
        {
            PQnode * temp = pq;
            pq = pq->next;
            delete temp->q;
            delete temp;
        }
        else
        {
            leaveQ(*pq->q);
            pq->size--;
        }
    }
}

int sizePQ (const PQ& pq)
{
    PQnode * temp = pq;
    int count = 0;
    while (temp != nullptr)
    {
        count += sizeQ(*temp->q);
        temp = temp->next;
    }
    return count;
}

int sizeByPriority (const PQ& pq, int priority)
{
    int size = 0;
    PQnode * temp = pq;
    while (temp != nullptr && temp->priority != priority)
    {
        temp = temp->next;
    }
    if (temp != nullptr)
        size = sizeQ(*temp->q);
    return size;
}

int numPriorities (const PQ& pq)
{
    PQnode * temp = pq;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


int main (int argc, char *argv[])
{
    int n;  //number of floors & number of people (1 person per floor)
    bool upward = true;
    int current = 1; //lobby
    
    //n=4;
    //int a[] = {4,3,2,1};   //floors to go to
    //string names[] = {"Shehan", "Aravind", "Armanit", "Yash"};
    
    n=7;
    int a[] = {7,1,5,3,4,6,2};   //floors to go to
    string names[] = {"Shehan", "Aravind", "Armanit", "Yash", "Wilson", "Lawrence", "Ethan"};
    int satisfied = 0;
    
    PQ up;
    initPQ(up);
    PQ down;
    initPQ(down);
    
    while (satisfied != n)
    {
        cout<<"We are at floor "<<current<<"! "<<endl;
        int goingTo = a[current-1];
        string name = names[current-1];

        if (upward)
        {
            if (!isEmptyPQ(up) && firstPQ(up)==current)
            {
                cout<<"Thanks for riding "<<up->q->first->name<<"!"<<endl;
                leavePQ(up);
                satisfied++;
            }
            if (goingTo>current)
            {
                enterPQ(up, name, goingTo);
                a[current-1] = 0;   //passenger is no longer waiting
                cout<<"Welcome aboard "<<name<<"."<<endl;
            }
            else if (goingTo == current)
            {
                cout<<name<<", you are already where you want to be!"<<endl;
                satisfied++;
            }
            if (current != n)
                current++;
            else
            {
                if (goingTo != current)
                {
                    enterPQ(down, name, -goingTo);
                    a[current-1] = 0;   //passenger is no longer waiting
                    cout<<"Welcome aboard "<<name<<"."<<endl;
                }
                current--;
                upward = false;
            }
        }
        else if (!upward)
        {
            if (!isEmptyPQ(down) && firstPQ(down)==current)
            {
                cout<<"Thanks for riding "<<down->q->first->name<<"!"<<endl;
                leavePQ(down);
                satisfied++;
            }
            if (goingTo != 0 && goingTo<current)
            {
                enterPQ(down, name, -goingTo);
                a[current-1] = 0;   //passenger is no longer waiting
                cout<<"Welcome aboard "<<name<<"."<<endl;
            }
            current--;
        }
        cout<<endl;
    }
}
