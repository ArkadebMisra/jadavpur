import java.util.Scanner;
public class Program4{
    public static void main(String []args){
      final float pi=3.14f;
      float radius,area;
      System.out.print("\nEnter the radius of the circle : ");
      
      //declaring input stream
      Scanner input=new Scanner(System.in);
      
      radius=input.nextFloat();
      
      area=pi*(radius)*(radius);
      System.out.println("\nThe required area of the given radius = "+area);
    }
}