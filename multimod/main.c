#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
static inline int num_of_digit(unsigned long x)
{
  int num=0;
  x=x>>1;
  while(x)
  {x=x>>1;
    num++;
  }
  return num;

}
uint64_t mod(uint64_t a,uint64_t b)
{
  if(b>a)
  return a;
  else
  {
    int adigit=num_of_digit(a);
    int bdigit=num_of_digit(b);
    if(adigit==bdigit)
    return a-b;
    else
    // return mod(sub(a,b<<(sub(adigit,add(bdigit,1)))),b);
    return mod(a-(b<<(adigit-bdigit-1)),b);
  }
}
uint64_t multimod(uint64_t a, uint64_t b, uint64_t m) {
int i=0;
uint64_t a1=a>>1;
uint64_t sum=0;
while(a)
{
if(a^(a1<<1))
sum+=(b<<i);
a=a1;
a1=a1>>1;
i++;

}
  return mod(sum,m); 
}

void test(uint64_t a, uint64_t b, uint64_t m) {
  #define U64 "%" PRIu64
  printf(U64 " * " U64 " mod " U64 " = " U64 "\n", a, b, m, multimod(a, b, m));
}

int main() {
  test(123, 456, 789);
  test(123, 456, -1ULL);
  test(-2ULL, -2ULL, -1ULL); // should be 1
}
