#include <stdio.h>
struct test
{
  int x;
  int y;
};

int main()
{
  test p[5];

  for (int i = 0; i < 5; i++)
  {
    p[i].x = i;
    p[i].y = i;
  }

  for (int i = 0; i < 5; i++)
  {
    printf("(%d, %d)\n", p[i].x, p[i].y);
  }

  return 0;
}