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





vector<bool> code;
map<char, vector<bool> > table;




int main(int argc, char* argv[])
{
	

	
			
	ifstream F("encode.txt", ios::in | ios::binary);
	ofstream G("decode.txt", ios::out | ios::binary);

	
	int n;

	char c,size,b;
	vector <bool> v;
	

for(;;)
	{
		c = F.get();
		if(c=='|') break;
		size = F.get();
		
	
for(int i = 0; i< size-48 ; i++)
{
	b=F.get();
	if(b==48) v.push_back(0);
	else 	v.push_back(1);

}
table[c] = v;
v.clear();

	}
	
 







	setlocale(LC_ALL, "Russian"); 


	int count = 0; char byte;
	byte = F.get();
	while (!F.eof())
	{
		bool b = byte & (1 << (7 - count));
		
		v.push_back(b);
		
			for (map<char, vector<bool> >::iterator itr = table.begin(); itr != table.end(); ++itr)
	{
		
		if(itr->second == v) {
		G<<itr->first; v.clear();
	}
	
	}
		
		
			count++;
			if (count == 8) { count = 0; byte = F.get(); }
	
	}

	F.close();
	G.close();

	return 0;
}