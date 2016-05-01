class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;// position in version1
        int j = 0;// position in version2
        
        while ( i <= version1.size() || j <= version2.size() ){
            int ver1 = 0;
            while( i < version1.size() && version1[i] != '.')
                ver1 = ver1*10 + (version1[i++]-'0');
                
            int ver2 = 0;
            while( j < version2.size() && version2[j] != '.')
                ver2 = ver2*10 + (version2[j++]-'0');
                
            if(ver1 < ver2)
                return -1;
            else if(ver1 > ver2)
                return 1;
            
            ver1 =  ver2 = 0;
            ++i, ++j;
        }
        
        
        return 0;
    }
};
