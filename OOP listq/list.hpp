#pragma once 
#ifndef  LIST_HPP
#define  LIST_HPP
#include <iostream>
#include <cstddef>

template <typename T>
struct Node {
    T data;
    Node* next = NULL;
};
template <typename T>
class List {
public:
    class Iterator
    {
    private:
        Node<T>* curr;
    
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(Node<T>* node) : curr(node) {}

        reference operator*() const { return curr->data; }
        pointer   operator->() { return &curr->data; }
        Iterator& operator++() { curr = curr->next; return *this; }
        Iterator  operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        bool operator>(const Iterator& iter) const {
            Iterator temp = *this;
            while (temp != iter) {
                ++temp;
                if (temp.curr == nullptr) return false;
            }
            return true;
        }
        bool operator == (const Iterator& iter) const { return curr == iter.curr; };
        bool operator != (const Iterator& iter) const { return curr != iter.curr; };
        bool operator<(const Iterator& iter) const { return !(*this >= iter); }
        bool operator<=(const Iterator& iter) const { return !(*this > iter); }
        bool operator>=(const Iterator& iter) const { return (*this == iter) || (*this > iter); }

    };

    class const_iterator {
    private:
        Node<T>* curr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = const T;
        using pointer = const T*;
        using reference = const T&;
        using const_reference = value_type&;

        const_iterator(Node<T>* node) : curr(node) {}
        const_iterator(const const_iterator& iter) : curr(iter.curr) {}

        const_reference operator*() const { return curr->data; }
        const_iterator& operator++() { curr = curr->next; return *this; }
        const T* operator->() const { return &curr->data; }
        bool operator==(const const_iterator& iter) const { return curr == iter.curr; }
        bool operator!=(const const_iterator& iter) const { return !(*this == iter); }
    };


    Node<T>* head;

    List() {
        head = NULL;
    };
    List(Node<T> a) {
        head = new Node<T>;
        *head = a;
        crutch++;
    };
    List(T a) {
        head = new Node<T>;
        head->data = a;
        crutch++;
    };
    List(List& copy) {
        Node<T>* current = copy.head;
        while (current) {
            PushBack(current->data);
            current = current->next;
        }
    };


    List(List&& list) : head(list.head), crutch(list.crutch) {
        list.head = NULL;
        list.crutch = 0;
    };

    ~List() {
        if (head != NULL && head->next != NULL) {
            Node<T>* current = this->head->next;
            while (current->next != NULL) {
                Node<T>* tmp = current;
                current = current->next;
                delete tmp;
            }
            delete this->head;
            this->head = NULL;
        }
        else if (head != NULL && head->next == NULL) {
            delete this->head;
            this->head = NULL;
        }
        else {

        }
        crutch = 0;
    };

    void PushBack(T data) {

        Node<T>* tmp = new Node<T>;
        tmp->data = data;

        if (head == NULL) {
            head = tmp;
            head->next = NULL;
        }

        else {
            Node<T>* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = tmp;
            tmp->next = NULL;
        }
        crutch++;
    };

    void popBack() {
        Node<T>* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    crutch++;
    }

    void print() {
        Node<T>* current = head;
        if (head == NULL) std::cout << "The list is empty";
        else {
            std::cout << head->ch << " ";
            while (current->next != NULL) {
                current = current->next;
                std::cout << current->ch << " ";
            }
            std::cout << std::endl;
        };
    }

    size_t size() { return crutch; };
    size_t maxSize() { return 204903409; };
    void swap(List* list2);


    List& operator=(const List& list) {
        if (this == &list) {
            return *this;
        }

        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        Node<T>* temp = list.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }

        return *this;
    }

    List& operator=(List&& list) {
        if (this != &list) {
            while (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }

            head = list.head;
            crutch = list.crutch;

            list.head = NULL;
            list.crutch = 0;


        }

        return *this;
    }
    bool operator ==  (const List& list) const {
        Node<T>* current = head;
        Node<T>* current2 = list.head;
        if (head == NULL && list.head == NULL) {
            return true;
        }
        else if (crutch == list.crutch)
        {
            while (current->next != NULL) {
                if (current->ch != current2->ch) {
                    return false;
                }
                current = current->next;
                current2 = current2->next;
            }
            return true;
        }
        else return false;
    };
    bool operator !=  (const List& list) const {
        Node<T>* current = head;
        Node<T>* current2 = list.head;
        if (head == NULL && list.head == NULL) {
            return false;
        }
        else if (crutch == list.crutch)
        {
            while (current->next != NULL) {
                if (current->ch != current2->ch) {
                    return true;
                }
                current = current->next;
                current2 = current2->next;
            }
            return false;
        }
        else return true;
    };



    List::Iterator begin() { return Iterator(head); };
    List::Iterator end() { return Iterator(NULL); };
    List::const_iterator cbegin() { return const_iterator(head); };
    List::const_iterator cend() { return const_iterator(NULL); };

    int crutch = 0;

};

template <typename T>
void swap(List<T>& list1, List<T>& list2) {
    List<T>& tmp = list2;
    list2 = list1;
    list2 = tmp;
};






#endif 