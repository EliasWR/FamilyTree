#ifndef FAMILYTREE_NODE_H
#define FAMILYTREE_NODE_H

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <utility>
#include <ostream>


class Node {
private:
    std::shared_ptr<Person> _person;
    Node *_parent = nullptr;
    std::vector<Node *> _children;

public:
    // Constructor taking person.
    // Creating person objects with unique ownership in the node.
    explicit Node(const Person &person) : _person(std::make_unique<Person>(person)) {}

    [[nodiscard]] Person &getPerson() {
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

    void traverseUpwards(std::function<void(Node *)> f) {
        f(this);
        if (hasChild()) {
            _parent->traverseUpwards(f);
        }
    }

    void traverseDepthFirst(std::function<void(Node *)> f) {
        f(this);
        for (auto c: _children) {
            c->traverseDepthFirst(f);
        }
    }

    void add(Node &f) {
        f._parent = this; // this -> parent node*
        _children.emplace_back(&f);
    }

    template<class T>
    friend std::ostream &operator<<(std::ostream &, const Node<T> &);
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> &l) {
    auto &myPerson = l.getPerson();
    os << myPerson.getFirstName();
    os << " ";
    os << myPerson.getLastName();
    os << std::endl;

    return os;
}


#endif //FAMILYTREE_NODE_H
