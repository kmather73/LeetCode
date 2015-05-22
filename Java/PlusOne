public class Solution {
    public int[] plusOne(int[] digits) {
       
       int carry = 1;//The initial one to be added to the array.
       for(int i = digits.length - 1; i >= 0; --i){
           int temp = digits[i] + carry;//Add one.
           carry = temp / 10;//Do we need to carry the one? 
           digits[i] = temp % 10;//set new digit.
       }
       
       if(carry == 1){// this is in the event that we have to carray a one at the head of the array so we need an array of one size bigger
           int[] newArray = new int[digits.length + 1];
           newArray[0] = 1;//Set leading digit to one.
           for(int i = 0; i < digits.length; i++){
               newArray[i+1] = digits[i];
           }
           return newArray;
       }
       return digits;
    }
}
