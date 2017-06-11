class Solution {
public:
    string addBoldTag(string s, vector<string> &dict) {
        if(dict.size() ==0) return s;
        vector<pair<int, int>> vct;
        int n = s.size();
        for(const auto str: dict) {
            size_t i = 0;
            while(1){
                i = s.find(str, i);
                
                if(i != string::npos){
                    vct.push_back(make_pair(i, i+str.size()));
                    ++i;
                    
                } else {
                    break;
                }
            }
        }
        
        
        sort(vct.begin(), vct.end(), [](pair<int,int> &a, pair<int,int> &b){return a.first < b.first;});
        vector<pair<int, int>> merged;
        for(int i=0; i < vct.size(); ){
            int start = vct[i].first;
            int end = vct[i].second;
            ++i;
            
            while(i < vct.size() ){
                if(vct[i].first > end) break;
                end = max(end, vct[i].second);
                ++i;
            }
            
            cout << start << " " << end << endl;
            merged.push_back(make_pair(start, end));
            
        }
        
        
        merged.push_back(make_pair(n+1, n+1));
        string str = "";
        
        int j=0;
        for(int i=0; i < s.size(); ++i){
            
            if(i == merged[j].first){
                str += "<b>";
                
            } else if(i == merged[j].second){
                str += "</b>";
                ++j;
            }
            str += s[i];
        }
        if( merged[j].second == n) str +="</b>";
        return str;
    }
};
