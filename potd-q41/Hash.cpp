#include "Hash.h"
#include <string>
#include <algorithm>
using namespace std;
unsigned long bernstein(string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
    for (unsigned i=0; i<str.length(); i++){
        b_hash *=33;
        b_hash += str[i];
    }
	return b_hash % M;
}

string reverse(string str)
{
    string output = "";
	//Your code here
    for(unsigned i = 0; i < str.length() / 2; i++){
        swap(str[i], str[str.length() - i - 1]);
    }
	return str;
}
