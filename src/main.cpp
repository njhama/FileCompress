#include "CompressionAlgorithm.h"
#include "LZ77/LZ77.h"  
#include <iostream>
#include <memory>

int main() {
    std::string originalText = "This is an example of compression using LZ77.";


    std::unique_ptr<CompressionAlgorithm> lz77(new LZ77(400, 15)); 

    
    auto lz77Compressed = lz77->compress(originalText);
    auto lz77Decompressed = lz77->decompress(lz77Compressed);


    std::cout << "Original: " << originalText << "\n";
    std::cout << "Decompressed: " << lz77Decompressed << "\n";

    return 0;
}
