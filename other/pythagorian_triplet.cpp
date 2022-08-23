#include <iostream>
#include <math.h>

using namespace std;

int max_(int a, int b, int c){
  if (a > b && a > c){
    return a;
  }
  if (b > a && b > c){
    return b;
  }
  else{
    return c;
  }
}

bool check(int x, int y, int z)
{
  int a = max_(x, y, z);
  int b, c;
  if (a == x)
  {
    b = y;
    c = z;
  }
  else if (a == y)
  {
    b = x;
    c = z;
  }
  else
  {
    b = x;
    c = y;
  }
  if (a * a == b * b + c * c)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main(void)
{
  int x, y, z;
  cin >> x >> y >> z;
  if (check(x, y, z)){
    cout << "Pythogorus" << endl;
  }
  else{
    cout << "No";
  }
  return 0;
}
// 12- out ->2->1