  public int numTrees(int n) {
      int[] values = new int[n + 1];
      values[0] = 1;
      values[1] = 1;
      
      for(int i = 1; i <= n; ++i){
          int sum = 0;
          for(int j = 0; j < i; ++j){
              sum += values[j] * values[i - j - 1];
          }
          values[i] = sum;
      }
      return values[n];
  }
