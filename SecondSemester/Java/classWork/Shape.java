class Shape{
	int len,breadth,h;
	Shape(){
		len=breadth=h=0;
		}
	Shape(int side){
		this();
		len=breadth=h=side;
		}
	int volume(){
		return len*breadth*h;
		}
	int volume(int l,int b,int h){
			return l*b*h;
	}
	public static void main(String args[])
	{
		int r1,r2;
		//Shape s1 = new Shape();
		Shape s2 = new Shape(10);
		//r1=s1.volume();
		r2=s2.volume(3,2,4);
		//System.out.println(r1);
		System.out.println(r2);
	}
}
