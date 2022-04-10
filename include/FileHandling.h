#ifndef FAMILYTREE_FILEHANDLING_H
#define FAMILYTREE_FILEHANDLING_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Node.h"
#include "LinkedList.h"


class XmlWriter {
private:
    std::ofstream outFile;
    int indent;
    int openTags;
    int openElements;
    std::vector<std::string> tempOpenTag;
    std::vector<std::string> tempElementTag;
public:
    bool open(const std::string);
    void close();
    bool exists(const std::string);
    void writeOpenTag(const std::string);
    void writeCloseTag();
    void writeStartElementTag(const std::string);
    void writeEndElementTag();
    void writeAttribute(const std::string);
    void writeString(const std::string);
    void writeString(char);
    void writeString(int);
    void readFile(std::string);
};

#endif //FAMILYTREE_FILEHANDLING_H
