#include "potd.h"
#include <string>
#include <vector>
// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end){
    double sum=0;
    for (vector<double>::iterator i =start; i!=end; i++){sum+= *i;}
    return sum;
}


vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
    vector<double>::iterator maxindex = start;
    for (vector<double>::iterator i =start; i!=end; i++){
        if (*maxindex < *i)
            maxindex = i;
    }
    return maxindex;
}


void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
    if (start==end)
        return;
    for (vector<double>::iterator i=start; i!=end;i++){
        vector<double>::iterator max = max_iter(i,end);
        double val = *i;
        *i = *max;
        *max = val;
    }
}
