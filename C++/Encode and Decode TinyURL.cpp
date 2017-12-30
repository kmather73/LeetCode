class Solution {
public:
    unordered_map<string, string> endcodeMap;
    unordered_map<string, string> decodeMap;
    int count=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto newString = to_string(count);
        ++count;
        endcodeMap[longUrl] = newString;
        decodeMap[newString] = longUrl;
        return newString;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
