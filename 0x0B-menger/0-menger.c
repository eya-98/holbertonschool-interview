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
int height, width, size, h, w;
if (level == 0)
{
printf("#\n");
}
if (level > 0)
{
size = pow(3, level);
for (height = 0; height < size; height++)
{
for (width = 0; width < size; width++)
{
h = height;
w = width;
while (h && w)
{
if (h % 3 == 1 && w % 3 == 1)
{
break;
}
h = h / 3;
w = w / 3;
}
if (h % 3 == 1 && w % 3 == 1)
{
printf(" ");
}
else 
printf("#");
}
printf("\n");
}
}
}
