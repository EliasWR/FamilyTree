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

class folder {

public:
    explicit folder(const std::string &name) : name_(std::move(name)) {}

    [[nodiscard]] std::string getName() const {
        return name_;
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

    void traverseUpwards(std::function<void(folder*)> f) {

        f(this);
        if (hasParent()) {
            parent_ -> traverseUpwards(f);
        }
    }

    void traverseDepthFirst(std::function<void(folder*)> f) {
        f(this);
        for (auto c : children_) {
            c -> traverseDepthFirst(f);
        }
    }


    void add(folder& f) {
        f.parent_ = this; // this -> folder*
        children_.emplace_back(&f);

    }

private:
    std::string name_;

    folder* parent_ = nullptr;
    std::vector<folder*> children_;

};

#endif //FAMILYTREE_NODE_H
