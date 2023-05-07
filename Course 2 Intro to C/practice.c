#include <stdio.h>

int oneTon(int p,int n)
{
    int a;
    if(p>n)//3
    {
        return 0;
    }
    else if(p<=n)//3
    {
        scanf("%d",&a);
        a=a%10;
    }
    int s = oneTon(p+1,n);
    return s+a;//8
}
int main()
{
  int n,m;
  scanf("%d",&n);
  printf("%d",oneTon(1,n));
  return 0;
}
