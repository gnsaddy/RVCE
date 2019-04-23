class Superclass{
    int age;
    Superclass(int age){
    this.age = age;
    }
    public void getAge(){
    System.out.println("The value of the variable named age in super class is: " +age);
    }
}
class SuperClassConstructor extends Superclass {
    SuperClassConstructor(int age){
    super(age);
    }
    public static void main(String argd[]){
        SuperClassConstructor s = new SuperClassConstructor(24);
        s.getAge();
        }
    }