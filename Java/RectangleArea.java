public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      if(A > E)  {
          return computeArea(E, F, G, H, A, B, C, D);
      }
      
      int area = (C - A) * (D - B)  + (G - E) * (H - F);
      
      
      int left = Math.max(A,E);
      int right = Math.min(C, G);
      int width = left < right ? right -left : 0;
      
      int top = Math.min(D,H); 
      int bottom = Math.max(B, F);
      int height = top > bottom ? top - bottom : 0;
      
      area -= height * width;
      
      return area;
    }
}
