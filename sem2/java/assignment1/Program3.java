import java.util.Scanner;
public class Program3{
    public static void main(String[] args){
        int height;
        System.out.print("\nEnter the height in cm : ");
        Scanner input=new Scanner(System.in);
        height=input.nextInt();
        
        /*
         formula 
         inch = 0.3937 * centimeter;  
         feet = 0.0328 * centimeter;  
        */

        float inch=0.3937f*height;
        float feet=0.0328f*height;

        System.out.println("\nThe required height in inch = "+inch);
        System.out.println("\nThe required height in feet = "+feet);
    }
}