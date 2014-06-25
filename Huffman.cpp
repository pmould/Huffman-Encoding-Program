#include<iostream>
#include<string>
#include"Huffman.h"
#include<limits.h>
using namespace std;


	Huffman::Huffman()
	{
	}
	void Huffman::insert(char Char, int weight)
	{
		
		Tree[nodeCount].Character = Char;
		Tree[nodeCount].Weight = weight;
		Tree[nodeCount].Parent= 0;
		Tree[nodeCount].ChildType = NULL;
		Tree[nodeCount].HasParentOrRoot = false;
		nodeCount++;
	}
	
	bool Huffman::inTree(char Char)
	{
		for (int i =0; i< nodeCount;i++)
		{
			if (Tree[nodeCount].Character == Char)
			{
				return  true;
			
			}
		}
		return false;
	}	
	
	
	//Gets the frequency of a character stored in the tree
	int Huffman::GetFrequency(char Char)
	{
		for (int i =0; i < nodeCount; i ++)
		{
			if (Tree[i].Character == Char)
			{
				return Tree[i].Weight;
			}
		}
		return 0;
	}

	string Huffman::GetCode(char Char)
	{

	}
	void Huffman:: PrintTable()
	{
		cout << "\t\t++++ ENCODING TABLE ++++\n"<<endl;
		cout << "\tIndex   Char    Weight  Parent  ChildType"<<end; 
		
	}

	int Huffman:: numNodes()
	{
		return nodeCount; 
	}

	void Huffman::mergeNodes()
	{
		if(nodeCount ==1)
		{
			Tree[0].Parent ==0;
			return;
		}
		while (!isBuilt())                // Keep merging SmallestTwo
			mergeSmallestTwo();
	}

	void Huffman::mergeSmallestTwo()
	{
		int index1, index2;
		findSmallestTwo(index1, index2);  // retruns the locations via pass by &
		Tree[index1].Parent = nodeCount;
		Tree[index2].Parent = nodeCount;
		Tree[index1].HasParentOrRoot = true;
		Tree[index2].HasParentOrRoot = true;

		Tree[index1].ChildType = 0; Tree[index2].ChildType = 1;

		Tree[nodeCount].Character = '\0';   // dummy char won't use
		Tree[nodeCount].Weight = Tree[index1].Weight + Tree[index2].Weight;
		Tree[nodeCount++].Parent = 0;
		Tree[nodeCount].HasParentOrRoot = true;
	}

// isBuilt returns a true value if  all the nodes has a parent except the root node
	bool  Huffman:: isBuilt() 
	{
		for(int i=0; i< nodeCount-1; i++)
		{
			if ( Tree[i].HasParentOrRoot == false)
				return false;
		}

		int rootNode = nodeCount;
		if ( Tee[rootNode].HasParentOrRoot == false)
			return false;
		return true;
	}

	void Huffman:: findSmallestTwo( int& index1, int& index2) const
	{
		int count =0;
		int max = INT_MAX;
		for (int i = 0; i< nodeCount; i++)
		{
			if (Tree[i].Parent = 0 && Tree[i].Weight< max)
			{
				index1=i;
				max = Tree[i].weight;
			}	
		}

		for (int i = 0; i<nodeCount; i++)
		{
			if(Tree[i].Parent = 0 && Tree[i].Weight< max)
			{
				index2 = i;
				max = Tree[i].Weight;
			}
		}
	}
