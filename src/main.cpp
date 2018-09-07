#include <cstdlib>
#include <list>
#include "aagReader.h"
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    string path_to_file = "input/" + std::string(argv[1]) + ".aag";
    AAGReader reader(path_to_file);
    Aig* aig = reader.readFile();
    
    list<AndNode*> inputs = aig->getAndNodes();
    std::for_each(inputs.begin(), std::next(inputs.begin(),inputs.size()),[&](AndNode* el) {
        const char* el_name = el->getName().c_str();
        cout << "And name [" << el_name << "]" << endl;
        AigNode* node = el->getFanIn(0);
        cout << "Fan 0: " << node->getName() << endl;
        AigNode* node1 = el->getFanIn(1);
        cout << "Fan 1: " << node1->getName() << endl;
    });

    cout << "# name of AIG: " << aig->getName() << "\n";
    cout << "  * number of Nodes:   " << aig->getNodes().size() << "\n";
    cout << "  * number of Inputs:  " << aig->getInputs().size() << "\n";
    cout << "  * number of Outputs: " << aig->getOutputs().size() << "\n";
    cout << "  * number of Ands: " << aig->getNodes().size()-aig->getInputs().size()-aig->getOutputs().size() << "\n";

    return EXIT_SUCCESS;
}
