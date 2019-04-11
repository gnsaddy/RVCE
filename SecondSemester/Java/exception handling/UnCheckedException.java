// exmple of unchecked exception and can handled by user by providing explicitly try and catch block


class Test2 {
public static void main(String[] args)
{
	try {                                 // nesting of try block
	                                      // every catch block can only execute after the try block
		try {
			int x=10/0;
		}
		catch (ArithmeticException e)
	{
		System.out.println(e);
	}
		
		int[] y =new int[5];
		y[10]=20;
	}
	catch(ArrayIndexOutOfBoundsException a)
	{
		System.out.println(a);
	}

}
}

// try can handled only one exception at a time so in that case it handled the first exception as 
//"java.lang.ArithmeticException: / by zero"
//top to bottom approch