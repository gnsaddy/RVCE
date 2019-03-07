//import java.util.*;
class Test{
	int a,b;
	Test(int x,int y)
	{
		a=x;
		b=y;
	}
	boolean getValue(Test o)
	{
		if((o.a==a)&&(o.b==b))
			return  true;
		else
			return false;
	}
public static void main(String args[])
	{
		Test obj1 = new Test(10,20);
		Test obj2 = new Test(20,30);
		System.out.println(obj1.getValue(obj2));

}
}
