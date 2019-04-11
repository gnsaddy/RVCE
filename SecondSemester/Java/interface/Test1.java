interface It2 {
    void m1();
    void m2();
    void m3();
}

abstract class A implements It2 {
    public void m1() {
        System.out.println("M1 method");
    }
}
abstract class B extends A {
    public void m2() {
            System.out.println("M2 method");
        }
    }
    class Test1 extends B {
    public void m3() {
        System.out.println("M3 method");
    }

    public static void main(String[] args) {
        Test1 obj = new Test1();
        obj.m1();
        obj.m2();
        obj.m3();
    }}


