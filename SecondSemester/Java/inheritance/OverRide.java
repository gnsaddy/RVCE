class Parent {
    public void method1(){
        System.out.println("Parent method");
    }
}
class OverRide extends Parent{
    public void method1(){
        super.method1();
        System.out.println("Child method");
    }
    public static void main(String[] args) {
        Parent obj = new OverRide();
        obj.method1();
    }
}