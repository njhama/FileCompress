#include "Huffman.h"

HuffmanNode::HuffmanNode(char data, unsigned freq, HuffmanNode* left, HuffmanNode* right) 
    : data(data), freq(freq), left(left), right(right) {}

HuffmanNode::~HuffmanNode() {
    delete left;
    delete right;
}

bool Compare::operator()(HuffmanNode* left, HuffmanNode* right) {
    return left->freq > right->freq;
}

HuffmanCoding::HuffmanCoding() : root(nullptr) {}

HuffmanCoding::~HuffmanCoding() {
    deleteTree(root);
}

std::string HuffmanCoding::compress(const std::string& text) {
    std::unordered_map<char, unsigned> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        pq.push(new HuffmanNode('\0', left->freq + right->freq, left, right));
    }

    root = pq.top();

    printCodes(root, "");

    std::string str;
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    return str;
}

std::string HuffmanCoding::decompress(const std::string& binaryStr) {
    std::string str;
    HuffmanNode* current = root;
    for (int i = 0; i < binaryStr.size(); i++) {
        current = binaryStr[i] == '0' ? current->left : current->right;
        if (!current->left && !current->right) {
            str += current->data;
            current = root;
        }
    }
    return str;
}

void HuffmanCoding::printCodes(HuffmanNode* root, std::string str) {
    if (!root) return;
    if (root->data != '\0') {
        huffmanCode[root->data] = str;
        reverseHuffmanCode[str] = root->data;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCoding::deleteTree(HuffmanNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
