#include <stdlib.h>

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void error() {
    cout << "YOU HAVE BROKEN THE PROGRAM";
    exit(0);
}

template <typename T>
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

template <typename T>
class LinkedList {
    class ListIterator {
        LinkedList<T>& ls;
        size_t ind;

       public:
        ListIterator(LinkedList& ls, size_t ind) : ls(ls), ind(ind) {}
        T& operator*() { return ls[ind]; }

        ListIterator& operator++() {
            ind++;
            return *this;
        }

        bool operator==(const ListIterator& other) const {
            return ind == other.ind && ls == other.ls;
        }
        bool operator!=(const ListIterator& other) const {
            return !(*this == other);
        }
    };

   private:
    Node<T>*head, *tail;

   public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    bool operator==(const LinkedList& other) {
        if (len() != other.len()) return false;
        for (size_t i = 0; i < len(); i++) {
            if (this->operator[](i) != other[i]) return false;
        }
        return true;
    }

    bool operator!=(const LinkedList& other) { return !(*this == other); }

    void append(T n) {
        Node<T>* tmp = new Node<T>;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
        tmp = NULL;
        delete tmp;
    }
    void append(T arr[], int size) {
        for (int i = 0; i < size; i++) {
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
            tmp = NULL;
            new_elem = NULL;
            delete tmp;
            delete new_elem;
        }
    }

    friend ostream& operator<<(ostream& os, const LinkedList<T>& obj) {
        Node<T>* tmp = new Node<T>;
        tmp = obj.head;
        if (obj.head != NULL) {
            while (tmp != obj.tail->next) {
                os << tmp->data << ' ';
                tmp = tmp->next;
            }
            os << endl;
        } else {
            os << "EMPTY" << endl;
        }
        tmp = NULL;
        delete tmp;
        return os;
    }

    void print() {
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if (head != NULL) {
            while (tmp != tail->next) {
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            cout << endl;
        } else {
            cout << "EMPTY" << endl;
        }
        tmp = NULL;
        delete tmp;
    }

    size_t len() const {
        size_t k = 1;
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if (tmp != NULL) {
            while (tmp != tail) {
                tmp = tmp->next;
                k++;
            }
            return (k);
        } else {
            return 0;
        }
        tmp = NULL;
        delete tmp;
    }

    void pop() {
        Node<T>* tmp = new Node<T>;
        tmp = head;
        if (head != NULL) {
            if (head->next == NULL) {
                head = NULL;
            } else {
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
        } else if (ind == 0) {
            head = head->next;
        } else {
            Node<T>* tmp = head;
            for (int i = 0; i < ind - 1; i++) {
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
        }
    }

    void pop_front() { erase(0); }

    template <typename predicate>
    void erase_by_lambda(predicate lambda) {
        for (int i = 0; i < this->len(); i++) {
            auto value = this->operator[](i);
            if (lambda(value)) {
                erase(i);
                i--;
            }
        }
    }

    void change_elem(T new_value, int ind) {
        if (ind > this->len()) {
            cout << "ERROR" << endl;
        } else {
            this->erase(ind);
            this->insert(new_value, ind);
        }
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
        } else {
            cout << "WHY ARE YOU DOING THIS?" << endl;
        }
    }

    void reverse() {
        Node<T>* tmp_begin = head;
        T temp_data = head->data;
        head->data = tail->data;
        tail->data = temp_data;
        for (int i = 1; i < this->len() / 2; i++) {
            tmp_begin = tmp_begin->next;
            Node<T>* tmp_end = tmp_begin;
            for (int j = 0; j < this->len() - i - (i + 1); j++) {
                tmp_end = tmp_end->next;
            }
            temp_data = tmp_begin->data;
            tmp_begin->data = tmp_end->data;
            tmp_end->data = temp_data;
            // cout << *tmp_begin << ' ' << *tmp_end << ' ' << endl;
        }
    }

    T& operator[](size_t ind) {
        if (head == NULL || ind < 0) {
            error();
        }
        if (ind > this->len()) error();
        int k = 0;
        Node<T>* tmp = head;
        while (k != ind) {
            tmp = tmp->next;
            k++;
        }
        return tmp->data;
    }

    T operator[](size_t ind) const {
        if (head == NULL || ind < 0) {
            error();
        } else if (ind < this->len()) {
            int k = 0;
            Node<T>* tmp = head;
            while (k != ind) {
                tmp = tmp->next;
                k++;
            }
            return tmp->data;
        } else {
            error();
        }
        return 0;
    }

    bool present(T a) {
        Node<T>* tmp = head;
        for (int i = 0; i < this->len(); i++) {
            if (tmp->data == a) {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    T find(T a) {
        Node<T>* tmp = head;
        for (int i = 0; i < this->len(); i++) {
            if (tmp->data == a) {
                return i;
            }
            tmp = tmp->next;
        }
        return this->len();
    }

    using iterator = ListIterator;

    iterator begin() { return iterator(*this, 0); }
    iterator end() { return iterator(*this, len()); }
};

int main() {
    LinkedList<int> a;
    a.append(6);
    a.append(7);
    a.append(8);
    int arr[4] = {1, 2, 10, 5};
    a.append(arr, 4);
    cout << a << endl;
    a.bubble_sort();
    a.reverse();
    // cout << 1;
    a.erase_by_lambda([](int& i) { return i % 2 == 0; });
    for (auto it : a) cout << it << endl;

    // cout << a.present(7) << endl;
    // cout << a.present(10) << endl;
    // cout << a.find(6) << endl;
    return 0;
}
