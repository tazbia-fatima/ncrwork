extern int result;
float divvi(int op1, int op2)
{
	if (op2 != 0)
	{
		result = (float)op1 / op2;
		return result;
	}
	return -1;
}