#include <iostream>
#include <math.h>
using namespace std;
void factorize(long long n){
   int count = 0;
   while (!(n % 2)) {
      n/= 2;
      count++;
   }
   if (count)
      cout<<2<<"\t"<<count<<endl;
   for (long long i = 3; i <= sqrt(n); i += 2) {
      count = 0;
      while (n % i == 0) {
         count++;
         n = n / i;
      }
      if (count)
      cout<<i<<"\t"<<count<<endl;
   }
   if (n > 2)
   cout<<n<<"\t"<<1<<endl;
}
int main() {
   long long N = 21000;
   cout<<"The prime factors and their frequencies of the number "<<N<<" are \n";
   factorize(N);
   return 0;
}