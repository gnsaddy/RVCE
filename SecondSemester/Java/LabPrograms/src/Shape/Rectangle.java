package Shape;

public class Rectangle {
    private double len, bre;

    public void setArea(double len,double bre){
        this.len = len;
        this.bre = bre;
    }

    public void displayArea(){
        double area = len*bre;
        System.out.println("Area of rectangle : "+ area);
    }

}