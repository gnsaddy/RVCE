package selftest;

import java.io.*;
import java.util.Scanner;

public class Program7 {
    Scanner sc = new Scanner(System.in);

    public void fileChooser(){
        File file = new File("./.");
        String[] child = file.list();
        if(child == null){
            System.out.println("Child not found");
        }else{
            for(int i=0;i<child.length;i++){
                String fileName = child[i];
                System.out.println("File number "+ (i+1) + " : "+fileName);
            }
        }
    }
    public void writeToFile(){
        try{
            String fileName;
            System.out.println("Enter file Name ");
            fileName = sc.nextLine();
            FileWriter fw = new FileWriter(fileName);
            String str;
            System.out.println("Enter data into file :");
            str = sc.nextLine();
            fw.write(str);
            System.out.println("Operation done ");
            fw.close();
        }catch (Throwable t){
            System.out.println("Exception Handled : "+t);
        }
    }

    public void readFromFile(){
        try{
            String fileName;
            System.out.println("Enter file Name ");
            fileName = sc.nextLine();
            FileReader fr = new FileReader(fileName);
            int ch;
            while ((ch=fr.read())!= -1){
                System.out.print((char)ch);
            }
            fr.close();
        }catch (Throwable t){
            System.out.println("Exception Handled : "+t);
        }
    }

    public void appendToFile(){
        try{
            String fileName;
            System.out.println("Enter file Name ");
            fileName = sc.nextLine();

            FileWriter fw = new FileWriter(fileName,true);
            String str;
            System.out.println("Enter data into file :");
            str = sc.nextLine();
            fw.write(str);
            System.out.println("Operation done");
            fw.close();
        }catch (Throwable t){
            System.out.println("Exception Handled : "+t);
        }
    }

    public static void main(String[] args) {
        Program7 obj = new Program7();
        Scanner sc = new Scanner(System.in);
        int ch;
        while(true){
            System.out.println("\n1-Show available files\n2-Write to file\n3-Read from file\n4-Append to file");
            System.out.print("Enter choice : ");
            ch = sc.nextInt();

            switch (ch){
                case 1:
                    obj.fileChooser();
                    break;
                case 2:
                    obj.writeToFile();
                    break;
                case 3:
                    obj.readFromFile();
                    break;
                case 4:
                    obj.appendToFile();
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
