class BankAcct {
    private int customerId;
    private String name;
    private int phoneNo;
    private double currentLoanAmount = 0;
    private double privilagedCreditLimit = 0.0; 
    private static double creditLimit = 300000; // Default interest rate
    
    // Constructor to initialize
    public BankAcct(int customerId, String name, int phoneNo) {
        this.customerId = customerId;
        this.name = name;
        this.phoneNo = phoneNo;
    }

    public BankAcct(int customerId, String name, int phoneNo, double privilagedCreditLimit) {
        this.customerId = customerId;
        this.name = name;
        this.privilagedCreditLimit = privilagedCreditLimit;
        this.phoneNo = phoneNo;
    }
    
    // Method to change name
    public void setName(String name) {
        this.name = name;
    }

    public  void setPhoneNo(int phoneNo) {
        this.phoneNo = phoneNo;
    }
    
    // Method to display interest rate
    public void displayCreditLimits() {
        if(privilagedCreditLimit==0.0){
            System.out.println("Credit Limit: " + creditLimit);
        }
        else{
            System.out.println("Credit Limit: " + privilagedCreditLimit);
        }

        System.out.println("Currernt Loan Amount: " + currentLoanAmount);

        if(privilagedCreditLimit==0.0){
            System.out.println("extra loan ammount you can apply for : " + (creditLimit-currentLoanAmount));
        }
        else{
            System.out.println("extra loan ammount you can apply for : " + (privilagedCreditLimit-currentLoanAmount));
        }

    }
    
    // Method to return balance
    public void applyForLoan(double loan) {
        if(privilagedCreditLimit==0.0){
            if(loan<=(creditLimit-currentLoanAmount)){
                System.out.println("Your loan is approved");
                currentLoanAmount += loan;
            }
            else{
                System.out.println("Your loan is not approved");
            }
        }
        else{
            if(loan<=(privilagedCreditLimit-currentLoanAmount)){
                System.out.println("Your loan is approved");
                currentLoanAmount += loan;
            }
            else{
                System.out.println("Your loan is not approved");
            }
        }
    }
    
    // // Method to calculate and return interest
    // public double calculateInterest() {
    //     return balance * interestRate;
    // }
}

public class Q1{
    public static void main(String[] args) {
        // Create a bank account object
        BankAcct account = new BankAcct(123456, "arka", 1000);

        account.displayCreditLimits();
        
        System.out.println();
        System.out.println();
        account.applyForLoan(200000);
        account.applyForLoan(200000);
        account.displayCreditLimits();
        // Display initial balance
        // System.out.println("Initial Balance: $" + account.getBalance());
        
        System.out.println();
        System.out.println();
        BankAcct account2 = new BankAcct(123456, "sohini", 1000, 400000);
        System.out.println();
        System.out.println();
        account2.applyForLoan(200000);
        account2.applyForLoan(200000);
        account2.displayCreditLimits();

        // // Display initial interest rate
        // System.out.print("Initial ");
        // BankAcct.displayInterestRate();
        
        // // Calculate and display interest
        // System.out.println("Interest: $" + account.calculateInterest());
        
        // // Change interest rate
        // BankAcct.setInterestRate(0.06);
        
        // // Display new interest rate
        // System.out.print("New ");
        // BankAcct.displayInterestRate();
        
        // // Calculate and display new interest
        // System.out.println("New Interest: $" + account.calculateInterest());
    }
}
