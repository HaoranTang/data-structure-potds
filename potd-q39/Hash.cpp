#include <vector>
#include <string>
#include "Hash.h"
#include <vector>
#include <map>
using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
    int sum = 0;
    for (unsigned i=0; i<s.length(); i++){
        sum += s[i];
    }
    return sum % M;
 }

int countCollisions (int M, vector<string> inputs) {
    int collisions = 0;
    // Your Code Here
    vector<int> v;
    map<int, int> m;
    for(unsigned i = 0; i < inputs.size(); i++)
        v.push_back(hashFunction(inputs[i], M));
    
    for(unsigned i = 0; i < v.size(); i++)
        m[v[i]]++;
    
    for(auto &it : m){
        if(it.second != 1)
            collisions += (it.second - 1);
    }
    
    return collisions;
}
