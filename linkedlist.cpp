#include <iostream>

template<typename T>
struct Node {
    T Data;
    Node<T>* Next;
};

template<typename T>
class LinkedList {
private:
    Node<T>* Head;
public:
    LinkedList () : Head(nullptr) {}

    size_t size() {
        Node<T>* temp = this->Head;

        if (temp == nullptr) {
            return 0;
        }

        size_t size = 1;
        while (temp->Next != nullptr) {
            temp = temp->Next;
            size++;
        }

        return size;
    }

    bool append(T new_data) {
        Node<T>* new_node = new Node<T>{new_data, nullptr};

        if (this->Head == nullptr) {
            this->Head = new_node;
            return true;
        }

        Node<T>* temp = this->Head;
        while (temp->Next != nullptr) {
            temp = temp->Next;
        }

        temp->Next = new_node;
    }

    bool insert(int index, T new_data) {
        Node<T>* new_node = new Node<T>{new_data, nullptr};

        if (index < 0) {
            throw std::out_of_range("Negative index not allowed!");
            delete new_node;
            return false;
        }

        if (index == 0) {
            new_node->Next = this->Head;
            this->Head = new_node;
            return true;
        }

        Node<T>* temp = this->Head;
        for(int i=0; temp != nullptr && i<index-1; i++) {
            temp = temp->Next;
        }


        if (temp == nullptr) {
            throw std::out_of_range("Index larger than list size is not allowed");
            delete new_node;
            return false;
        }

        new_node->Next = temp->Next;
        temp->Next = new_node;
        return true;
    }

    T& operator[](int index) {
        if (index < 0) {
            throw std::out_of_range("Negative index not allowed!");
        }

        Node<T>* temp = this->Head;
        int currentIndex = 0;

        while (temp != nullptr) {
            if (currentIndex == index) {
                return temp->Data;  // Veriyi referans olarak döndür
            }
            temp = temp->Next;
            currentIndex++;
        }

        throw std::out_of_range("Index out of bounds!");
    }


    void print() {
        std::cout << "[ ";
        Node<T>* temp = this->Head;
        while (temp != nullptr) {
            std::cout << temp->Data << " ";
            temp = temp->Next;
        }
        std::cout << "]";
    }
};

int main() {
    LinkedList<int> mylist;

    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.append(4);
    mylist.append(5);

    mylist.print();
}
