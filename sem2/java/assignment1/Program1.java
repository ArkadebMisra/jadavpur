import java.util.Scanner;
public class Program1{
    public static void main(String []args){
      Scanner in = new Scanner(System.in);
      short n1,n2;
      System.out.print("\nEnter the first number : ");
      n1=in.nextShort();
      System.out.print("\nEnter the second number : ");
      n2=in.nextShort();
      int sum=n1+n2;
      System.out.print("\nThe sum of "+n1+" and "+n2+" is "+sum+"\n");
      in.close();
    }
}