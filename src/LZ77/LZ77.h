#ifndef LZ77_H
#define LZ77_H

#include <vector>
#include <string>

class LZ77 {
public:
    struct EncodedData {
        int offset;
        int length;
        char nextChar;
    };

    LZ77(int windowSize, int lookAheadBufferSize);

    std::vector<EncodedData> compress(const std::string& data);
    std::string decompress(const std::vector<EncodedData>& compressedData);

private:
    int windowSize;
    int lookAheadBufferSize;
};

#endif // LZ77_H
