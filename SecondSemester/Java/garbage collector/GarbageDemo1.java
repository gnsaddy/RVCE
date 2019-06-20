class GarbageDemo1 {
	int x=10;
	int y=20;
	
	public void finalize() throws Throwable {
     System.out.println("object delete ");
	}
	void show() {
		GarbageDemo1 obj = new GarbageDemo1();
	}
	static void get() {
		GarbageDemo1 obj1 = new GarbageDemo1();
		obj1.show();
	}
	public static void main(String[] args)
	{ 
		for(int i = 1;i<2;i++)
		{		
			get(); // static call
			System.gc();
		}
	}
}