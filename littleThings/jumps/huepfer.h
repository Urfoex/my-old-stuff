int huepfer(int a,int b)
{
	int c;

	c=0;

	while (c<(b-1)) 
	{
		cout << endl;
		c++;
	}


	c=1;
	while (c<(a)) 
	{
		cout << " ";
		c++;
	}
	
	if ((b<1) || (a<1) || (b>19) || (a>80))
		cout << "ERROR";
	else 
		cout << "*";

return 0;
}