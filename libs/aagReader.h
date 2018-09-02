#ifndef AAGREADER_H
#define AAGREADER_H
#include "aig.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class AAGReader
{
private:
    ifstream source;
    ofstream debug;
    string word;
    char buf[250];
    string file_name;
public:
    AAGReader(string sourcePath);
    Aig* readFile();
    InputNode* findInputNode(list<InputNode*> list, string label);
    OutputNode* findOutputNode(list<OutputNode*> list, string label);
};

#endif // AAGREADER_H
