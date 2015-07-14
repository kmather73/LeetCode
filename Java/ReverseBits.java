public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        if(n == 0)
            return 0;
        int upperBits = 0xFFFF0000 & n;
        int lowerBits = 0x0000FFFF & n;
        
        return reverse16Bits(upperBits>>>16) + (reverse16Bits(lowerBits)<<16);
    }
    
    public int reverse16Bits(int n){
        int upperBits = n & 0xFF00;
        int lowerBits = n & 0x00FF;
        
        return reverse8Bits(upperBits>>8) + (reverse8Bits(lowerBits)<<8);
    }
    
    public int reverse8Bits(int n){
       int upperBits = n & 0xF0;
       int lowerBits = n & 0x0F;
       
       return reverse4Bits(upperBits>>4) + (reverse4Bits(lowerBits)<<4);
    }
    
    public int reverse4Bits(int n){
        int upperBits = n & 0xC;
        int lowerBits = n & 0x3;
        
        return reverse2Bits(upperBits>>2) + (reverse2Bits(lowerBits)<<2);
    }
    public int reverse2Bits(int n){
        return ((n&2)>>1) + ((n&1)<<1);
    }

}
