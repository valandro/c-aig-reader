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
    AndNode* findAndNode(list<AndNode*> list, string label);
    void connectInputToAndNode(AndNode* node_and, Aig* aig, string input_labelm , int pin);
    void connectAndToOutput(AndNode* node_and, Aig* aig);
    void connectInputToOutput(InputNode* node_input, Aig* aig);
    int isInverted(string label);
    void setFanInNames(AndNode* and_node, string fan0Name, string fan1Name);
    int compute_depth(AigNode* node);
};

#endif // AAGREADER_H
