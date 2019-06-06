import Shape.Rectangle;
import Shape.Square;
import Shape.Circle;


public class TestPackage{
    public static void main(String[] args) {
        Rectangle rect = new Rectangle();
        Square square = new Square();
        Circle cir = new Circle();
        System.out.println("Different area shapes");

        rect.setArea(10,23);
        rect.displayArea();
        square.setArea(12);
        square.displayArea();
        cir.setArea(8);
        cir.displayArea();
    }
}