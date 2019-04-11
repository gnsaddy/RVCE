class Test3 {
	public static void main(String[] args)
{
	try {                                 
	     try {
			 int x=10/0;
		 }
		 catch(ArithmeticException | ArrayIndexOutOfBoundsException a)  //pipeing of catch statement
	{
		System.out.println(a);
	}
		 
	int[] y =new int[5];
		y[10]=20;
	}
	catch(ArithmeticException | ArrayIndexOutOfBoundsException a)    //pipeing of catch statement
	{
		System.out.println(a);
	}

}
}