public class Q6 {
    // Method to show an integer
    public void show(int num) {
        System.out.println("Integer value: " + num);
    }
    
    // Method to show a double
    public void show(double num) {
        System.out.println("Double value: " + num);
    }
    
    public static void main(String[] args) {
        Q6 demo = new Q6();
        
        // Call show method with a short as actual parameter
        short shortValue = 10;
        demo.show(shortValue);
        
        // Call show method with a double as actual parameter
        double doubleValue = 20.5;
        demo.show(doubleValue);
    }
}
