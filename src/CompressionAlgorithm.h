#ifndef COMPRESSIONALGORITHM_H
#define COMPRESSIONALGORITHM_H

#include <cstdint> 
#include <string>
#include <vector>

class CompressionAlgorithm {
public:
  
    virtual ~CompressionAlgorithm() {}

    virtual std::vector<uint8_t> compress(const std::string& input) = 0;
    virtual std::string decompress(const std::vector<uint8_t>& compressedData) = 0;
};

#endif 
