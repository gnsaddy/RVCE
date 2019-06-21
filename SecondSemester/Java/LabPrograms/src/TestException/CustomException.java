package TestException;

import java.util.Scanner;

class UsnNotFound extends Exception {

    public UsnNotFound(String message) {
        super(message);
    }

}

class StudentUsn {

     public static void usn(String name) throws UsnNotFound {

         if ("1RD18MCA01".equalsIgnoreCase(name) || "1RD18MCA02".equalsIgnoreCase(name)) {
             System.out.println("USN valid! You scored first Rank");
         }
         else if (name != "1RD18MCA01" || name != "1RD18MCA02"){
             throw new UsnNotFound("Result not found!");
         }
     }

     public static void main(String[] args) {
         try {
             Scanner sc = new Scanner(System.in);
             System.out.println("Enter USN to check result");
             String take = sc.nextLine();
             usn(take);

         } catch (UsnNotFound e) {
             System.out.println("Exception : "+e);
         }
     }
 }