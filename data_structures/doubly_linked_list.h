#ifndef STRUCTURES_DOUBLY_LIST_H
#define STRUCTURES_DOUBLY_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

template<typename T>
class DoublyLinkedList {
 public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void clear();

    void push_back(const T& data);
 
    void push_front(const T& data);
 
    void insert(const T& data, std::size_t index);
 
    void insert_sorted(const T& data);

    T pop(std::size_t index);
 
    T pop_back();

    T pop_front();
 
    void remove(const T& data);
 
    bool empty() const;
 
    bool contains(const T& data) const;
 
    std::size_t find(const T& data) const;
 
    std::size_t size() const;
 
    T& at(std::size_t index);

    T& at(std::size_t index) const;

    void printAll();

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data},
            prev_{nullptr},
            next_{nullptr}
        {}

        Node(const T& data, Node* next):
            data_{data},
            prev_{nullptr},
            next_{next}
        {}

        Node(const T& data, Node* prev, Node* next):
            data_{data},
            prev_{prev},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* prev() {  // getter: anterior
        	return prev_;
        }

        const Node* prev() const {  // getter const: anterior
        	return prev_;
        }

        void prev(Node* node) {  // setter: anterior
        	prev_ = node;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* prev_{nullptr};
        Node* next_{nullptr};
    };

    Node* head{nullptr};
    Node* tail{nullptr};
    std::size_t size_{0u};
};

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList():
        head{nullptr},
        tail{nullptr},
        size_{0u}
    {}

    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() {
        clear();
    }

    template<typename T>
    void DoublyLinkedList<T>::push_back(const T& data) {
        Node* newNode{new Node(data)};
        if (empty()) {
    		    head =  newNode;
        } else {
            tail->next( newNode);
            newNode->prev(tail);
        }
        tail =  newNode;
        size_++;
    }

    template<typename T>
    void DoublyLinkedList<T>::push_front(const T& data) {
        Node* newNode{new Node(data, nullptr, head)};
        if (empty()) {
        	tail =  newNode;
        } else {
        	head->prev(newNode);
        }
        head =  newNode;
        size_++;
    }

    template<typename T>
    void DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
        if (index > size()) {
            throw std::out_of_range("Wrong position");
        }
        
        if (empty() || index == 0) {
            push_front(data);
            return;
        } 
        
        if (index == size()) {
        	push_back(data);
            return;
        }
    
        Node* newNode{new Node(data)};
        Node* helper = head;
        for (auto i = 0u; i < index; ++i) {
            helper = helper->next();
        }

        newNode->next(helper);
        newNode->prev(helper->prev());
        newNode->prev()->next(newNode);
        helper->prev(newNode);
        size_++;
    }

    template<typename T>
    void DoublyLinkedList<T>::insert_sorted(const T& data) {
        if (empty()) {
            push_front(data);
            return;
        }

        Node* helper = head;
        auto index = 0u;
        while (index < size_ && *data > *helper->data()) {
            index++;
            helper = helper->next();
        }
        
        insert(data, index);
    }

    template<typename T>
    T DoublyLinkedList<T>::pop(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }

        if (index >= size_) {
            throw std::out_of_range("Posição inválida");
        }
        
        if (index == 0) {
            return pop_front();
        } 
        
        if (index == size()-1) {
        	return pop_back();
        }

        Node* helper = head;
        for (auto i = 0u; i < index; ++i) {
            helper = helper->next();
        }
        
        T requested = helper->data();
        helper->prev()->next(helper->next());
        helper->next()->prev(helper->prev());
        
        delete helper;
        size_--;

        return requested;
    }

    template<typename T>
    T DoublyLinkedList<T>::pop_back() {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }

        Node* helper = tail;
        if (size() == 1) {
        	tail = nullptr;
        	head = nullptr;
        } else {
        	tail = tail->prev();
        	tail->next(nullptr);
        }

        T requested = helper->data();
        delete helper;
        size_--;
        return requested;
    }

    template<typename T>
    T DoublyLinkedList<T>::pop_front() {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }

        Node* helper = head;
        if (size() == 1) {
        	head = nullptr;
        	tail = nullptr;
        } else {
        	head = head->next();
        	head->prev(nullptr);
        }
        
        T requested = helper->data();
        delete helper;
        size_--;
        return requested;
    }

    template<typename T>
    void DoublyLinkedList<T>::remove(const T& data) {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }

        if (contains(data))
        	pop(find(data));
    }

    template<typename T>
    std::size_t DoublyLinkedList<T>::find(const T& data) const {
        Node* helper = head;
        auto index = 0u;
        
        while ( (index < size_) && (data != helper->data()) ) {
            index++;
            helper = helper->next();
        }

        return index;
    }

    template<typename T>
    void DoublyLinkedList<T>::clear() {
        Node* helper = head;
        
        while (helper != nullptr && helper->next() != nullptr) {
            helper = helper->next();
            delete helper->prev();
        }
        
        if (helper != nullptr) {
        	delete helper;
        }

        head = nullptr;
        tail = nullptr;
        size_ = 0u;
    }

    template<typename T>
    std::size_t DoublyLinkedList<T>::size() const {
        return size_;
    }

    template<typename T>
    bool DoublyLinkedList<T>::empty() const {
        return (size_ == 0);
    }

    template<typename T>
    bool DoublyLinkedList<T>::contains(const T& data) const {
        return (find(data) >= 0 && find(data) < size_);
    }

    template<typename T>
    T& DoublyLinkedList<T>::at(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }

        if (index >= size_) {
            throw std::out_of_range("Wrong position");
        }
        
        if (index == 0) {
            return head->data();
        } 
        
        if (index == size()-1) {
        	return tail->data();
        }
        
        Node* helper = head;
        for (auto i = 0u; i < index; ++i) {
            helper = helper->next();
        }

        return helper->data();
    }

    template<typename T>
    T& DoublyLinkedList<T>::at(std::size_t index) const {
        if (empty()) {
            throw std::out_of_range("Empty");
        }

        if (index >= size_) {
            throw std::out_of_range("Wrong position");
        }
        
        if (index == 0) {
            return head->data();
        }
        
        if (index == size()-1) {
        	return tail->data();
        }
        
        Node* helper = head;
        for (auto i = 0u; i < index; ++i) {
            helper = helper->next();
        }

        return helper->data();
    }

    template<typename T>
    void DoublyLinkedList<T>::printAll() {
        Node* helper = head;
        auto index = 0u;
        
        while (helper != nullptr) {
            printf("i: %d - data: ", index);
            helper->data()->print();
            index++;
            helper = helper->next();
        }
    }

#endif