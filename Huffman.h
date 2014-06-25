
using namespace std;
#include <string>


        struct HuffNode
        {
                char Character;
                int Weight;
                int Parent;
                int ChildType;
		int HasParentOrRoot;

        };

class Huffman
{
public:
        Huffman();
        void insert(char Char, int weight);
        bool inTree(char Char);
        int GetFrequency(char Char);
        string GetCode(char Char);
        void PrintTable();
        int numNodes();
	void mergeNodes();

private:

  	int nodeCount;
        int maxNodes;
	HuffNode Tree[255];

	bool isBuilt();
	void mergeSmallestTwo();
	void findSmallestTwo(int& index1, int& index2)const;
};
