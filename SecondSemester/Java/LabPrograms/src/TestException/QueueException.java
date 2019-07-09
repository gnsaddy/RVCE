package TestException;
import java.util.Scanner;

class CustomException extends Exception {
    CustomException(String s) {
        super(s);
    }
}
public class QueueException {
    Scanner s = new Scanner(System.in);
    int ar[] = new int[5];
    int rear = -1, front = -1;

    public void push() throws CustomException {
        if ((rear+1) > 4) {
            throw new CustomException("queue is overflow");
        } else {
            if (front == -1)
                front = 0;
            System.out.println("Enter the element:");
            rear = rear + 1;
            ar[rear] = s.nextInt();
            System.out.println(ar[rear] + " is inserted");
        }
    }

    public void pop() throws CustomException {
        if ((front == -1) || front > rear) {
            front = -1;
            throw new CustomException("Queue Underflow");
        } else {
            System.out.println("pop element:" + ar[front]);
            front = front + 1;
        }
    }

    public void display() throws CustomException {
        if (front == -1)
            throw new CustomException("Queue empty");
        else {
            for (int i = front; i <= rear; i++) {
                System.out.println(ar[i] + "");
            }
        }
    }

    public static void main(String[] args) {
        QueueException q = new QueueException();
        Scanner s = new Scanner(System.in);
        int ch;
        int q1 = 3;
        while (q1 == 3) {
            System.out.println("1.Insert");
            System.out.println("2.Delete");
            System.out.println("3.Display");
            System.out.println("4.Exit");
            System.out.println("Enter the choice:");
            ch = s.nextInt();
            switch (ch) {
                case 1:
                    try {
                        q.push();
                    }
                    catch (CustomException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 2:
                    try {
                        q.pop();
                    }
                    catch (CustomException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3:
                    try {
                        q.display();
                    }
                    catch (CustomException e) {
                        System.out.println(e.getMessage());
                    }
                default:
                    System.out.println("Invalid choice");
            }

        }
    }
}