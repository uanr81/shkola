/* zippo1.c -- информация о массиве zippo  */
#include <stdio.h>
int main(void)
{
  int zippo[4][2][3] = {{} ,{}, {{},{{1,3},{2,4}},} };
  printf("   zippo = %p,    zippo + 1 = %p\n",
	 zippo,         zippo + 1);
  printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
	 zippo[0],      zippo[0] + 1);
  printf("zippo[0][0] = %p, zippo[0][0] + 1 = %p\n",
	 zippo[0][0],      zippo[0][0] + 1);
  printf("  *zippo = %p,   *zippo + 1 = %p\n",
	 *zippo,        *zippo + 1);
  printf("zippo[0][0][0] = %d\n",  zippo[0][0][0]);
  printf("  **zippo[0] = %d\n", **zippo[0]);
  printf("    ***zippo = %d\n", ***zippo);
  printf("      zippo[2][1][1] = %d\n", zippo[2][1][1]);
  printf("*(*(*(zippo+2) + 1) +)1 = %d\n", *(*(*(zippo+2) + 1) + 1));
    
	 return 0;
	 }
