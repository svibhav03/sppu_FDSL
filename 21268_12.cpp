#include <iostream>
using namespace std;

template<class T>
class Node {
    public:
    T data;
    int priority;
    Node *next;

    Node(T data, int priority) {
        this->data = data;
        this->priority = priority;
        next = NULL;
    }
};

template <class T>
static bool operator <= (const Node<T> &n1, const Node<T> &n2) {
    return n1.priority <= n2.priority;
}

template<class T>
class PriorityQueue {
      Node<T> *head;

      public:
      PriorityQueue() {
        head = NULL;
      }

      void insert(T data, int priority) {
        Node<T> *newNode = new Node<T>(data, priority);
        if (head) {
            if (head->priority <= priority) {
                newNode->next = head;
                head = newNode;
            } else {
                Node<T> *itr = head;
                while (itr->next && !(itr->next->priority <= priority)) {
                    itr = itr->next;
                }
                newNode->next = itr->next;
                itr->next = newNode;
            }
        } else {
            head = newNode;
        }
      }

      void remove() {
        if (head) {
            Node<T> *temp = head;
            head = head->next;
            cout<<"Removed "<<temp->data<<". Priority: "<<temp->priority<<endl;
            delete temp;
        } else {
            cout<<"Priority queue is empty"<<endl;
        }
      }

      void print() {
        Node<T> *itr = head;
        while(itr) {
            cout<<"Task "<<itr->data<<". Priority: "<<itr->priority<<endl;
            itr = itr->next;
        }
        cout<<endl;
      }
};

int main() {
    PriorityQueue<string> pq;
    int choice;
    while (true) {
        cout<<"MENU"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Remove"<<endl;
        cout<<"3.Print"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;
        switch(choice) {
            case 1: {
                int priority;
                string data;
                cout<<"Enter task: ";
                cin>>data;
                cout<<"Enter priority: ";
                cin>>priority;
                pq.insert(data, priority);
                break;
            }
            case 2: {
                pq.remove();
                break;
            }
            case 3: {
                pq.print();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                cout<<"Invalid choice"<<endl;
                break;
            }
        }
    }
}