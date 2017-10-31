#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>


using namespace std;
	
#define PN 				cout<<'\n'
#define PI 			    3.1415926535
#define MOD				1000000007

struct node
{
	struct node *right;
	struct node *left;
	//struct node *parent = NULL;
	int freq;
	char ch;
}*root;

struct comp_func{
  bool operator()(const struct node& a,const struct node& b) const{
    return a.freq > b.freq;
  }
};
map<char, int> freq_table;
vector<struct node> x, y;

struct node extract_min(vector<struct node> &v){
	struct node temp(v.front());
	pop_heap (v.begin(),v.end(), comp_func()); 
	v.pop_back();
	cout<<"Min Heap Top Element: ---"<<temp.ch<<"  "<<temp.freq<<"\n";;	
	return temp;
}


void construct_tree(){
	int n = freq_table.size();
	vector<struct node> V;
	for (map<char, int>::iterator i = freq_table.begin(); i != freq_table.end(); ++i)
	{
		struct node *N =(struct node*) malloc(sizeof(struct node) );
		N->freq = i->second;
		N->ch = i->first;
		N->left = NULL;
		N->right = NULL;
		V.push_back(*N);
		// cout<<"s\n";
	}

	x.resize(n);
	y.resize(n);	
	make_heap(V.begin(), V.end(), comp_func());

	for(unsigned i = 0; i < n - 1; ++i) {
		struct node *N =(struct node*) malloc(sizeof(struct node) );
		x[i] = extract_min(V);
		N->left = &x[i];
		y[i] = extract_min(V);
		N->right = &y[i];
		N->freq = x[i].freq + y[i].freq;
		N->ch = '#';
		if(V.size() == 0) {
			root = N;
			return;
		}
		V.push_back(*N);
		push_heap (V.begin(),V.end(), comp_func());
		// cout<<"d\n";
	}
}

void decode(struct node *ptr, vector<int> &v, int top){
	if(!ptr->left && !ptr->right){
		cout<<"Code for \'"<<ptr->ch<<"\': ";
		copy(v.begin(), v.begin()+top,
				ostream_iterator<int>(cout," "));
		cout<<"\n";	
		return;	
	}
	// cout<<ptr->freq;cout<<"\n";
	if(ptr->left) {
		v[top] = 0;
		// int t; cin>>t;
		// cout<<'\n'<<ptr->ch<<" --- "<<ptr->freq<<'\n';
		decode(ptr->left, v, top+1);

	}
	if(ptr->right) {
		v[top] = 1;
		// int t; cin>>t;
		// cout<<'\n'<<ptr->ch<<" -*-*- "<<ptr->freq<<'\n';
		decode(ptr->right, v, top+1);
	}

	
}

int main()
{
	int max_height = 20;
	vector<int> arr(20);
	string s;
	cin>>s;

	for(unsigned i = 0; i < s.size(); ++i) {
		if(freq_table.find(s[i]) == freq_table.end())
			freq_table.insert(make_pair(s[i], 1));
		else
			freq_table[s[i]]++;
		// cout<<"sd\n";
	}
	cout<<"\n\tFreq Table: \n";
	for (map<char, int>::iterator i = freq_table.begin(); i != freq_table.end(); ++i){
		cout<<"\t"<<i->first<<" --- "<<i->second<<'\n';
	}
	
	cout<<"\n";
	construct_tree();
	cout<<'\n';
	decode(root, arr, 0);
	
	return 0;
}
