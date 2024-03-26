class Metric {
    // Method to convert kilometers to miles
    public static double kmToMiles(double km) {
        return km / 1.5;
    }
    
    // Method to convert miles to kilometers
    public static double milesToKm(double miles) {
        return miles * 1.5;
    }
}

public class Q10{
    
    public static void main(String[] args) {
        // Test km to miles conversion
        Metric m = new Metric();
        double km = 10.0;
        double miles = m.kmToMiles(km);
        System.out.println(km + " kilometers equals " + miles + " miles.");
        
        // Test miles to km conversion
        double milesInput = 15.0;
        double kmResult = m.milesToKm(milesInput);
        System.out.println(milesInput + " miles equals " + kmResult + " kilometers.");
    }
}
