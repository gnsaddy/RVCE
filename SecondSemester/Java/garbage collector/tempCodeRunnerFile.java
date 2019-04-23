// Garbage collector...  System class call gc (static method) System.gc
class GarbageDemo {
	int x=10;
	int y=20;
	
	public void finalize() throws Throwable {
     System.out.println("object delete ");
	}
	static void show() {
		GarbageDemo obj = new GarbageDemo();
	}
	static void get() {
		GarbageDemo obj1 = new GarbageDemo();
		obj1.show();
	}
	public static void main(String[] args)
	{
		get();
		GarbageDemo.show();
		for(int i =1; i<=10; i++){
		System.gc();
		try{
			Thread.sleep(1000);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	}
}