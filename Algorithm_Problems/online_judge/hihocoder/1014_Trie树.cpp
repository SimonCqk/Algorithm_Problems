
#include<iostream>
#include<algorithm>
#include<string>
#define CHILD_MAX 26

using namespace std;

//define and initialize TrieTree 
typedef struct Trie_Tree
{
	unsigned int value;
	char  key;
	struct Trie_Tree* child[CHILD_MAX];
	Trie_Tree() :value(0) {
		int i;
		for (i = 0; i < CHILD_MAX; ++i)child[i] = nullptr;
	}
}TrieTree;



void Insert_Tree(TrieTree* TREE, const string s) {
	TrieTree* T = TREE;
	string::const_iterator beg = s.cbegin(), ed = s.cend();
	if (!*beg || !T)return;
	while (beg != ed) {
		if (T->child[*beg - 'a'] == nullptr) {
			T->child[*beg - 'a'] = new TrieTree();
			T->child[*beg - 'a']->key = *beg;
			T = T->child[*beg - 'a'];
			++T->value;// cout << T->value<<endl;
		}
		else {
			T->child[*beg - 'a']->key = *beg;
			T = T->child[*beg - 'a'];
			++T->value;// cout << T->value<<endl;
		}
		++beg;
	}
}

unsigned int Query_value(TrieTree* TREE, string s) {
	TrieTree* Tp = TREE;
	string::const_iterator item = s.cbegin(), ed = s.cend();
	while (item != ed) {
		if (Tp->child[*(item)-'a'] == nullptr)return 0;
		Tp = Tp->child[*(item++) - 'a'];
	}

	return Tp->value;
}



int main() {
	TrieTree* TREE = new TrieTree();
	int dic_size, get_size;
	cin >> dic_size;
	string s, query_s;
	for (int i = 0; i < dic_size; ++i) {
		cin >> s;
		Insert_Tree(TREE, s);
	}
	cin >> get_size;
	unsigned int get_value;
	for (int i = 0; i < get_size; ++i) {
		cin >> query_s;
		get_value = Query_value(TREE, query_s);
		cout << get_value << endl;
	}
	delete TREE;
	return 0;
}

/*
//version of : char[20]  ->  string
#include<iostream>
#include<algorithm>
#include<string>
#define CHILD_MAX 26

using namespace std;

//define and initialize TrieTree
typedef struct Trie_Tree
{
unsigned int value;
char  key;
struct Trie_Tree* child[CHILD_MAX];
Trie_Tree():value(0){
int i;
for (i = 0; i < CHILD_MAX; ++i)child[i] = nullptr;
}
}TrieTree;



void Insert_Tree(TrieTree* TREE, char* s) {
TrieTree* T=TREE;
//string::iterator beg = s.begin(), ed = s.end();
if (!*s)return;
while (*s) {
if (T->child[*s - 'a'] == nullptr) {
T->child[*s - 'a'] = new TrieTree();
T->child[*s - 'a']->key = *s;
T = T->child[*s - 'a'];
++T->value; //cout << T->value;
}
else {
T->child[*s - 'a']->key = *s;
T = T->child[*s - 'a'];
++T->value; //cout << T->value;
}
++s;
}
}

void Find_value(TrieTree* TREE,char *s) {
TrieTree* Tp = TREE;
//string::const_iterator item = s.cbegin(),ed=s.cend();
while ( *s &&Tp->child[*(s)-'a'] != nullptr) {
Tp = Tp->child[*(s++)-'a'];
//if (item + 1 == ed)break;//cout << Tp->value;
}

if(!(*s))cout<< Tp->value<<endl;
else cout<< 0<<endl;
}



int main() {
TrieTree* TREE = new TrieTree();
int dic_size,get_size;
cin >> dic_size;
//string s,query_s;
char s[20], query_s[20];
for (int i = 0; i < dic_size;++i) {
cin >> s;
Insert_Tree(TREE, s);
}
cin >> get_size;
for (int i = 0; i < get_size; ++i) {
cin >> query_s;
Find_value(TREE,query_s);
}
//delete TREE->child;
return 0;
}

*/