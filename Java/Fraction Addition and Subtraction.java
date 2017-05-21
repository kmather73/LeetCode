public class Solution {
    public int t;
    public int b;
    
    public String fractionAddition(String expression) {
        if(expression == null || expression.length() == 0) return "0/1";
        if(expression.charAt(0) == '-') expression = "0/1" + expression;
        String[] terms = expression.split("/");
        
        t = 0;
        b = 1;
        ArrayList<String> myList = new ArrayList<>();
        myList.add(terms[0]);
        
        for(int i=1; i<terms.length-1; ++i){
            if(terms[i].contains("-")) {
                String ss[] = terms[i].split("-");
                myList.add(ss[0]);
                myList.add("-" + ss[1]);
            } else if(terms[i].contains("+")) {
                String ss[] = terms[i].split("\\+");
                myList.add(ss[0]);
                myList.add(ss[1]);
            }
        }
        myList.add(terms[terms.length-1]);
        
        for(int i=0; i<myList.size(); i += 2){
            String s1 = myList.get(i);
            String s2 = myList.get(i+1);
            add(Integer.parseInt(s1), Integer.parseInt(s2));
        }
        
        return "" + t + "/" +  b;
    }
    
    public void add(int tt, int bb){
        t = t*bb + b*tt;
        b = b*bb;
        int gcd = GCD(t, b);
            
        t = t / gcd;
        b = b / gcd;
    }
        
    public int GCD(int a, int b) {
        if(a < 0) return GCD(b, -a);
        if (b==0) return a;
        return GCD(b,a%b);
    }
}
