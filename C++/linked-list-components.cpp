class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, ListNode*> nodes;
        
        while(head)
        {
            nodes[head->val] = head;
            head = head->next;
        }
        
        unordered_map<int,int> UF;
        
        for(auto g : G) UF[g] = g;
        
        for(auto g : G)
        {
            auto next = nodes[g]->next;
            if(next && UF.count(next->val))
            {
                Union(UF, g, next->val);
            }
        }
        
        unordered_set<int> cc;
        
        for(auto g : G)
        {
            cout << Find(UF, g) << endl;
            cc.insert(Find(UF, g));
        }
        
        return cc.size();
    }
    
    void Union(unordered_map<int,int> &UF, int i, int j)
    {
        auto findi = Find(UF, i);
        auto findj = Find(UF, j);
        
        UF[i] = findj;
    }
    
    int Find(unordered_map<int,int> &UF, int i)
    {
        while(UF[i] != i)
        {
            UF[i] = UF[UF[i]];
            i = UF[i];
        }
        
        return i;
    }
};
