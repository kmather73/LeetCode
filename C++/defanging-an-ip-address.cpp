class Solution {
public:
    string defangIPaddr(string address) {
        string defanged = "";
        for(auto ch : address)
        {
            if(ch == '.') defanged += "[.]";
            else defanged.push_back(ch);
        }
        
        return defanged;
    }
};
