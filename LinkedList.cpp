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
    Node<T>* head, * tail;
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
        tmp = NULL;
        delete tmp;
    }
    insert(T n, int ind) {
        ind--;
        if ( ind > this->len() ) {
            cout << "ERROR" << endl;
        }

        else if ( ind == 0 ) {
            Node<T>* new_elem = new Node<T>;
            new_elem->data = n;
            new_elem->next = head;
            head = new_elem;
            new_elem = NULL;
            delete new_elem;
        }

        else {
            Node<T>* tmp = new Node<T>;
            tmp = head;
            for ( int i = 1; i < ind; i++ ) {
                tmp = tmp->next;
            }
            Node<T>* new_elem = new Node<T>;
            new_elem->data = n;
            new_elem->next = tmp->next;
            tmp->next = new_elem;
            tmp = NULL; new_elem = NULL;
            delete tmp; delete new_elem;
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
        tmp = NULL;
        delete tmp;
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
        tmp = NULL;
        delete tmp;
    }
    void pop()
    {
        Node<T>* tmp = new Node;
        tmp = head;
        if ( head != NULL ) {
            if ( head->next == NULL ) {
                head = NULL;
            }
            else {
                while ( ( tmp->next != tail ) && ( tmp != tail ) ) {
                    tmp = tmp->next;
                }
                tmp->next = NULL;
                tail = tmp;
            }
        }
        tmp = NULL;
        delete tmp;
    }
};

int main() {
    list<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.insert(5, 1);
    a.print();
    return 0;
}
