struct Node
{
    int data;
    Node *PreviousNode;
};

class LinkedList {
    Node *head;
    Node *tail;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;

        void push(int data)
        {
            Node *newNode = new Node;
            newNode-> data = data;
            newNode->PreviousNode = nullptr;
            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else 
            {
                newNode-> PreviousNode = head;
                head = newNode;
            }
        }
 
        int size() const
        {
            int counter = 0;
            Node *tmp = head;
            while (tmp)
            {
                counter++;
                tmp = tmp-> PreviousNode;
            }
            return counter;
        }

        Node* fNode() const
        {
            return head;
        }

        Node* lNode() const
        {
            return tail;
        }

        void swapData(Node *one, Node *two)
        {
            if (!one || !two) return;

            int tmp = one-> data;
            one-> data = two-> data;
            two-> data = tmp;
        }

        ~LinkedList() {
            while (head) {
                Node* tmp = head;
                head = head-> PreviousNode;
                delete tmp;
            }
            tail = nullptr;
        }
};