  // example of checked exception in this JVM implicitly handled the exception 
  
  
  class Test1 {
	public static void main(String[] args)
	{
		int x=10/0;
		System.out.println(x);
	}
}