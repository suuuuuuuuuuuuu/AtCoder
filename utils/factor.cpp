#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long>> factorization(long long N){
  vector<pair<long long, long long>> fac;
  long long num = N; 
  for (long long i = 2 ; i * i <= N; i++){
    long long c = 0;
    while(num%i == 0){
      c++;
      num /= i;
    }
    if (c != 0) fac.push_back( pair( i, c ) );
  }
  if (num != 1) fac.push_back( pair( num, 1 ) );
  return fac;
}

#include <cmath>
long long N;
const long long N_MAX = 1000000000000;
vector<pair<long long, long long>>fac;

int main(){
  cin >> N;
  if (N == 1) {
    cout << 0;
    return 0;
  }
  fac = factorization(N);
  float f;
  int ans = 0;
  for ( auto& i: fac ){
    f = (-1 + sqrt(1+8*i.second)) / 2;
    ans += floor(f);
  }
  if (fac.size() == 0) cout << 1;
  else cout << ans;
}