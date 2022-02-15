float maximum( float x, float y)
{
	if ( x > y)
		return x;
	return y;
}

void main()
{
	float a = 1, b = 2.3, c;
	c = maximum( a, b);
	c = maximum( 12.3, a * b + 1);
	c = b + maximum( 1, 2);
	c = maximum( 1, maximum( a, b) + 1);
}