//Clearner solution at the end, faster one at the top.
public class Solution {
    public String addBinary(String a, String b) {
        
        int indexA = a.length();
        int indexB = b.length();
        
        int maxSize = Math.max(indexA, indexB);//Find the longer of the two strings
        int minSize = Math.min(indexA, indexB);//Find the shorter of the two strings.
        
        int carry = 0;
        char[] add = new char[maxSize];//create an array to hold the sum.
        
        for( ; minSize> 0; --minSize){//start adding the digits from LSD to MSD or until one of them run out of digits.
            int temp =  carry + (a.charAt(--indexA) - '0') + ( b.charAt(--indexB) - '0');// Add the current digits
            carry =  temp / 2;// Need to carry the one?
            add[--maxSize ] = (char)(temp%2 +'0');// Input the current digit.
        }
        
        while(indexA > 0){//Add what is left of the number a if needed.
            int temp = carry + (a.charAt(--indexA) - '0');
            carry = temp / 2;
            add[--maxSize] = (char)  (temp % 2+'0');
        }
        while(indexB > 0){//Add what is left of the number b if needed
            int temp = carry + ( b.charAt(--indexB) - '0');
            carry = temp / 2;
            add[--maxSize] = (char) (temp % 2 +'0');
        }
        String added = new String(add);
        if(carry == 1){//don't forget about the last carry.
            added = "1" + added;
        }
        return added;
    }
}

//Clean version
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int indexA = a.length(), indexB = b.length(), carry = 0;
        while (indexA > 0 || indexB > 0) {
            int sum = carry;
            if (indexB > 0){
                sum += b.charAt(--indexB) - '0';
            }
            if (indexA > 0){
                sum += a.charAt(--indexA) - '0';
            }
            sb.append(sum % 2);
            carry = sum / 2;
        }
        if (carry == 1) sb.append(carry);
        return sb.reverse().toString();
    }
