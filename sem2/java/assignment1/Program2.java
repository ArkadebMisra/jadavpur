////Write a program in java that accepts number of command line parameters and displays the parameters and count of such parameters.
public class Program2{
    public static void main(String[] args){
    System.out.println("Number of command-line parameters: "+args.length);
    System.out.println("Command line parameters: ");
    for(int i=0;i<args.length;i++)
    {
        System.out.println("#"+ (i+1)+": "+args[i]); 
    }
    }
}