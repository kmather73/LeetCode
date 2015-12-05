public class Solution {
    public String largestNumber(int[] num) {
        if(num == null){
            return "";
        }
        Integer[] arr = new Integer[num.length];
        for(int i = 0;i<num.length ; i++){
            arr[i] = num[i];
        }
        Arrays.sort(arr, new IntegerComparator());
        String str = Arrays.toString(arr).replaceAll("[, ]","");
        return str.substring(1,str.length()-1).replaceFirst("^0+(?!$)", "");
    }
    
    public class IntegerComparator implements Comparator<Integer>{
            public int compare(Integer n, Integer m){
                if(n == 0)
                    return 1;
                else if(m == 0)
                    return -1;
                else{
                    int nPowOf10 = (int)Math.log10(n);
                    int mPowOf10 = (int)Math.log10(m);
                    
                    double t1 = m*Math.pow(10,nPowOf10+1) + n;
                    double t2 = n*Math.pow(10,mPowOf10+1) + m;

                    return t1 < t2? -1:1;
                }
            }
    }
}
