#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

class HuffmanNode {
public:
    char data;
    unsigned freq;
    HuffmanNode *left, *right;
    HuffmanNode(char data, unsigned freq, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr);
    
    ~HuffmanNode(); 
};

class Compare {
public:
    bool operator()(HuffmanNode* left, HuffmanNode* right);
};

class HuffmanCoding {
public:
    HuffmanCoding();
    ~HuffmanCoding();

    std::string compress(const std::string& text);
    std::string decompress(const std::string& binaryStr);

private:
    void printCodes(HuffmanNode* root, std::string str);
    void deleteTree(HuffmanNode* node);
    HuffmanNode* root;
    std::unordered_map<char, std::string> huffmanCode;
    std::unordered_map<std::string, char> reverseHuffmanCode;
};

#endif 
