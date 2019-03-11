package shape;

public class Circle {
    private double rad;

    public void setArea(double rad){
        this.rad = rad;
        
    }

    public void displayArea(){
        double area = (3.14*rad*rad)/2;
        System.out.println("Area of circle : "+ area);
    }

}