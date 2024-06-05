import java.util.Scanner;
public class Program5{
    
    public static void main(String[] args){
        String str1,str2;
    
        System.out.print("Enter your first string : ");
        
        Scanner input=new Scanner(System.in);
        
        str1=input.nextLine();  //Taking input string from the user
        str2=str1; 
        
        if(str1==str2)
        System.out.println("Both the string are equal");
    
        else
        System.out.println("\nBoth the strings are not equal");

        if(str1.equals(str2))
        System.out.println("Both the string are equal");

        else
        System.out.println("Both are not equal");
    }
}