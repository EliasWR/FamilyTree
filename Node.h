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

//This code showcases a generic tree type data structure

class Node {

public:
    // Constructor taking person.
    // Creating person objects with unique ownership in the node.
    explicit Node(const Person& person): _person(std::make_unique<Person>(person)){}
    [[nodiscard]] Person& getPerson() {
        return *_person;
    }

    [[nodiscard]] bool isRoot() const {
        return parent_ == nullptr;
    }

    [[nodiscard]] bool isLeaf() const {
        return children_.empty();
    }

    bool hasParent() {
        return parent_ != nullptr;
    }

    void traverseUpwards(std::function<void(Node*)> f) {
        f(this);
        if (hasParent()) {
            parent_ -> traverseUpwards(f);
        }
    }

    void traverseDepthFirst(std::function<void(Node*)> f) {
        f(this);
        for (auto c : children_) {
            c -> traverseDepthFirst(f);
        }
    }


    void add(Node& f) {
        f.parent_ = this; // this -> folder*
        children_.emplace_back(&f);

    }

private:
    std::unique_ptr<Person> _person;
    Node* parent_ = nullptr;
    std::vector<Node*> children_;
};

#endif //FAMILYTREE_NODE_H
