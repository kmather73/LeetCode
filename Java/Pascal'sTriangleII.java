public class Solution {
    public List<Integer> getRow(int rowIndex) {
        ArrayList<Integer> row = new ArrayList<Integer>();
        
        row.add(1);
        if(rowIndex == 0){//Edge case one. The top row.
            return row;
        }
        else if(rowIndex == 1){//Edge case two. The second row.
            row.add(1);
            return row;
        }
        
        int[] binomCoeff = new int[rowIndex/2+1];
        binomCoeff[0] = 1;//Leftmost element is always a one.
        
        for(int i = 1; i < rowIndex/2 + 1; i++){//Calculate the next binomail coefficent in terms of the previous coefficent.
            int temp = binomCoeff[i-1];//Get the last coefficent
            if(i < 10){//To avoid overflow/underflow the order of operations matter.
                binomCoeff[i] = temp*(rowIndex - i + 1 )/i;//The new coefficent.
            }
            else{//To avoid overflow/underflow the order of operations matter.
                binomCoeff[i] = (int)((rowIndex -i+1)*((double)temp/i));
            }
            row.add(binomCoeff[i]);//Add the current coefficent ot the list.
        }
        
        int index = rowIndex / 2;// The index half way into the list.
        if(rowIndex % 2 == 0){//The row has an odd number of element, so the middle element is unique.
            index--;
        }
        for(int i= index ; i>=0; i--){//Mirror the list, since the binomial coefficents have some symmetry.
            row.add(binomCoeff[i]);//Add the element to the list.
        }
        return row;
    }
}
