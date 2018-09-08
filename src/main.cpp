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
    
    // Testando FanOut dos nodes
    //      
    // list<AndNode*> inputs = aig->getAndNodes();
    // std::for_each(inputs.begin(), std::next(inputs.begin(),inputs.size()),[&](AndNode* el) {
    //     const char* el_name = el->getName().c_str();
    //     cout << "And name [" << el_name << "]" << endl;
    //     AigNode* node = el->getFanIn(0);
    //     cout << "Fan 0: " << node->getName() << endl;
    //     AigNode* node1 = el->getFanIn(1);
    //     cout << "Fan 1: " << node1->getName() << endl;
    //     vector<AigNode*> node2 = el->getFanOut();
    //     AigNode* first = node2.front();
    //     if(first->getType() == 0){
    //         AndNode* test = (AndNode*)node2.front();
    //         cout << "Fanout and: " << test->getName() << endl;
    //         if(node2.size() == 2){
    //             AigNode* second = node2.at(1);
    //             if(second->getType() == 0){
    //                 AndNode* test2 = (AndNode*)second;
    //                 cout << "Fanout and: " << test2->getName() << endl;
    //             }
    //         }
    //     } else {
    //         OutputNode* test = (OutputNode*)node2.front();
    //         cout << "Fanout out: " << test->getName() << endl;
    //     }
    // });

    cout << "# name of AIG: " << aig->getName() << "\n";
    cout << "  * number of Nodes:   " << aig->getNodes().size() << "\n";
    cout << "  * number of Inputs:  " << aig->getInputs().size() << "\n";
    cout << "  * number of Outputs: " << aig->getOutputs().size() << "\n";
    cout << "  * number of Ands: " << aig->getAndNodes().size() << "\n";

    return EXIT_SUCCESS;
}
