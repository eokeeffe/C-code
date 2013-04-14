/*conversion functions*/

//conversion scale number
static double ConversionFactor = 43560.000;

extern double convertxToy(double x)
{
	return (x*ConversionFactor);
}

extern double convertyTox(double y)
{
	return (y/ConversionFactor);
}
