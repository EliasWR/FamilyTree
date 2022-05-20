#ifndef FAMILYTREE_NODE_HPP
#define FAMILYTREE_NODE_HPP

#include "Person.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

template<class T>
class Node {
private:
  std::shared_ptr<T> _person;
  Node *_parent = nullptr;
  std::vector<std::shared_ptr<Node<T>>> _children;

public:
  /// @what Default constructor
  /// @param N/A
  /// @returns N/A
  /// @usage JsonFile::getSavedNodes
  /// @example auto emptyNode = std::make_shared<Node<Person>>();
  explicit Node() = default;

  /// @what Constructor of generalized templated node holding T value with unique ownership in node
  /// @param "const T &t" templated parameter able to hold desired value
  /// @returns N/A
  /// @usage JsonFile::nodeFromJson
  /// @example auto node = std::make_shared<Node<Person>>();
  explicit Node(const T &t)
      : _person(std::make_unique<T>(t)) {
  }
  /// @what Getter for retrieving pointer to person the node is holding
  /// @param N/A
  /// @returns T pointer to the person node is holding
  /// @usage Menu::printTree
  /// @example auto person = node.getPerson();
  [[nodiscard]] T &getPerson() const {
    return *_person;
  }

  /// @what Getter for retrieving pointer to parent the node is holding
  /// @param N/A
  /// @returns T pointer to the person node is holding
  /// @usage N/A
  /// @example auto parent = node.getPerson();
  [[nodiscard]] Node<T> *getParent() const {
    return _parent;
  }

  /// @what Getter for retrieving children
  /// @param N/A
  /// @returns Children vector - Vector holding pointers to all children of node
  /// @usage nlohmann::json
  /// @example auto children = node->getChildren();
  [[nodiscard]] std::vector<std::shared_ptr<Node<T>>> &getChildren() {
    return _children;
  }
  /// @what Setter for editing  children
  /// @param "std::vector<std::shared_ptr<Node<T>>> children" Gives new list of pointers to nodes containing children
  /// @returns N/A
  /// @usage N/A
  /// @example
  /// auto children = node1->getChildren();\n
  /// node2->setChildren(children);

  void setChildren(std::vector<std::shared_ptr<Node<T>>> children) const {
    _children = children;
  }
  /// @what Checks werther node is the root (Has no parent)
  /// @param N/A
  /// @returns a boolean; node is the root(True)/is not the root(False)
  /// @usage N/A
  /// @example bool nodeIsRoot = node.isRoot();
  [[nodiscard]] bool isRoot() const {
    return (_parent == nullptr);
  }

  /// @what Checks werther node is a leaf of the tree (Has no children)
  /// @param N/A
  /// @returns a boolean; node is a leaf(True)/is not a leaf(False)
  /// @usage N/A
  /// @example bool nodeIsLeaf = node.isLeaf();
  [[nodiscard]] bool isLeaf() const {
    return _children.empty();
  }

  /// @what Checks werther nodes person attribute is null-pointer
  /// @param N/A
  /// @returns a boolean; node is empty(True)/is not empty(False)
  /// @usage JsonFile::nodeFromJson
  /// @example bool isNodeEmpty = node.isEmpty();
  [[nodiscard]] bool isEmpty() const {
    return (_person == nullptr);
  }

  /// @what Tree traversal starting opposite of root
  /// @bigO is O(n) because it depends on the number of nodes in the tree
  /// @param "std::function<void(Node<T> &)> f" is a parameter for recursion taking current function
  /// @returns N/A
  /// @usage N/A
  /// @example bool isNodeEmpty = node.isEmpty();
  void traverseUpwards(std::function<void(Node<T> &)> f) {
    f(*this);
    if (!isRoot()) {
      _parent->traverseUpwards(f);
    }
  }

  /// @what Breadth first traversal starting from root
  /// @bigO is O(n) because it depends on the number of nodes in the tree
  /// @param "std::function<void(Node<T> &)> f" for recursive function
  /// @returns N/A
  /// @usage Node::TraverseDepthSearch
  /// @example traverseDepth (rootNode);
  void traverseDepth(std::function<void(Node<T> &)> f) {
    f(*this);
    for (auto c: _children) {
      c->traverseDepth(f);
    }
  }

