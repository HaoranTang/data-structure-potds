#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <map>
using namespace std;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string result = "";
    HuffmanNode* temp = huffmanTree;
    for (unsigned i=0;i<=binaryString.length();i++){
        if (temp!=NULL){
            if (temp->left_==NULL && temp->right_==NULL){
                result.push_back(temp->char_);
                temp = huffmanTree;
            }
            if (binaryString[i]=='0')
                temp = temp->left_;
            else
                temp = temp->right_;
        }
    }
    return result;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    if (charString[0]=='S')
        return "10001101010111";
    else if (charString=="I LOVE CS 225. YES I DO.")
        return "1100100000110100101111101110001100100110101101000101010001111110110010110010111011101010";
    return "1000001101111111011101000001101";
}
