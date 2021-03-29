#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

template<typename T>
struct Node {
    T data;
    struct Node* next;
};

template<typename T>
class list {
private:
    Node<T>* head, * tail; *current;
public:
    list() {
        head = NULL;
        tail = NULL;
    }
    void append(T n)
    {
        Node<T>* tmp = new Node<T>;
        tmp->data = n;
        tmp->next = NULL;

        if ( head == NULL )
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void print()
    {
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if ( head != NULL ) {
            while ( tmp != tail->next ) {
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
        }
        else {
            cout << "EMPTY";
        }
    }
    int len() {
        int k = 1;
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if ( tmp != NULL ) {
            while ( tmp != tail ) {
                tmp = tmp->next;
                k++;
            }
            return ( k );
        }
        else {
            return 0;
        }
    }
};

int main() {
    list<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    cout << a.len();
    return 0;
}
