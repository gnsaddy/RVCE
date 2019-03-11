package shape;

public class Square {
    private double side;

    public void setArea(double side){
        this.side = side;
        
    }

    public void displayArea(){
        double area = side*side;
        System.out.println("Area of square : "+ area);
    }

}