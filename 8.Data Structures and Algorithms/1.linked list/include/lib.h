#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

// LinkedList Node
struct Node {
    int data;
    Node *NextNode;
    Node *PreviousNode;
};

// LinkedList Class
class LinkedList {

    int count;
    Node *head;
    Node *tail;

    // search helper function
    Node* search(int data) 
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if(temp-> data == data)
            {
                return temp;
            }            
            temp = temp-> NextNode;
        }
        return NULL;
    }

    public:
    // constractor
    LinkedList()
    {
        cout << "Creating List." << endl;
        count = 0;
        head = NULL;
        tail = NULL;
    }   

    int getDataByIndex(int index)
    {
        int track = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            if(track == index)
            {
                cout << "Found: ";
                return temp-> data;
            }            
            track++;
            temp = temp-> NextNode;
        }
        cout << "Not Found." << endl;
        return 0;
    }

    void appendHeadData(int data)
    {
        Node *newData = new Node;
        newData-> data = data;

        // first node 
        if (head == NULL)
        {
            head = newData; tail = newData; 
            newData-> NextNode = NULL; newData-> PreviousNode = NULL;
            cout << "First Node Added." << endl;
        }

        // if node exist 
        else 
        {
            newData-> NextNode = head;
            head-> PreviousNode = newData;
            head = newData;
            cout << "Appended Node." << endl;
        }
        count++;
    }

    void insertAfter(int data, int afterData)
    {
        Node *dataPosition = search(data);
        if (dataPosition != NULL)
        {
            Node *newData = new Node;
            newData-> data = afterData;
            newData-> PreviousNode = dataPosition;
            count++;

            if (dataPosition-> NextNode != NULL)
            {
                // adjust new node
                newData-> NextNode = dataPosition-> NextNode;

                // adjust old nodes
                dataPosition-> NextNode -> PreviousNode = newData;
                dataPosition-> NextNode= newData;
                cout << "Added Node Between Two Nodes." << endl;
            }
            else 
            {
                // adjust new node
                newData-> NextNode = NULL;

                // adjust old nodes
                dataPosition-> NextNode= newData;
                tail = newData;
                cout << "Added Node After One Node." << endl;
            }
            newData = nullptr;  
        } 
    }

    void insertBefore(int data, int beforeData)
    {
        Node *dataPosition = search(data);
        if (dataPosition != NULL)
        {
            Node *newData = new Node;
            newData-> data = beforeData;
            newData-> NextNode = dataPosition;
            count++;

            if (dataPosition-> PreviousNode != NULL)
            {
                // adjust new node
                newData-> PreviousNode = dataPosition-> PreviousNode;

                // adjust old nodes
                dataPosition-> PreviousNode -> NextNode = newData;
                dataPosition-> PreviousNode = newData;
                cout << "Added Node Between Two Nodes." << endl;
            }
            else 
            {
                // adjust new node
                newData-> PreviousNode = NULL;

                // adjust old nodes
                dataPosition-> PreviousNode = newData;
                head = newData;
                cout << "Added Node Before One Node." << endl;
            }
            newData = nullptr;  
        } 
    }

    int GetCount()
    {
        cout << "Count: ";
        return count;
    }

    ~LinkedList()
    {
        while(head != NULL)
        {
            Node *temp = head; 
            head = head-> NextNode;
            delete temp;
        }
        cout << "Deleted List." << endl;
    }
};

#endif
