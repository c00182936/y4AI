#include "Slope.h"

#include <iostream>


/*distance curves
|
|_____   _______
|     \ /
|      X
|_____/_\_________________________________________
*/
Slope ForceSmallSlope = Slope(0, 1, 1, 1, 8, 1, 8, 12, 0);
Slope ForceMedSlope = Slope(8, 12, 1, 12, 18, 1, 18, 22, 0);
Slope ForceBigSlope = Slope(18, 22, 1, 22, 28, 1, 28, 32, 0);
Slope ForceHugeVal = Slope(28, 32, 1, 32, 40, 1, 40, 400, 1);
float smallForce, medForce, bigForce, hugeForce;
//force curves;
Slope closeDistSlope = Slope(0, 1, 1, 1, 25, 1, 25, 35, 0);
Slope medDistSlope = Slope(25, 35, 1, 35, 55, 1, 55, 65, 0);
Slope farDistSlope = Slope(55, 65, 1, 65, 90, 1, 90, 90000, 0);
float close, med, far;


int main()
{
	float enemyForceSize, minForce=0.1,maxForce=40;
	float enemyDistance, minDist=0.1, maxDist=90;


	for (int testAmounts = 0; testAmounts < 10; testAmounts++)
	{

	}






	return 0;
}