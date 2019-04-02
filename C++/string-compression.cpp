class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0, write = 0;
        int n = chars.size();
        while(start < n)
        {
            auto end = start + 1;
            while(end < n && chars[start] == chars[end]) ++end;
            
            chars[write++] = chars[start];
            auto len = end - start;
            if(len > 1)
            {
                auto k = write;
                while(len)
                {
                    chars[k] = '0' + (len % 10);
                    len /= 10;
                    ++k;
                }

                auto i = write;
                write = k--;

                while(i < k)
                {
                    swap(chars[i++], chars[k--]);
                }
            }
            
            start = end;
        }
                
        return write;
    }
};
