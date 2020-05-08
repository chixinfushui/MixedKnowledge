// inplace_merge example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/************************************************************************/
/*
		inplace_merge:  合并同一个序列中两个连续有序的元素序列
*/
/************************************************************************/
int main19 () {
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  vector<int> v(10);
  vector<int>::iterator it;

  sort (first,first+5);
  sort (second,second+5);

  copy (first,first+5,v.begin());
  copy (second,second+5,v.begin()+5);

  inplace_merge (v.begin(),v.begin()+5,v.end());

  cout << "The resulting vector contains:";
  for (it=v.begin(); it!=v.end(); ++it)
    cout << " " << *it;

  cout << endl;
  
  return 0;
}
