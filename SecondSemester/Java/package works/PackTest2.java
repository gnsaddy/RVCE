package com.p2;
import com.p.*;
public class PackTest2 extends PackTest {
	public PackTest2() {
		System.out.println("cons 2");
	}
	public void show(){
		super.show();
		System.out.println("package 2 disp method");
	}
	public static void main(String[] args)
	{
		PackTest obj = new PackTest2();
		obj.show();
		//obj.disp();
	}
}
