#ifndef LZ78_H
#define LZ78_H

#include <string>
#include <vector>
#include <unordered_map>

class LZ78 {
public:
    struct EncodedData {
        int dictIndex;
        char nextChar;
    };

    std::vector<EncodedData> compress(const std::string& data);
    std::string decompress(const std::vector<EncodedData>& compressedData);
};

#endif 
