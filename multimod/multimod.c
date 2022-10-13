#include <stdint.h>
#include<stdio.h>
// static int selfincre(int x)
// {
//   int p=1;
//   int t=1;
//   int x1=x>>1;
//   int x2=x;
//   while(t)
//   {
//     if(x^(x1<<1))
//     {
//       x=x1;
//       x1=x1>>1;
//       p=p<<1;
//       p^=1;

//     }
//     else
//     t=0;


//   }
//   return x2^p;


// }
// static inline int bit_of(int x, int i) {
//   return (x >> i) & 1;
// }
// static inline int full_add(int x, int y, unsigned long z) {
//   return x ^ y ^ z;
// }

// static inline int carry(int x, int y, unsigned long z) {
//   return (x & y) | (x & z) | (y & z);
// }
// static inline int mynum_of_digit(unsigned long x)
// {
//   int num=0;
//   x=x>>1;
//   while(x)
//   {x=x>>1;
//     num=selfincre(num);
//   }
//   return num;

// }
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
/*似乎可以使用串位并行加法器来实现add*/
// static inline unsigned long max(unsigned long x,unsigned long y)
// {
//   return x>y?x:y;
// }

// static inline int cmpint(int x,int y)
// {
//   int max=-1;
//   int x3=x;
//   int y3=y;
//   int x1=x;
//   int y1=y;
//   int x2=0;
//   int y2=0;
//   while(x||y)
//   {
//     x=x>>1;
//     y=y>>1;
//     x2=x1^(x<<1);
//     y2=y1^(y<<1);
//     if(x2==1&&y2==0)
//     max=x3;
//     else if(x2==0&&y2==1)
//     max=y3;
//     x1=x;
//     y1=y;


//   }
//   if(max==x3)
//   return 1;
//   else
//   return 0;

// }
// static inline unsigned long add(unsigned long x,unsigned long y)
// {
//   unsigned long temp[131];
//   unsigned long x1=x;
//   unsigned long y1=y;
//   int i=0;
//   unsigned long ans=0;
//   unsigned long carry0=0;
//   int j=0;
//   while(x && y)
//   {
//     if(x==1)
//     {
//       temp[i<<1]=x;
//       x=x>>1;
//     }
//     else
//     {
//       x=x>>1;
//       temp[i<<1]=x1^(x<<1);
//     }
//     if(y==1)
//     {
//       temp[(i<<1)^1]=1;
//       y=y>>1;
//     }
//     else
//     {
//     y=y>>1;
//     temp[(i<<1)^1]=y1^(y<<1);
//     }
//     i=selfincre(i);
//     x1=x;
//     y1=y;
//   }
//   while(x)
//   {
//     x=x>>1;
//     temp[i<<1]=x1^(x<<1);
//     temp[(i<<1)^1]=0;
//     i=selfincre(i);
//     x1=x;
//   }
//    while(y)
//   {
//     y=y>>1;
//     temp[i<<1]=0;
//     temp[(i<<1)^1]=y1^(y<<1);
//     i=selfincre(i);
//     y1=y;
//   }
//   while(cmpint(i,j))
//   {
   
//     unsigned long ans1=full_add(temp[j<<1],temp[(j<<1)^1],carry0);
//     carry0=carry(temp[j<<1],temp[(j<<1)^1],carry0);
//     // printf("%lu ,%lu\n",ans,ans1<<j);
//     ans|=(ans1<<j);

//     j=selfincre(j);


//   }
//   if(i==64)
//   return ans;
//   ans|=carry0<<i;
//   return ans;

// }
// uint64_t sub(uint64_t a,uint64_t b)
// {
//   uint64_t c=add(b^0xffffffffffffffff,1);
//   return add(a,c);

// }
// int cmp(uint64_t x,uint64_t y)
// {
//  int max=-1;
//   uint64_t x3=x;
//   uint64_t y3=y;
//   uint64_t x1=x;
//   uint64_t y1=y;
//   int x2=0;
//   int y2=0;
//   while(x||y)
//   {
//     x=x>>1;
//     y=y>>1;
//     x2=x1^(x<<1);
//     y2=y1^(y<<1);
//     if(x2==1&&y2==0)
//     max=x3;
//     else if(x2==0&&y2==1)
//     max=y3;
//     x1=x;
//     y1=y;


//   }
//   if(max==x3)
//   return 1;
//   else
//   return 0;
// }
// uint64_t mymod(uint64_t a,uint64_t b)
// {
//   if(cmp(b,a))
//   return a;
//   else
//   {
//     int adigit=num_of_digit(a);
//     int bdigit=num_of_digit(b);
//     if(adigit==bdigit)
//     return sub(a,b);
//     else
//     return mymod(sub(a,b<<(sub(adigit,add(bdigit,1)))),b);
//   }
// }
uint64_t mod(uint64_t a,uint64_t b)
{while(1)
  {if(b>a)
  return a;
  else
  {
    int adigit=num_of_digit(a);
    int bdigit=num_of_digit(b);
    if(adigit==bdigit)
    return a-b;
    else
    // return mod(sub(a,b<<(sub(adigit,add(bdigit,1)))),b);
    a-=(b<<(adigit-bdigit-1));
  }
}
}
// uint64_t mymultimod(uint64_t a, uint64_t b, uint64_t m) {
// int i=0;
// uint64_t a1=a>>1;
// uint64_t sum=0;
// while(a)
// {
// if(a^(a1<<1))
// sum=add(sum,b<<i);
// a=a1;
// a1=a1>>1;
// i=selfincre(i);

// }
  // return mod(sum,m); 

// }
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
int main()
{ uint64_t num1=0,num2=0,num3=0,result=0;
int i=0;
int t=0;
uint64_t myans=0;
  FILE *file=fopen("input.txt","r");
  if(!file)
  return 0;
  while(i<10000)
  {i++;
    fscanf(file,"%lu",&num1);
    fscanf(file,"%lu",&num2);
    fscanf(file,"%lu",&num3);
    fscanf(file,"%lu",&result);
    myans=multimod(num1,num2,num3);
    if(myans!=result)
    {printf("(%lu*%lu) mod %lu =%lu !=%lu in line %d",num1,num2,num3,myans,result,i);
    t=1;
    break;
    }
  }
  fclose(file);
  if(!t)
  printf("all right");
  // printf("%lu",multimod(18446744073709551615,198,100));
  return 0;
}
