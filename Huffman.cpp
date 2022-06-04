#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>


using namespace std;

class Node
{
public:
	int a;
	char c;
	Node* left, * right;

	Node() { left = right = NULL; }

	Node(Node* L, Node* R)
	{
		left = L;
		right = R;
		a = L->a + R->a;
	}

};


struct MyCompare
{
	bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};



vector<bool> code;
map<char, vector<bool> > table;



int main(int argc, char* argv[])
{

	ifstream f("1.txt", ios::out | ios::binary);

	map<char, int> m;

	while (!f.eof())
	{
		char c = f.get();
		m[c]++;
	}



	list<Node*> t;
	for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
	{
		Node* p = new Node;
		p->c = itr->first;
		p->a = itr->second;
		t.push_back(p);
	}




	while (t.size() != 1)
	{
		t.sort(MyCompare());

		Node* SonL = t.front();
		t.pop_front();
		Node* SonR = t.front();
		t.pop_front();

		Node* parent = new Node(SonL, SonR);
		t.push_back(parent);

	}

	Node* root = t.front();



	return 0;
}