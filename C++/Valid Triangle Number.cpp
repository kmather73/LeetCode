class Solution {
public:
    bool validTri(int a, int b, int c){
        return a+b > c && b+c > a && c+a > b;
    }
    
    int triangleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int x : nums){
            ++mp[x];
        }
        
        int count = 0;
        
        
        for(std::map<int,int>::iterator it1=mp.begin(); it1!=mp.end(); ++it1){
            int x = it1->second;
            int a = it1->first;
            for(std::map<int,int>::iterator it2=it1; it2!=mp.end(); ++it2){
                int y = it2->second;
                int b = it2->first;
                
                for(std::map<int,int>::iterator it3=it2; it3!=mp.end(); ++it3){
                    int z = it3->second;
                    int c = it3->first;
                    if(c > a + b) break;
                    
                    if(validTri(a,b,c)){
                        int d = 0;
                        if(a == b && b == c){
                            d += x*(x-1)*(x-2)/6;
                        } else if(a == b){
                            d += x * (x-1) * z/2;
                        } else if(b == c){
                            d += x*y*(y-1) / 2;
                        } else {
                            d += x*y*z;
                        }
                        
                        count += d;
                    }   
                }
            }
        }
        
        
        return count;
    }
};
