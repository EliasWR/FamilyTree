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

int globalNodeIndex = 0;

template <class T>
class Node {
private:
    std::shared_ptr<T> _person;
    Node *_parent = nullptr;
    std::vector<std::shared_ptr<Node<T>>> _children;
    int _index;
public:
    // Constructor taking person.
    // Creating person objects with unique ownership in the node.
    explicit Node(const T &t) : _person(std::make_unique<T>(t)) {
      globalNodeIndex += 1;
      _index = globalNodeIndex;
      // TODO Make destructor for Nodes
    }

    T &getPerson() const {
        return *_person;
    }

    Node &getParent () const {
      return *_parent;
    }

    std::vector<Node *> getChildren () const {
      return *_children;
    }

    [[nodiscard]] int getIndex () const {
      return _index;
    }

    [[nodiscard]]bool isRoot() const {
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
    void traverseDepth(std::function<void(Node<T> *, int)> f, int depth = 0) {
        f(this, depth);
        for (auto c: _children) {
            c->traverseDepth(f, depth + 1);
        }
    }

    void traverseDepthSearch(Node<T> root, std::string firstname, std::string lastname, std::function <void(T&)> editingFunc ) {
        root.traverseDepth([firstname, lastname, editingFunc](Node<T>* node) {
            if (node->getPerson().getFirstName() == firstname && node->getPerson().getLastName() == lastname) {
                std::cout << node->getPerson().getFirstName() << node->getPerson().getLastName() << " exists in tree." << std::endl;
                auto &myPerson = node->getPerson();
                editingFunc(myPerson);
            }
        });
    }

    // TODO Implement breadth first traversal

    void traverseBreadthFirst(std::function<void(Node<T> *)> f) {

    }

    void add(T value) {
      auto n = std::make_shared<Node <T>>(value);
      n->_parent = this;
      _children.emplace_back(n);
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
