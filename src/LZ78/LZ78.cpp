#include "LZ78.h"

std::vector<LZ78::EncodedData> LZ78::compress(const std::string& data) {
    std::unordered_map<std::string, int> dict;
    std::vector<EncodedData> compressedData;
    std::string currentStr;
    int dictIdx = 1;

    for (char ch : data) {
        currentStr += ch;
        if (dict.find(currentStr) == dict.end()) {
            compressedData.push_back({dict[currentStr], ch});
            dict[currentStr] = dictIdx++;
            currentStr.clear();
        }
    }

    if (!currentStr.empty()) {
        compressedData.push_back({dict[currentStr], '\0'});
    }

    return compressedData;
}

std::string LZ78::decompress(const std::vector<EncodedData>& compressedData) {
    std::string decompressedData;
    std::vector<std::string> dict(1);  

    for (const auto& data : compressedData) {
        std::string toAdd = dict[data.dictIndex] + data.nextChar;
        decompressedData += toAdd;
        dict.push_back(toAdd);
    }

    return decompressedData;
}
