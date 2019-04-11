 package nesting.p2;
import nesting.p1.subp1.subp2.*;
public class PackNesting2 extends PackNesting {

	public void show(){
		super.show();
		System.out.println("package 2 disp method");
	}
	public static void main(String[] args)
	{
		PackNesting2 obj = new PackNesting2();
		obj.show();
		//obj.disp();
	}
}