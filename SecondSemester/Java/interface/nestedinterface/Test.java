package nestedinterface;

interface It1 {
    void m1();
    interface It2 {
       // void m2();
        interface It3{
            void m3();
        }
    }
}

 class Test implements It1.It2.It3{

     public void m1() {
        System.out.println("Nested M1 interface method");
    }
     public void m2(){
         System.out.println("Nested m2 interface method");
     }
     public void m3() {
         System.out.println("Nested M3 interface method");
     }

     public static void main(String[] args)
    {
        Test obj=new Test();
        obj.m1();
        obj.m2();
        obj.m3();

    }
}
