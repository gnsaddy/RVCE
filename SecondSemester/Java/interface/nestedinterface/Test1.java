package nestedinterface;

class A {
    interface It1 {
        void m1();
    }
}

 class Test1 implements A.It1 {
    public void m1(){
        System.out.println("Interface method m1");
    }
    public static void main(String[] args) {
        Test1 obj = new Test1();
        obj.m1();
    }
}
