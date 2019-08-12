class Solution {
vector<int> Months2Days {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public:
    int dayOfYear(string date) {
        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + date[3]-'0';
        int month = (date[5]-'0')*10 + (date[6]-'0');
        int day = (date[8]-'0')*10 + date[9]-'0';
        while(--month)
        {
            day += DaysInMonth(month, year);
        }
            
        return day;
    }
    
    int DaysInMonth(int x, int year)
    {
        if(x != 2) return Months2Days[x];
        
        int f = year % 4;
        int h = year % 100;
        int fh = year % 400;
        
        int leap = (!f && h) || !fh;
        return Months2Days[x] + leap;
    }
};
