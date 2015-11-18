public class Solution {
    public boolean isAdditiveNumber(String num) {
        for(int i = 1; i <= num.length() - 2; ++i){
            for(int j = i + 1; j <= num.length() - 1; ++j){
                if(driverUtill(num, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    
    private boolean driverUtill(String num, int start, int mid, int end){
        if( (num.charAt(mid) == '0' &&  end > mid + 1) )
            return false;
        else if(end == num.length())
            return true;
            
        long nextNum = Long.parseLong(num.substring(start, mid)) + Long.parseLong(num.substring(mid, end));
        
        for(int i = end + 1; i <= num.length(); ++i){
            long temp = Long.parseLong(num.substring(end,i));
            if(temp > nextNum)
                return false;
            else if(nextNum == temp && driverUtill(num, mid, end, i) )
                return true;
        }
        return false;
    }
}
