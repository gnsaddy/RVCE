package selftest;
import java.util.Scanner;

class CustomException extends Exception{
    CustomException(String s){
        super(s);
    }
}
public class Program4 {
    Scanner sc = new Scanner(System.in);
    int[] ar = new int[5];
    int rear=-1,front=-1;

    public void push() throws CustomException{
        if((rear+1)>4)
            throw new CustomException("Queue is overflow");
        else{
            if(front==-1)
                front=0;
            System.out.println("Enter number to insert");
            rear = rear+1;
            ar[rear] = sc.nextInt();
            System.out.println(ar[rear] + " is inserted ");
        }
    }

    public void pop() throws CustomException{
        if((front == -1) || (front > rear)){
            front = -1;
            throw new CustomException("Queue is underflow");
        }else {
            System.out.println(ar[front] +" is deleted");
            front = front+1;
        }
    }

    public void display() throws CustomException{
        if(front == -1)
            throw new CustomException("Queue is empty");
        else {
            for(int i=front;i<=rear;i++){
                System.out.println(ar[i] + " ");
            }
        }
    }

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        Program4 obj = new Program4();
        int ch;
        while (true){
            System.out.println("\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\n");
            System.out.print("Enter choice : ");
            ch = sc.nextInt();
            switch (ch){
                case 1:
                    try {
                        obj.push();
                    }catch (CustomException c){
                        System.out.println(c.getMessage());
                    }
                    break;
                case 2:
                    try {
                        obj.pop();
                    }catch (CustomException c){
                        System.out.println(c.getMessage());
                    }
                    break;
                case 3:
                    try {
                        obj.display();
                    }catch (CustomException c){
                        System.out.println(c.getMessage());
                    }
                    break;
                case 4:
                    System.exit(0);
                 default:
                     System.out.println("Invalid choice");
            }
        }
    }
}
