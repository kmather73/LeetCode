public class Solution {
    public List<String> generateParenthesis(int n) {
       Set<String> listOfPerens = new TreeSet<String>();
       if(n == 1){
           listOfPerens.add("()");
           return new ArrayList(listOfPerens);
       }
       
       List<String> previousPerens = generateParenthesis(n-1);
       for(String peren : previousPerens){
            listOfPerens.add("(" + peren +")");
            listOfPerens.add("()" + peren);
            listOfPerens.add(peren + "()");
       }
       
       int nBy2 = n/2;
       for(int i = 2; i <= nBy2; ++i){
            previousPerens = generateParenthesis(n-i);
            List<String> previousPerens2 = generateParenthesis(i);
            for(String peren : previousPerens){
                for(String otherPeren: previousPerens2){
                    listOfPerens.add(otherPeren + peren);
                    listOfPerens.add(peren + otherPeren);
                }
            }
       }
       return new ArrayList(listOfPerens);
    }
}
