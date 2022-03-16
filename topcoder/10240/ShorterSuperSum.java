public class ShorterSuperSum { 
  public int calculate(int k, int n){ 
    int sum=0; 
    if(k==0) return n; 
    else 
      for (int i = 1; i <= n; i++) 
        sum+=calculate(k-1,i); 
    return sum; 
  } 
}