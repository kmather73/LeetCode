class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ax, ay, bx, by;
        
        Str2Num(a, ax, ay);
        Str2Num(b, bx, by);
        
        int re = ax * bx - ay * by;
        int im = ax * by + ay * bx;
        
        return to_string(re) + "+" + to_string(im) + "i";
    }
    
    void Str2Num(string &a, int &x, int &y)
    {
        x = 0;
        int i=0, n = a.size();
        auto reNeg = a[0] == '-';
        if(reNeg) ++i;
        
        while(a[i] != '+')
        {
            x = x * 10 + a[i] - '0';
            ++i;
        }
        if(reNeg) x = -x;
        
        ++i;
        auto imNeg = a[i] == '-';
        if(imNeg) ++i;
        
        y = 0;
        while(a[i] != 'i')
        {
            y = y * 10 + a[i] - '0';
            ++i;
        }
        
        if(imNeg) y = -y;
    }
};
