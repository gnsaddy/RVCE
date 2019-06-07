package testfiles;

import java.io.*;
import java.util.Scanner;

public class FileOperation {
    public static void fileDetails() {
        File file = new File("./.");
        String[] child = file.list();
        if (child == null) {
            System.out.println("Not found");
        } else {
            for (int i = 0; i < child.length; i++) {
                String fileName = child[i];
                System.out.println(fileName);
            }
        }

    }


    public static void writeToFile() {
        System.out.println("Select from the following file : ");
        fileDetails();

        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the existing file name or create new file");
            String fileName = sc.nextLine();
            System.out.println("Enter string to input ");
            String str = sc.nextLine();
            FileWriter fileWriter = new FileWriter(fileName);
            fileWriter.write(str);
            fileWriter.close();
            System.out.println("Operation done");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void readAFile(){
        System.out.println("Select from the following file");
        fileDetails();

        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the file name");
            String filename = sc.nextLine();
            FileReader fileReader = new FileReader(filename);
            int i=0;
            while ((i=fileReader.read()) != -1){
                System.out.print((char)i);
            }
            fileReader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void appendToFile(){
        System.out.println("select from the following files :-");
        fileDetails();
        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter existing file name or enter file name to create file");
            String fileName = sc.nextLine();
            FileWriter fileWriter = new FileWriter(fileName,true);
            System.out.println("--------------------------------");
            System.out.println("Enter data ----------------");
            String str = sc.nextLine();
            // byte[] strToByte = str.getBytes();
            fileWriter.write(str);
            fileWriter.close();
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