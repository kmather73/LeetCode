class MyCalendar {
    map<int,int> calStarts;
    map<int,int> negStarts;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto itS = calStarts.lower_bound(start);
        auto itE = negStarts.lower_bound(-start);
        
        bool DoesNotOverlapWithPreviousEvent = itE == negStarts.end() || itE->second <= start;
        bool DoesNotOverlapWithNextEvent = itS == calStarts.end() || itS->first >= end;
        
        auto canAdd = DoesNotOverlapWithPreviousEvent && DoesNotOverlapWithNextEvent;
        
        if (canAdd)
        {
            calStarts[start] = end;
            negStarts[-start] = end;
        }
        
        return canAdd;
    }
};
