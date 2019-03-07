class Test1{
	int n=10;
	Test1 add(){
		Test1 temp = new Test1();
		temp.n=n+n;
		return temp;
		}
	int display(){
	return n+n;
}
}

class returnObject{
public static void main(String[] args){

Test1 obj1 = new Test1();
Test1 obj2 = new Test1();

System.out.println("Result : " + obj2.display());
}
}
