    // save within the same directory and import the package.


package p2;
import p1.Check;
public class Check2
{
	public void disp()
	{
		System.out.println("second package ");
	}
	public static void main(String[] args) 
	{
		Check2 c=new Check2();
		c.disp();
		Check c1=new Check();
		c1.show();
	}
}
