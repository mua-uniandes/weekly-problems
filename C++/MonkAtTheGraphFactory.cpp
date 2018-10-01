#include <iostream>
using namespace std; 
int main() {
  int numberNodes = 0;
  cin >> numberNodes;
  int counter = 0;
  //Read the degree of each node and add it up to the total
  int totalDegree = 0;
  while (counter < numberNodes){
    int number = 0;
    cin >> number;
    totalDegree += number;
    counter++;
  }
  if(totalDegree/2 == numberNodes-1){
    cout << "Yes";
  }
  else{
    cout << "No";
  }

}