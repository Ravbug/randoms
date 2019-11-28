

//the seed and precision for this rng
unsigned int msseed = 1834659;
float msprec = 10000;

/**
@returns the next float in the sequence on [0,1)
*/
float msrand(){
	msseed = msseed * msseed + msseed;
	return msseed % (int)(msprec) /msprec;
}

/**
Uses msrand() to generate a value on [min,max)
@param min the minimum value
@param max the maximum value
@returns 
*/
float msrand_range(float min, float max){
	return msrand() * (max - min) + min;
}
