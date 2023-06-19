
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;


#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H
template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& d, Node* n) : data(d), next(n) {}
        Node(const T& d) : data(d), next(NULL) {}
        ~Node() = default;
    };
    Node* head;
    Node* tail;
public:
    LinkedList() : head(NULL), tail(NULL) {}
    ~LinkedList() { clear(); }

    void clear()
    {
        Node* nptr = head;
        while (nptr != NULL)
        {
            Node* dptr = nptr;
            nptr = nptr->next;
            delete dptr;

        }
        head = NULL;
    }

    void push_front(const T& item)
    {
        if (head == NULL)
        {
            head = new Node(item, head);
            tail = head;
        }
        else {
            head = new Node(item, head);
        }
    }


    friend ostream& operator<<(ostream& os, LinkedList& ll)
    {
        Node* node_ptr = ll.head;
        while (node_ptr != NULL)
        {
            os << node_ptr->data << (node_ptr->next != NULL ? " " : "");
            node_ptr = node_ptr->next;
        }
        return os;
    }

    int size()
    {
        int count = 0;
        Node* current = head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }


    class Iterator
    {
    private:

        Node* iNode;
    public:
        Iterator(Node* head) : iNode(head){ }
        ~Iterator() {}

        bool operator!=(const LinkedList<T>::Iterator& rhs) const
        {
            bool temp;

            if( this->iNode != NULL && this->iNode != rhs.iNode)
            {
                temp = true;
            }
            else{
                temp = false;
            }

            return temp;
        }

        Iterator operator++()
        {
            return this->iNode->next;
        }

        T operator*() const
        {
            T temp = this->iNode->data;
            return this->iNode->data;
        }

    };
    Iterator find(Iterator begin, Iterator end, const T& item)
    {
        Node* current = head;
        while (begin != end)
        {
            if (item == current->data)
            {
                return current;
            }
            current = current->next;
        }

    }
    LinkedList<T>::Iterator begin()
    {
        return LinkedList<T>::Iterator(head);
    }

    LinkedList<T>::Iterator end()
    {
        return LinkedList<T>::Iterator(NULL);
    }
    /*Iterator insert_after(Iterator value, const T& item)
    {
        Node* tmp = NULL;
        Node* temp = head;
        //Node* why = value;
        while (temp != NULL)
        {
            if(value == this) {
                tmp = new Node(item, this->next);
                this->Next = tmp;
            }
            else {
                this = this->next;
            }

        }




    }*/


};

#endif //ITERATOR_ITERATOR_H
