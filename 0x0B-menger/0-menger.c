#include "menger.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
/**
 * menger - function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Return: the sponge menger
 */
void menger(int level)
{
int i, j, size;
if (level == 0)
{
printf("#\n");
}
if (level > 0)
{
size = pow(3, level);
for (i = 1; i <= size; i++)
{
j = 1;
while (j <= size)
{
while (j >= (size / 3) + 1  && j < (size / 3) * 2 + 1
&& i >= (size / 3) + 1 && i < (size / 3) * 2 + 1)
{
printf(" ");
j++;
}
if (i % 3 == 2 && j % 3 == 2)
{
printf(" ");
j++;
}
else
{
printf("#");
j++;
}
}
printf("\n");
}
}
}
