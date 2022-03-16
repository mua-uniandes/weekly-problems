#include <vector>
 
using namespace std;
 
class BinarySearchable
  {
  public:
  int howMany(vector <int> sequence) {
      int count = 0;
      int N = sequence.size();
      for (int i=0; i<N; ++i) {
        bool find = true;
        for (int j=0; j<N; ++j)
          if ((sequence[j] > sequence[i] && j < i) || (sequence[j] < sequence[i] && j > i)) {
            find = false;
            break;
          }
 
        if (find)
          count++;
      }
      return count;
    }    
};