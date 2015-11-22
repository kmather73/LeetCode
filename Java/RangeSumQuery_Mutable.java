public class NumArray {
    ArrayList<ArrayList<Integer>> levelSums;
    
    public NumArray(int[] nums)  {
        levelSums = new ArrayList<ArrayList<Integer>>();
        int logSize = 0;
        for (int i = nums.length; i > 0; i /= 2)
            ++logSize;

        ArrayList<Integer> currLevel = new ArrayList<Integer>();
        int limit = 1<<logSize;
        for (int i = 0; i < limit; ++i) {
            if (i < nums.length)
                currLevel.add(nums[i]);
            else
                currLevel.add(0);
        }
        levelSums.add(new ArrayList<Integer>(currLevel));


        for (int i = logSize; i >= 1; --i) {
            currLevel = new ArrayList<Integer>();
            int prevLevel = levelSums.size() - 1;
            limit = 1<<(i-1);
            for (int j = 0; j < limit; ++j) {
                currLevel.add(levelSums.get(prevLevel).get(2 * j) + levelSums.get(prevLevel).get(2 * j + 1));
            }
            levelSums.add(currLevel);
        }
    }

    void update(int i, int val) {
        int diff = val - levelSums.get(0).get(i);

        for (int j = 0; j < levelSums.size(); ++j) {
            levelSums.get(j).set(i, levelSums.get(j).get(i) + diff);
            i = i>>1;
        }
    }

    public int sumRange(int i, int j) {
        return leftSum(j) - leftSum(i - 1);
    }

    public int leftSum(int num) {
        int sum = 0;
        if (num >= 0) {
            int offset = 0;
            int size = levelSums.size() - 1;
            ++num;
            do {
                while((num&1) == 0 && num > 1) {
                    num >>= 1;
                    ++offset;
                }

                sum += levelSums.get(offset).get(num-1);
                num >>= 1;
                ++offset;
            }while(num > 0);
        }
        return sum;
    }
}
