int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if(A > E)  {
        return computeArea(E, F, G, H, A, B, C, D);
    }
      
    int area = (C - A) * (D - B)  + (G - E) * (H - F);
    
    int left =  A ^ ((E ^ A) & -(A < E));
    int right = C ^ ((G ^ C) & -(G < C));
    int width = left < right ? right -left : 0;
      
    int top = D ^ ((H ^ D) & -(H < D));
    int bottom = B ^ ((F ^ B) & -(B < F));
    int height = top > bottom ? top - bottom : 0;
      
    area -= height * width;
      
    return area;
}



//Without Bit Tricks.
#include <math.h>
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if(A > E)  {
        return computeArea(E, F, G, H, A, B, C, D);
    }
      
    int area = (C - A) * (D - B)  + (G - E) * (H - F);
      
      
    int left = fmax(A,E);
    int right = fmin(C, G);
    int width = left < right ? right -left : 0;
      
    int top = fmin(D,H); 
    int bottom = fmax(B, F);
    int height = top > bottom ? top - bottom : 0;
      
    area -= height * width;
      
    return area;
}
