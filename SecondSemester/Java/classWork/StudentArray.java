import java.util.Scanner;

class StudentArray{
    int sum = 0;
    int marks;
    public void getData(){
        int[] score = new int[5];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter marks: ");
        for(int i=0;i<score.length;i++){
            score[i]=sc.nextInt();
        }
        System.out.println("Marks are as:");
        for(int i=0;i<score.length;i++){
            System.out.print(score[i]+" "+"\n");
        }
        for(int i=0;i<score.length;i++){
            sum = sum + score[i]; 
        }
        System.out.println("Total marks:"+sum);
    }
    public static void main(String[] args) {

        
        StudentArray obj = new StudentArray();
        obj.getData();
        
    }
}