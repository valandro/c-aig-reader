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
    cout << "# name of AIG: " << aig->getName() << "\n";
    cout << "  * number of Nodes:   " << aig->getNodes().size() << "\n";
    cout << "  * number of Inputs:  " << aig->getInputs().size() << "\n";
    cout << "  * number of Outputs: " << aig->getOutputs().size() << "\n";
    cout << "  * number of Ands: " << aig->getAndNodes().size() << "\n";
    cout << "  * AIG Depth: " << aig->compute_depth(aig->getOutputs().front()) << endl;
    return EXIT_SUCCESS;
}
