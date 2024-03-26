class BankAcct {
    private int accountNumber;
    private double balance;
    private static double interestRate = 0.05; // Default interest rate
    
    // Constructor to initialize account number and balance
    public BankAcct(int accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }
    
    // Method to change interest rate
    public static void setInterestRate(double newRate) {
        interestRate = newRate;
    }
    
    // Method to display interest rate
    public static void displayInterestRate() {
        System.out.println("Interest Rate: " + interestRate);
    }
    
    // Method to return balance
    public double getBalance() {
        return balance;
    }
    
    // Method to calculate and return interest
    public double calculateInterest() {
        return balance * interestRate;
    }
}

public class Q9{
    public static void main(String[] args) {
        // Create a bank account object
        BankAcct account = new BankAcct(123456, 1000);
        
        // Display initial balance
        System.out.println("Initial Balance: $" + account.getBalance());
        
        // Display initial interest rate
        System.out.print("Initial ");
        BankAcct.displayInterestRate();
        
        // Calculate and display interest
        System.out.println("Interest: $" + account.calculateInterest());
        
        // Change interest rate
        BankAcct.setInterestRate(0.06);
        
        // Display new interest rate
        System.out.print("New ");
        BankAcct.displayInterestRate();
        
        // Calculate and display new interest
        System.out.println("New Interest: $" + account.calculateInterest());
    }
}
