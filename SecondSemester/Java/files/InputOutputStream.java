import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.File;
import java.util.*;

class InputOutputStream {
    
    public static void fileDetails(){
        File dir = new File("./.");
        String[] children = dir.list();
        if (children == null) {
            System.out.println( "Either dir does not exist or is not a directory");
        } else { 
            for (int i = 0; i< children.length; i++) {
                String filename = children[i];
                System.out.println(filename);
            }
        }
    }
    public static void writeToFile() {
        System.out.println("select from the following files :-");
        fileDetails();
        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter existing file name or enter file name to create file");
            String fileName = sc.nextLine();
            FileOutputStream outputStream = new FileOutputStream(fileName);
            System.out.println("--------------------------------");
            System.out.println("Enter data ----------------");
            String str = sc.nextLine();
            byte[] strToByte = str.getBytes();
            outputStream.write(strToByte);
            outputStream.close();
            System.out.println("Operation sucessful"); 
        }catch(IOException e){
            System.out.println("Exception caught "+e);
        }
    }

    public static void readAFile() {
        fileDetails();
        try{
            System.out.println("Choose for the following files :- ");
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter selected file name");
            String fileName = sc.nextLine();
            FileInputStream inputStream = new FileInputStream(fileName);
            int i=0;
            while((i=inputStream.read())!=-1)
                System.out.print((char)i);
            inputStream.close();
        }catch(IOException e){
            System.out.println("Exception caught "+e);
        }
    }
    
    public static void appendToFile(){
        System.out.println("select from the following files :-");
        fileDetails();
        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter existing file name or enter file name to create file");
            String fileName = sc.nextLine();
            FileOutputStream outputStream = new FileOutputStream(fileName,true);
            System.out.println("--------------------------------");
            System.out.println("Enter data ----------------");
            String str = sc.nextLine();
            byte[] strToByte = str.getBytes();
            outputStream.write(strToByte);
            outputStream.close();
            System.out.println("Operation sucessful");
        }catch(IOException e){
            System.out.println("Exception caught "+e);
        }

    }

    public static void main(String[] args) {
        System.out.println("File operation in Java");
        int ch;
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("\n1-Available Files \n2-Write\n3-Read\n4-Append\n");
            System.out.print("Enter choice : \n");
            ch = sc.nextInt();
            switch(ch){
                case 1: 
                    fileDetails();
                    break;
                case 2:
                    writeToFile();
                    break;
                case 3:
                    readAFile();
                    break;
                case 4:
                    appendToFile();
                    break;
                default:
                    System.out.println("Invalid choice");
                    System.exit(0);
            }
        }
    }
}