class Test{
    public void displayC1(){
        System.out.println("Class First method");
    }
}

class TestClass2{
    public void dsiplayC2(){
        Test obj3 = new Test();
        obj3.displayC1();
        System.out.println("Class second method");
    }
}

class TestCLassObj{
    public static void main(String[] args) {
        TestClass2 obj2 = new TestClass2();
         obj2.dsiplayC2();
    }
}