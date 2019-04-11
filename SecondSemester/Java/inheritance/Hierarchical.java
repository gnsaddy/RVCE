class Vehicle {
    public void type(){
        System.out.println("Type of vehicle");
    }
    public void speed(){
        System.out.println("Speed of vehicle");
    }
}
class Car extends Vehicle{
    public void type(){
        super.type();
        System.out.println("XUV cars");
    }
    public void speed(){
        super.speed();
        System.out.println("Highest speed is 220kms");
    }
}
clas Truck 