#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

// void exit(
//     int const status
// );

void error() {
    cout << "YOU HAVE BROKEN THE PROGRAM";
    exit(0);
}

template<typename T>
struct Node {
    T data;
    struct Node* next;

    friend ostream& operator<<(ostream& os, const Node<T>& obj) {
        os << obj.data;
        return os;
    }
    const Node<T> operator=(const Node<T> new_value) {
        this->data = new_value.data;
        cout << *this;
        return *this;
    }
    const Node<T> operator=(T value) {
        this->data = value;
        return *this;
    }

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

        if (head == NULL)
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
    void append(T arr[]) {
        for (int i = 0; i < sizeof(*arr) - 1; i++) {
            this->append(arr[i]);
        }
    }
    void insert(T n, int ind) {
        if (ind > this->len()) {
            cout << "ERROR" << endl;
        }

        else if (ind == 0) {
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
            for (int i = 1; i < ind; i++) {
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
        if (head != NULL) {
            while (tmp != tail->next) {
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            cout << endl;
        }
        else {
            cout << "EMPTY" << endl;
        }
        tmp = NULL;
        delete tmp;
    }
    int len() {
        int k = 1;
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if (tmp != NULL) {
            while (tmp != tail) {
                tmp = tmp->next;
                k++;
            }
            return (k);
        }
        else {
            return 0;
        }
        tmp = NULL;
        delete tmp;
    }
    void pop()
    {
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if (head != NULL) {
            if (head->next == NULL) {
                head = NULL;
            }
            else {
                while ((tmp->next != tail) && (tmp != tail)) {
                    tmp = tmp->next;
                }
                tmp->next = NULL;
                tail = tmp;
            }
        }
        tmp = NULL;
        delete tmp;
    }

    void erase(int ind) {
        if (ind > this->len()) {
            cout << "ERROR" << endl;
        }
        else if (ind == 0) {
            head = head->next;
        }
        else {
            Node<T>* tmp = head;
            for (int i = 0; i < ind - 1; i++) {
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
        }
    }

    void change_elem(T new_value, int ind) {
        if (ind > this->len()) {
            cout << "ERROR" << endl;
        }
        else {
            this->erase(ind);
            this->insert(new_value, ind);
        }
    }

    void change_elem_by_fedor(T new_value, int ind) {
        Node<T>* tmp = new Node<T>;
    }

    void bubble_sort() {
        if (head != NULL) {
            if (head->next != NULL) {
                Node<T>* tmp = new Node<T>;
                Node<T>* next_node = new Node<T>;
                tmp = head;
                next_node = tmp->next;
                bool flag = false;
                while (!flag) {
                    flag = true;
                    while (tmp != tail) {
                        if (tmp->data > tmp->next->data) {
                            T n = tmp->data;
                            tmp->data = tmp->next->data;
                            tmp->next->data = n;
                            flag = false;
                        }
                        tmp = tmp->next;
                    }
                    tmp = head;
                }
            }
        }
        else {
            cout << "WHY ARE YOU DOING THIS?" << endl;
        }
    }

    T operator[](int ind) {
        if (head == NULL || ind < 0) {
            error();
        }
        else if (ind < this->len()) {
            int k = 0;
            Node<T>* tmp = head;
            while (k != ind) {
                tmp = tmp->next;
                k++;
            }
            return tmp->data;
        }
        else {
            error();
        }
        return 0;
    }

};

int main() {
    list<int> a;
    a.append(6);
    a.append(7);
    a.append(8);
    int arr[3] = { 1, 2, 3 };
    a.append(arr);
    a.bubble_sort();

    a.print();
    cout << a[3] << endl;
    a.print();
    return 0;
}
