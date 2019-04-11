class Vehicle{
    void print(){
        System.out.println("base class");
    }
}
class Single extends Vehicle{
    void print(){
        super.print();
        System.out.println("from child");
    }
    void dif(){
        System.out.println("new child method");
    }
    public static void main(String[] args){
    Single s=new Single();
    s.print();
    s.dif();
}
}