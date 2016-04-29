#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if(numerator == 0)
            return "0";
            
        std::string s;
        if(numerator < 0  ^  denominator < 0) s = "-";
        if(numerator < 0)   numerator = -numerator;
        if(denominator < 0) denominator = -denominator;
        
        s += std::to_string(numerator/denominator);
        
        if( numerator % denominator == 0)
            return s;
        
        
        s  += ".";
        //numerator -> location in string after "."
        std::unordered_map<int, int> map;
        
        numerator %= denominator;
        while ( numerator > 0) {
            
            if ( map.find( numerator ) != map.end() ){
                s.insert( map[ numerator ], 1, '(');
                s += ')';
                break;
            }

            map[ numerator ] = s.size();
            numerator *= 10;
            s += std::to_string(numerator/denominator);
            numerator = numerator % denominator;
        }
        
        return s;
    }
};
