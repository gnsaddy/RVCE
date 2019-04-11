
interface It1 {  //abstract 100%
    void m1();  //public abstract
    void m2();  //public abstract
    void m3();  //public abstract
 }



class Test implements It1 {   //implementation of interface It1
    public void m1() {
        System.out.println("M1 method");
    }
    public void m2() {
        System.out.println("M2 method");
    }
    public void m3() {
        System.out.println("M3 method");
    }
    public static void main(String[] args)
    {
        Test obj=new Test();
        obj.m1();    obj.m2();   obj.m3();

        It1 i=new Test();  //interface id variable is able to hold the implementation class object.
        i.m1(); i.m2(); i.m3();
    }
}

