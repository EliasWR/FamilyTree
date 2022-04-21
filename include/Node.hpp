#ifndef FAMILYTREE_NODE_HPP
#define FAMILYTREE_NODE_HPP

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <utility>
#include <ostream>
#include <memory>
#include <queue>
#include "Person.hpp"

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

    void traverseDepthSearch(Node<T> a, std::function <void(Node <T> *)> editingFunc ,std::string &firstname, std::string &lastname) {
        a.traverseDepth([&](Node<T>* a) {
            if (a->getPerson().getFirstName() == firstname && a->getPerson().getLastName() == lastname) {
                std::cout << a->getPerson().getFirstName() << a->getPerson().getLastName() << " exists in tree." << std::endl;
                auto &myPerson = a->getPerson();
                myPerson.editingFunc(a);
            }
        });
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


#endif//FAMILYTREE_NODE_HPP
