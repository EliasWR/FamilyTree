#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>


namespace nlohmann {
  template<class T>

  /// @what Overloading the json functions from the nlohmann library in order to catch template exception
  /// @param "json &j" and "std::shared_ptr<Node<T>> n" mirrors other to_json function
  /// @returns N/A
  /// @Usage nlohmann::json::to_json
  /// @example to_json (j,node);
  void to_json(json &j, std::shared_ptr<Node<T>> n) {
    throw std::runtime_error("Unknown type T");
  };

  /// @what Overloading the json functions from the nlohmann library in order to write persons to file
  /// @param All info is written to the reference "json &j" and "std::shared_ptr<Node<T>> n"
  /// @returns N/A
  /// @Usage nlohmann::json::to_json
  /// @example nlohmann::json j(rootNode);
  void to_json(json &j, std::shared_ptr<Node<Person>> n) {
    Person p = n->getPerson();
    j = json{
      {"FirstName", p.getFirstName()},
      {"LastName", p.getLastName()},
      {"Birth", p.getBirth()},
      {"Death", p.getDeath()},
      {"Sex", p.getSex()},
      {"Children", n->getChildren()}};
  }
}// Namespace nlohmann

template<class T>
class JsonFile {
private:
  const std::string _fileName;
  std::shared_ptr<Node<T>> &_rootNode;
  std::ofstream f;
  std::string _parentFirstName, _parentLastName;

public:
  /// @what Constructor for JsonFile
  /// @param "std::shared_ptr<Node<T>> &t" initiates objects private variable _rootNode ,\n
  ///         "std::string const &fileName" initiates objects private variable _fileName
  /// @returns N/A
  /// @Usage Menu::saveNodes, Menu::getSavedNodes
  /// @example JsonFile json(rootNode, fileName);
  explicit JsonFile(std::shared_ptr<Node<T>> &t, std::string const &fileName)
      : _rootNode(t), _fileName(fileName) {
  }

  /// @what Opens or creates file with ofstream library.
  /// @param N/A
  /// @returns N/A
  /// @Usage Menu::saveNodes
  /// @example json.openFile();
  void openFile() {
    f.open(_fileName, std::ios_base::trunc | std::ios_base::out);
  }

  /// @what Closes a file
  /// @param N/A
  /// @returns N/A
  /// @Usage Menu::getSavedNodes, Menu::saveNodes
  /// @example json.closeFile();
  void closeFile() {
    f.close();
  }

  /// @what Checks if a file is empty
  /// @param N/A
  /// @returns Werther the file is empty(True) or not(False) and if the file is not open(True)
  /// @Usage Menu::getSavedNodes
  /// @example if (!json.isEmpty()){};
  bool isEmpty() {
    std::ifstream file(_fileName);
    if (!file) {
      std::cout << "File could not be opened.";
      return true;
    }
    bool fileIsEmpty = file.peek() == std::ifstream::traits_type::eof();
    return fileIsEmpty;
  }

  /// @what Function moves contents to file
  /// @param "nlohmann::json &j" brings the contents to be moved
  /// @returns N/A
  /// @Usage Menu::saveNodes
  /// @example json.jsonToFile(j);
  void jsonToFile(nlohmann::json &j) {
    f << j.dump(4);
  }
  /// @what Function reads contents of .json file and returns it to j
  /// @param "nlohmann::json &j" is mutated to hold contents of file
  /// @returns nlohmann::json j which holds contents of file
  /// @Usage Menu::getSavedNodes
  /// @example nlohmann::json j = json.readFile(j);
  nlohmann::json readFile(nlohmann::json j) {
    std::ifstream file(_fileName);
    file >> j;
    return j;
  }

  /// @what Function writes persons from tree to json using the to_json () function previously overloaded
  /// @param N/A
  /// @returns nlohmann::json personJson which holds contents of all nodes
  /// @Usage Menu::saveNodes
  /// @example nlohmann::json j = json.nodesToJson();
  nlohmann::json nodesToJson() {
    nlohmann::json personJson(_rootNode);
    return personJson;
  }

  /// @what Retrieves person from .json to nlohmann::json &j
  /// @param "nlohmann::json &j" is read and information is used to create a person
  /// @returns "Person person" a person of type Person
  /// @Usage JsonFile::nodeFromJson
  /// @example Person person = personFromJson(j);
  Person personFromJson(nlohmann::json &j) {
    std::string firstName, lastName, birth, death, sex;
    if (j.contains("FirstName")) {
      firstName = j.at("FirstName");
    }
    if (j.contains("LastName")) {
      lastName = j.at("LastName");
    }
    if (j.contains("Birth")) {
      birth = j.at("Birth");
    }
    if (j.contains("Death")) {
      death = j.at("Death");
    }
    if (j.contains("Sex")) {
      sex = j.at("Sex");
    }

    Person person(firstName, lastName, birth, death, sex);
    return person;
  }

  /// @what Retrieves nodes from .json and get saved information recursively
  /// @param "nlohmann::json &j" is used to traverse tree in file\n
  ///         "std::shared_ptr<Node<Person>> rootNode" is used to store all node information
  /// @returns "std::shared_ptr<Node<Person>>" containing all previously saved nodes
  /// @Usage Menu::getSavedNodes
  /// @example auto node = json.nodeFromJson(j, emptyNode);
  std::shared_ptr<Node<Person>> nodeFromJson(nlohmann::json &j, std::shared_ptr<Node<Person>> rootNode) {
    Person person;

    if (rootNode->isEmpty()) {
      person = personFromJson(j);
      rootNode = std::make_shared<Node<Person>>(person);
    }

    if (j.contains("Children") && !j.at("Children").empty()) {
      for (auto jsonChildNode: j.at("Children")) {
        if (j.contains("FirstName")) {
          _parentFirstName = j.at("FirstName");
        }
        if (j.contains("LastName")) {
          _parentLastName = j.at("LastName");
        }
        person = personFromJson(jsonChildNode);
        auto lambda = [ person ](Node<Person> &node) {
          node.add(person);
        };
        rootNode->traverseDepth(lambda, _parentFirstName, _parentLastName);
        nodeFromJson(jsonChildNode, rootNode);
      }
    }
    _rootNode = rootNode;
    return rootNode;
  }
};

#endif//FAMILYTREE_JSONFILE_HPP
