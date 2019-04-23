class Animal{
    public void m1(){
        System.out.println("Animal parent class");
    }
}
class Mammal extends Animal{
    public void m2(){
        super.m1();
        System.out.println("Method from mammal class");
    }
}
class Reptile extends Animal{
    public void m3(){
    System.out.println("Method from reptile class ");
    }
}
public class MultiLevel{
public static void main(String args[]){
    Mammal m = new Mammal();
    Reptile d = new Reptile();
    m.m2(); d.m3();
    }
}