package testfiles;

import java.io.*;

public class StudentRecords {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

    public void addRecord() throws IOException{
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("studentRecords.txt",true)));
        String name,usn,curriculum,extra;
        int[] marks = new int[10];
        String s;
        boolean addMore = false;
        do{
            System.out.println("Enter name : ");
            name = sc.readLine();

            System.out.println("Enter usn : ");
            usn = sc.readLine();

            System.out.println("Enter curriculum : ");
            curriculum = sc.readLine();

            System.out.println("Enter extra curriculum : ");
            extra = sc.readLine();

            System.out.println("Enter marks");
            for (int i = 0; i < 5; i++) {
                marks[i] = Integer.parseInt(sc.readLine());
            }

            pw.println(name);
            pw.println(usn);
            pw.println(curriculum);
            pw.println(extra);
            for (int i = 0; i < 5; i++) {
                pw.println(marks[i]);
            }
            pw.println("****************************");

            System.out.print("\nRecords added successfully !\n\nDo you want to add more records ? (y/n) : ");
            s = sc.readLine();
            System.out.println("***************************");
            if(s.equalsIgnoreCase("y"))
            {
                addMore = true;
                System.out.println();
            }
            else
                addMore = false;
        }while (addMore);
        pw.close();
        showMenu();
    }

    public void readDetails() throws IOException {
        FileReader fr = new FileReader("studentRecords.txt");
        int i = 0;
        while ((i=fr.read()) != -1){
            System.out.print((char)i);
        }
        fr.close();
        showMenu();
    }

    public void showMenu() throws IOException {
        System.out.println("1-Add details\n2-View Details\n3-exit");
        int ch;
        while (true){
            System.out.print("Enter choice : ");
            ch = Integer.parseInt(sc.readLine());

            switch (ch){
                case 1:
                    System.out.println("***************************");
                    addRecord();
                    System.out.println("***************************");
                    break;
                case 2:
                    System.out.println("***************************");
                    readDetails();
                    System.out.println("***************************");
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice");
            }
        }
    }

    public static void main(String[] args) throws IOException {
        StudentRecords obj = new StudentRecords();
        obj.showMenu();
    }
}
