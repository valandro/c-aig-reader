#include "aagReader.h"
#include <string.h>
#include<algorithm>

AAGReader::AAGReader(string sourcePath)
{
    // Parsing the file name
    file_name = sourcePath.c_str();
    size_t dot = file_name.find(".aag");
    file_name = file_name.substr(6,file_name.size()-1-dot);
    // Open the file
    source.open(sourcePath.c_str());
}

Aig* AAGReader::readFile()
{
    Aig* aig = new Aig();
    aig->setName(file_name);

    //Treating header
    source.getline(buf, 250, '\n');
    string s=buf;
    istringstream line;
    line.str(s);
    line >> word;

    if(strcmp("aag",word.c_str())!=0)
    {
        debug << "the file is not an AAG file!";
        return NULL;
    }

    int nNodes, nInputs, nFFs, nOutputs, nAnds;
    line >> word;
    nNodes = atoi(word.c_str());
    line >> word;
    nInputs = atoi(word.c_str());
    line >> word;
    nFFs = atoi(word.c_str());
    line >> word;
    nOutputs = atoi(word.c_str());
    line >> word;
    nAnds = atoi(word.c_str());

    if (nNodes != nInputs + nFFs + nAnds) {
        debug << "Wrong file header";
        return NULL;
    }

    if (nFFs != 0) {
        debug << "FF not supported yet";
        return NULL;
    }

    debug << s << "\nThe file header is ok!\n\n";

    AigNode** nodes = new AigNode*[nNodes + 1];
    OutputNode* outs = new OutputNode[nOutputs];
    InputNode* ins = new InputNode[nInputs];

    //Treating inputs
    for (int i = 1; i <= nInputs; i++) {
        // Get input value
        source.getline(buf, sizeof(int), '\n');
        string s = buf;
        istringstream line;
        line.str(s);
        line >> word;
        // Set input label name
        string name = word;
        InputNode *input = new InputNode();
        input->setName(name);
        aig->insertInputNode(input);
        aig->insertNode(input);
        debug << word << "\n";
    }

    //Treating outputs
    debug << "\n";
    for (int i = 1; i <= nOutputs; i++) {        
        // Get ouput value
        source.getline(buf, sizeof(int), '\n');
        string s = buf;
        istringstream line;
        line.str(s);
        line >> word;
        // Set output label name
        string name = "po" + std::to_string(i);
        OutputNode *output = new OutputNode();
        output->setName(name);
        aig->insertOutputNode(output);
        aig->insertNode(output);
        debug << word << "\n";
    }

    //Connecting ands
    debug << "\n";
    for (int i = 1; i <= nAnds; i++) {
        // Get ouput value
        vector<string> strings;
        source.getline(buf, 3 * sizeof(int),'\n');
        string s = buf;
        string c;
        istringstream line(s);
        // Parsing the AND line > [and] [and] [and]
        while(getline(line,c,' ')){
            strings.push_back(c);
        }
        cout << "AND: " << strings[1] << endl;
        this->findInputNode(aig->getInputs(),strings[1]);
        AndNode* node_and = new AndNode();
        
        aig->insertNode(node_and);
    }

    debug << "\n";
    string aigName;
    while(source)
    {
        source.getline(buf, 250, '\n');
        string s=buf;
        istringstream line;
        line.seekg(0);line.str(s);
        line >> word;

        if(strcmp("c",word.substr(0).c_str())==0){
            debug << "the comments began. Ignore the file from here!\n";
            break;
        } else if(strcmp(word.substr(0).c_str(),"i")==0){

        } else if(strcmp(word.substr(0).c_str(),"o")==0){

        } else if(strcmp(word.substr(0).c_str(),"l")==0){

        }
    }

    debug << "\ncreate the AIG and add all nodes\n";
    debug << "return the AIG";
    

    return aig;
}

// Function to find Input node on aig inputs;
InputNode* AAGReader::findInputNode(list<InputNode*> inputs, string label) {
    size_t input_size = inputs.size();
    std::for_each(inputs.begin(), std::next(inputs.begin(),input_size),[&](InputNode* el) {
        const char* el_name = el->getName().c_str();
        if(strcmp(el_name,label.c_str()) == 0){
            return el;
        }
    });
    return NULL;
}

// Function to find Output node on aig outputs;
OutputNode* AAGReader::findOutputNode(list<OutputNode*> outputs, string label) {
    size_t output_size = outputs.size();
    std::for_each(outputs.begin(), std::next(outputs.begin(),output_size),[&](OutputNode* el) {
        const char* el_name = el->getName().c_str();
        if(strcmp(el_name,label.c_str()) == 0){
            return el;
        }
    });
    return NULL;
}