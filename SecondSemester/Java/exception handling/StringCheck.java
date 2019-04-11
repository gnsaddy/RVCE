class StringCheck {
	public static void main(String[] args){
		
	String s= new  String("hello");
	String s1="Hello";
	String s2=s.intern();
	if(s1==s2){
		System.out.println("ref match");
	}
	else
		System.out.println("not match");
}
}