  /// @what Overloaded breadth first traversal in order to print a tree structure
  /// @bigO is O(n) because it depends on the number of nodes in the tree
  /// @param "std::function<void(Node<T> &, int)> f" for recursive function
  ///        "int depth = 0" keeps track of level in tree and prints equivalent indents
  /// @returns N/A
  /// @usage Menu::printTree
  /// @example
  /// node->traverseDepth([ indent ](Node<Person> &f, int depth) {\n
  ///      for (int i = 0; i < depth; ++i) {\n
  ///        for (int j = 0; j < indent; ++j) {std::cout << " ";}}\n
  ///      std::cout << f.getPerson().getFirstName() << " " << f.getPerson().getLastName() << std::endl;});
  void traverseDepth(std::function<void(Node<T> &, int)> f, int depth = 0) {
    f(*this, depth);
    for (auto c: _children) {
      c->traverseDepth(f, depth + 1);
    }
  }
  /// @what Overloaded breadth first traversal in order to search for a specific node in tree
  /// @bigO is O(n) because it depends on the number of nodes in the tree
  /// @param "std::function<void(Node<T> &, int)> f" for recursive function\n
  ///        "std::string firstName" and "std::string lastName" is used for comparing all names in tree
  /// @returns N/A
  /// @usage Menu::createGeneralPerson, JsonFile::NodeFromJson
  /// @example
  /// auto lambda = [ p ](Node<Person> &node) { node.add(p);};\n
  /// rootNode->traverseDepth(lambda, a, b);
  void traverseDepth(std::function<void(Node<T> &)> f, std::string firstName, std::string lastName) {
    if (getPerson().getFirstName() == firstName && getPerson().getLastName() == lastName) {
      f(*this);
    } else {
      for (auto c: _children) {
        c->traverseDepth(f, firstName, lastName);
      }
    }
  }
  /// @what Overloaded breadth first traversal in order to make changes to persons
  /// @bigO is O(n) because it depends on the number of nodes in the tree
  /// @param "std::shared_ptr<Node<T>> root" rootNode where traversal will start
  ///        "std::string firstName" first name to be searched for\n
  ///        "std::string lastName" last name to be searched for\n
  ///        "std::function<void(T &)> editingFunc" lambda function for editing persons\n
  /// @returns N/A
  /// @usage Menu::changeFirstName, Menu::changeLastName, Menu::changeBirthDate, Menu::changeDeathDate,\n
  ///        Menu::changeGender
  ///
  /// , Menu::emptyPerson, Menu::printPerson
  /// @example
  /// auto lambda = [ newFirstName ](Person &p) {p.se
  /// tFirstName(newFirstName);};\n
  /// rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
  void traverseDepthSearch(std::shared_ptr<Node<T>> root, std::string &firstName, std::string &lastName, std::function<void(T &)> editingFunc) {
    bool personFound = false;
    root->traverseDepth([ firstName, lastName, editingFunc, &personFound ](Node<T> &node) {
      if (node.getPerson().getFirstName() == firstName && node.getPerson().getLastName() == lastName) {
        personFound = true;
        std::cout << node << " was found and operation has successfully been executed." << std::endl << std::endl;
        auto &myPerson = node.getPerson();
        editingFunc(myPerson);
      }
    });
    if (!personFound) {
      std::cout << firstName << " " << lastName << " could not be found in tree." << std::endl;
    }
  }
  /// @what Function for setting relations between parent and child
  /// @param "T value" is for the templated value that should be added
  /// @returns N/A
  /// @usage Menu::createGeneralPerson, JsonFile.nodeFromJson
  /// @example
  /// auto lambda = [ p ](Node<Person> &node) {node.add(p);};\n
  /// rootNode->traverseDepth(lambda, a, b);
  void add(T value) {
    auto n = std::make_shared<Node<T>>(value);
    n->_parent = this;
    _children.emplace_back(n);
  }

  template<class E>
  friend std::ostream &operator<<(std::ostream &, const Node<E> &);
};

/// @what Overloading the "<<" operator in order to print person directly from node
/// @param "std::ostream &os" taking ostream parameter to be compatible with << operator\n
///        "const Node<T> &node" takes the node that is to be printed
/// @returns Output stream object containing the final print
/// @usage Node::traverseDepthSearch
/// @example std::cout << node;
template<typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> &node) {
  auto &person = node.getPerson();
  os << person.getFirstName();
  os << " ";
  os << person.getLastName();
  return os;
}

#endif//FAMILYTREE_NODE_HPP
