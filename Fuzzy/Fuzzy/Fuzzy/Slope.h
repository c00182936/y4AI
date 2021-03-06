#pragma once
class Slope
{
public:
	Slope(int upStart=0, int upEnd=1, int upY=0, int midStart=1,int midEnd=2, int midY=1,int downStart=2,int downEnd=3, int downY=0):upSlopeStart(upStart),upSlopeEnd(upEnd),midSlopeStart(midStart),midSlopeEnd(midEnd),downSlopeStart(downStart),downSlopeEnd(downEnd) {
		//upSlope = makeSlope(upSlopeStart, upSlopeEnd, upY, midY);
		//midSlope = makeSlope(midSlopeStart, midSlopeEnd, midY, midY);
		//downSlope = makeSlope(downSlopeStart, downSlopeEnd, midY, downY);

	};
	//~Slope() {};
	float getVal(float x){
		float result, temp1, temp2;
		if (x>=upSlopeStart&&x<=upSlopeEnd)//y=slope(x)+
		{
			temp1 = upSlopeEnd - upSlopeStart;
			temp2 = upSlopeEnd - x;
			result = temp1 / temp2;
			return result;
		}
		else if (x >= midSlopeStart&&x <= midSlopeEnd)
		{
			return midSlope;
		}
		else if (x >= downSlopeStart&&x <= downSlopeEnd)
		{
			temp1 = downSlopeEnd - downSlopeStart;
			temp2 = downSlopeEnd - x;
			result = temp1 / temp2;
			result = 1 - result;
			return result;
		}

	}
	float makeSlope(int startX,int startY,int endX,int endY)
	{
		float result;
		float temp1;
		float temp2;
		temp1 = startY - endY;
		temp2 = startX - endX;
		result = temp2 / temp1;
		return result;
	}
	bool withinSlope(int x)
	{
		if (x >= upSlopeStart&&x <= downSlopeEnd)
		{
			return true;
		}
		return false;
	}
	int upSlopeStart, upSlopeEnd, midSlopeStart, midSlopeEnd, downSlopeStart, downSlopeEnd;
	float upSlope, downSlope, midSlope;//y is always starting at 1 and ending at 0
	//Slope();
	//~Slope();
private:

};
