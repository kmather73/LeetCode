struct Transaction
{
    Transaction(string &str)
    {
        _data = str;
        stringstream ss(str);
        getline(ss, name, ',');
        string strTime;
        getline(ss, strTime, ',');
        time = stoi(strTime);
        string strAmount;
        getline(ss, strAmount, ',');
        amount = stoi(strAmount);
        getline(ss, city, ',');
    }
    
    string _data;
    string name;
    int time;
    int amount;
    string city;
};

using City = string;
using Name = string;
using Time = string;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        unordered_map<Name, vector<Transaction>> allTrans;
        
        for(auto &t : transactions)
        {
            auto trans = Transaction(t);
            allTrans[trans.name].push_back(trans);
        }
        
        vector<string> invalid;
        for(auto& personPair : allTrans)
        {
            auto& TransVect = personPair.second;
            for(int i = 0; i < TransVect.size(); ++i)
            {
                for(int j = 0; j < TransVect.size(); ++j)
                {
                    if ((TransVect[i].city != TransVect[j].city &&
                        abs(TransVect[j].time - TransVect[i].time) <= 60) || TransVect[i].amount > 1000
                    )
                    {
                        invalid.push_back(TransVect[i]._data);
                        break;
                    }
                }
            }
        }
        
        return invalid;
    }
};
