#ifndef FAMILYTREE_NODE_H
#define FAMILYTREE_NODE_H

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <utility>
#include <ostream>
#include <memory>
#include <queue>
#include "Person.h"

template <class T>
class Node {
private:
    std::shared_ptr<T> _person;
    Node *_parent = nullptr;
    std::vector<Node *> _children;

public:
    // Constructor taking person.
    // Creating person objects with unique ownership in the node.
    explicit Node(const T &t) : _person(std::make_unique<T>(t)) {}

    T &getPerson() const {
        return *_person;
    }

    [[nodiscard]] bool isRoot() const {
        return _parent == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return _children.empty();
    }

    bool hasChild() {
        return _parent != nullptr;
    }

    void traverseUpwards(std::function<void(Node<T> *)> f) {
        f(this);
        if (hasChild()) {
            _parent->traverseUpwards(f);
        }
    }

    void traverseDepth(std::function<void(Node<T> *)> f) {
        f(this);
        for (auto c: _children) {
            c->traverseDepth(f);
        }
    }

    Node traverseDepth(std::function<void(Node<T> *)> f, std::string firstname, std::string lastname) {
        f(this);
        for (auto c: _children) {
            auto &myPerson = f.getPerson();
            if (myPerson.getFirstName() == firstname && myPerson.getLastName() == lastname) {
               break;
            }
            c->traverseDepth(f);
        }
        return myPerson;

    }


    // TODO Implement breadth first traversal

    void traverseBreadthFirst(std::function<void(Node<T> *)> f) {

    }

    void add(Node &f) {
        f._parent = this; // this -> parent node*
        _children.emplace_back(&f);
    }

    template<class E>
    friend std::ostream &operator<<(std::ostream &, const Node<E> &);
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> &l) {
    auto &myPerson = l.getPerson();
    os << myPerson.getFirstName();
    os << " ";
    os << myPerson.getLastName();
    return os;
}


#endif //FAMILYTREE_NODE_H
