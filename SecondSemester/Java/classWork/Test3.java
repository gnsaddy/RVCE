class Test3{
	void sum(int x,int y){
		System.out.println("sum "+ (x+y));
		}
	void sum(float x,float y){
		System.out.println("Sum "+ (x+y));
		}

	void sum(double x,double y,double z){
		System.out.println("Sum " +(x+y+z));
		}

public static void main(String[] args){

	Test3 obj1 = new Test3();

	obj1.sum(10,20);
	obj1.sum(12.2f,15.5f);
	obj1.sum(12.2,5.5,8.4);
}
}
