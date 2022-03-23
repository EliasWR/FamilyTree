//
// Created by filip on 17.03.2022.
//

#ifndef FAMILYTREE_NODE_H
#define FAMILYTREE_NODE_H

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <utility>

class Node {
private:
    std::unique_ptr<Person> _person;
    Node* _parent = nullptr;
    std::vector<Node*> _children;

public:
    // Constructor taking person.
    // Creating person objects with unique ownership in the node.
    explicit Node(const Person& person): _person(std::make_unique<Person>(person)){}
    [[nodiscard]] Person& getPerson() {
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

    void traverseUpwards(std::function<void(Node*)> f) {
        f(this);
        if (hasChild()) {
            _parent -> traverseUpwards(f);
        }
    }

    void traverseDepthFirst(std::function<void(Node*)> f) {
        f(this);
        for (auto c : _children) {
            c -> traverseDepthFirst(f);
        }
    }

    void add(Node& f) {
        f._parent = this; // this -> folder*
        _children.emplace_back(&f);
    }

};

#endif //FAMILYTREE_NODE_H
