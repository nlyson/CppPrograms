/******************************************************************************

GetTheLoop.cpp
Nathan Lyson

You are given a node that is the beginning of a linked list. This list always contains a tail and a loop. 

Your objective is to determine the length of the loop.

For example in the following picture the tail's size is 3 and the loop size is 12:

A -> B -> C -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12
               ^                                                        |
               ----------------------------------------------------------         
               
Use the `getNext()` method to get the following node.
nodePtr->getNext()

*******************************************************************************/

#include <iostream>
#include <map>

using namespace std;

// Linked list created for testing purposes
template<class T>
class Node
{
    public:
        Node();
        Node(const T& item, Node<T>* ptrNext = NULL);
        T data;
        Node<T>* getNext();
        void insert(Node* p);
        void setNext(Node<T>* n);

        
    private:
        Node<T>* next;
};

template<class T>
Node<T>::Node()
{
    
}

template<class T>
Node<T>::Node(const T& item, Node<T>* ptrNext)
{
    this->data = item;
    this->next = ptrNext;
}

template<class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template<class T>
void Node<T>::insert(Node* p)
{
    p->next = this->next;
    
    this->next = p;
}

template<class T>
void Node<T>::setNext(Node* n)
{
    this->next = n;
}

template<class T>
int getLoopSize(Node<T>* startNode)
{
    
    // Here's the plan:
    // 1) Traverse the list and add each node to a map with a unique number.  (Starting at 0)
    // 2) Stop when I get to a) Null (There was no loop in this case)
    //                       b) The next node is already in our map - we've seen him before
    // 3) The length of our "loop" is the difference between the mappings of current and current->next
    int count = 0;
    
    Node<T>* current = startNode;
    Node<T>* current2 = current;
    map<Node<T>*, int> m;
    
    m[current] = count;
    count++;
    
   
    while(current->getNext() != NULL && m[current->getNext()] == 0)
    {
        current = current->getNext();
        m[current] = count;
        count++;
    }
    
 
    return m[current] - m[current->getNext()] + 1;
}

template<class T>
Node<T>* createTestCase()
{
    int size = 15;
    Node<T>* start = new Node<T>(0);
    Node<T>* current = start;
    
    Node<T>* loopBack;
    
    for(int i=1; i<size; i++)
    {
        
        
        Node<T>* n = new Node<T>(i);
        
        current->insert(n);
        current = current->getNext();
        
        if(i == 3)
            loopBack = current;
    }
    
    current->setNext(loopBack);
    
    return start;
}

template<class T>
void printList(Node<T>* startNode)
{
    int count = 0;
    while(startNode != NULL)
    {
        cout << startNode->data << " ";
        startNode = startNode->getNext();
        
        count++;
        if(count > 100)
            break;
    }
    cout << endl;
}


int main()
{
    // Test cases
    Node<int>* test = createTestCase<int>();
    
    cout << getLoopSize(test) << endl;

    return 0;
}
