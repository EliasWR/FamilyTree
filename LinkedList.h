#ifndef FAMILYTREE_LINKEDLIST_H
#define FAMILYTREE_LINKEDLIST_H
#include <exception>
#include <ostream>
#include <utility>

namespace FamilyTree {
    template<typename T>        // Template to work with generic node
    class ListNode {

    public:
        explicit ListNode(const T &data) : data_(std::move(data)) {}

        T data_;
        ListNode *next_ = nullptr;
    };

    template<typename T>
    class singly_linked_list {
    private:
        ListNode<T> *head_ = nullptr;
        size_t size_ = 0;
    public:
        singly_linked_list() : size_(0) {}

        [[nodiscard]] bool empty() const { return size_ == 0; }

        T &operator[](size_t index) {
            if (index > size_) {
                throw std::runtime_error("Index out of bounds");
            }

            ListNode<T> *current = head_;
            for (int i = 0; i < index; i++) {
                current = current->next_;
            }
            return current->data_;
        }

        const T &operator[](size_t index) const {
            return operator[](index);
        }

        void addFirst(const T &data) { insert(0, data); }

        void addLast(const T &data) { insert(size_, data); }

        void insert(size_t index, T data) {
            if (index > size_) {
                throw std::runtime_error("Index out of bounds");
            }

            ListNode<T> *current = head_;
            ListNode<T> *prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = current;             // Saves last node
                current = current->next_;   // Goes to next node in linked list
            }

            ListNode<T> *insert = new ListNode(data);
            insert->next_ = current;
            if (!prev) {
                head_ = insert;
            } else {
                prev->next_ = insert;
            }

            size_++;
        }

        T remove(size_t index) {
            if (index >= size_) {
                throw std::runtime_error("Index out of bounds");
            }

            ListNode<T> *current = head_;
            ListNode<T> *prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next_;
            }

            T data = current->data_;
            if (!prev) {
                head_ = current->next_;
            } else {
                prev->next_ = current->next_;
            }

            delete current;

            size_--;

            return std::move(data);
        }

        [[nodiscard]] size_t size() const { return size_; }

        T removeFirst() {
            if (empty()) {
                throw std::runtime_error("List is empty..");
            }

            return remove(0);
        }

        T removeLast() {
            if (empty()) {
                throw std::runtime_error("List is empty..");
            }

            return remove(size_ - 1);
        }

        template<class E>
        friend std::ostream &operator<<(std::ostream &, const singly_linked_list<E> &);
    };

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const singly_linked_list<T> &l) {
        if (l.empty()) {
            os << "[]"
               << "\n";
        }

        os << "[";

        ListNode<T> *head = l.head_;
        while (true) {
            os << head->data_;
            ListNode<T> *next = head->next_;
            if (!next) {
                os << "]";
                break;
            } else {
                os << ", ";
                head = next;
            }
        }
        return os;
    }
}
#endif //FAMILYTREE_LINKEDLIST_H
