package testString;

public class StringMethods {
    public static void stringBufferMethods(){
        StringBuffer stringBuffer = new StringBuffer();

        System.out.println("-----------String Buffer methods----------");
        System.out.println("1-Append to buffer : "+ (stringBuffer.append("This is of string type")));
        System.out.println("2-Insert to buffer : "+ (stringBuffer.insert(18,"buffer ")));
        System.out.println("3-Index of : "+ (stringBuffer.indexOf("y")));
        StringBuffer stringBuffer1 = new StringBuffer("Python is awesome");
        System.out.println("4-Replace Python with Java : "+ (stringBuffer1.replace(0,6,"Java")));
        System.out.println("5-Reverse of string : "+ (stringBuffer.reverse()));
        stringBuffer.reverse();
        System.out.println("6-Length of string : "+ (stringBuffer.length()));
        System.out.println("7-Fetch Substring : "+ (stringBuffer1.substring(0,4)));
        System.out.println("8-string old capacity : "+ (stringBuffer.capacity())) ;
        stringBuffer.ensureCapacity(36);
        System.out.println("9-Ensure new capacity : "+ (stringBuffer.capacity()));
        stringBuffer.delete(18,24);
        System.out.println("10-Delete from string buffer : "+ (stringBuffer));


    }

    public static void stringMethods(){
        System.out.println("-----------String methods----------");
        String str = "This is of string type";
        String str1 = " Java is programming language and platform";
        System.out.println("1-String length : "+ (str.length()));
        System.out.println("2-CharAt : "+ (str.charAt(5)));
        System.out.println("3-Substring : "+ (str.substring(0,5)));
        System.out.println("4-subSequence : "+ (str.subSequence(0,5)));
        System.out.println("5-equals : "+ (str.equals(str1)));
        System.out.println("6-equalsIgnorecase : "+ (str.equalsIgnoreCase("This is of STRING type")));
        System.out.println("7-toLowerCase : "+ (str1.toLowerCase()));
        System.out.println(("8-concat : "+ (str.concat(str1))));
        System.out.println("9-indexOf : "+ (str.indexOf("of")));
//        System.out.println(str);
        System.out.println("10-hasCode : "+ (str.hashCode()));
        System.out.println("11-Last index : "+ (str.lastIndexOf('o')));
    }

    public static void main(String[] args) {
        stringBufferMethods();
        stringMethods();
    }
}


