#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> mapA,
                                        unordered_map<string, int> mapB) {

    // your code here
    unordered_map<string, int>unordered;
    vector<string>v;
    for(unordered_map<string, int>::iterator itA = mapA.begin(); itA != mapA.end(); itA++){
        for(unordered_map<string, int>::iterator itB = mapB.begin(); itB != mapB.end(); itB++){
            if(itA->first == itB->first){
                unordered[itA->first]+=itA->second;
                unordered[itA->first]+=itB->second;
                v.push_back(itA->first);
                break;
            }
        }
    }
    for(unordered_map<string, int>::iterator it = unordered.begin(); it != unordered.end(); it++){
        mapA.erase(it->first);
        mapB.erase(it->first);
    }
    return unordered;
} 
