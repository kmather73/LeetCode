class Solution {
private:
    vector<string> map{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"} ;
    int mask = 0xF;
    
public:
    string toHex(int num) {
        if(num == 0) return "0";
        
        uint unum = static_cast<uint>(num);
        string hex = "";
        while(unum){
            hex = map[unum&mask] + hex;
            unum = unum >> 4;
        }
        return hex;
    }
};
