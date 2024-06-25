class BankAccount:
    def __init__(self, owner: str, initial_amount: float, security_pin: str):
        self.owner = owner
        self.balance = initial_amount
        self.security_pin = security_pin

    def deposit(self, amount: float):
        if amount > 0:
            self.balance += amount
            print(f"Deposited ${amount}. Current balance: ${self.balance}.")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amount: float, pin: str):
        if pin != self.security_pin:
            print("Incorrect PIN. Cannot process withdrawal.")
            return
        
        if amount > self.balance:
            print("Not enough funds. Withdrawal failed.")
        elif amount > 0:
            self.balance -= amount
            print(f"Withdrew ${amount}. Current balance: ${self.balance}.")
        else:
            print("Withdrawal amount must be positive.")

    def get_balance(self):
        return self.balance

    def change_pin(self, current_pin: str, new_pin: str):
        if current_pin == self.security_pin:
            self.security_pin = new_pin
            print("PIN updated successfully.")
        else:
            print("Incorrect PIN. PIN update failed.")

class SavingsAccount(BankAccount):
    def __init__(self, owner: str, initial_amount: float, security_pin: str, interest_rate: float):
        super().__init__(owner, initial_amount, security_pin)
        self.interest_rate = interest_rate

    def apply_interest(self):
        interest = self.balance * (self.interest_rate / 100)
        self.balance += interest
        print(f"Interest of ${interest} applied. Current balance: ${self.balance}.")

class FeeSavingsAccount(SavingsAccount):
    def __init__(self, owner: str, initial_amount: float, security_pin: str, interest_rate: float, fee: float):
        super().__init__(owner, initial_amount, security_pin, interest_rate)
        self.fee = fee

    def withdraw(self, amount: float, pin: str):
        total_amount = amount + self.fee
        if pin != self.security_pin:
            print("Incorrect PIN. Cannot process withdrawal.")
            return

        if total_amount > self.balance:
            print("Not enough funds for withdrawal and fee. Withdrawal failed.")
        elif amount > 0:
            self.balance -= total_amount
            print(f"Withdrew ${amount} with a fee of ${self.fee}. Current balance: ${self.balance}.")
        else:
            print("Withdrawal amount must be positive.")


def app():
    print("Welcome to the Banking Application!")
    account_type = input("Select account type (1: BankAccount, 2: SavingsAccount, 3: FeeSavingsAccount): ")
    
    owner = input("Enter the account owner's name: ")
    initial_amount = float(input("Enter the initial deposit amount: "))
    security_pin = input("Set your security PIN: ")

    if account_type == '1':
        account = BankAccount(owner, initial_amount, security_pin)
    elif account_type == '2':
        interest_rate = float(input("Enter the interest rate: "))
        account = SavingsAccount(owner, initial_amount, security_pin, interest_rate)
    elif account_type == '3':
        interest_rate = float(input("Enter the interest rate: "))
        fee = float(input("Enter the withdrawal fee: "))
        account = FeeSavingsAccount(owner, initial_amount, security_pin, interest_rate, fee)
    else:
        print("Invalid account type selected.")
        return

    while True:
        print("\nMenu:")
        print("1. Deposit")
        print("2. Withdraw")
        print("3. Check Balance")
        print("4. Change PIN")
        if isinstance(account, SavingsAccount):
            print("5. Apply Interest")
        print("6. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            amount = float(input("Enter deposit amount: "))
            account.deposit(amount)
        elif choice == '2':
            amount = float(input("Enter withdrawal amount: "))
            pin = input("Enter your PIN: ")
            account.withdraw(amount, pin)
        elif choice == '3':
            print(f"Current balance: ${account.get_balance()}")
        elif choice == '4':
            current_pin = input("Enter current PIN: ")
            new_pin = input("Enter new PIN: ")
            account.change_pin(current_pin, new_pin)
        elif choice == '5' and isinstance(account, SavingsAccount):
            account.apply_interest()
        elif choice == '6':
            print("Thank you for using the Banking Application. Goodbye!")
            break
        else:
            print("Invalid option selected. Please try again.")

if __name__ == "__main__":
    app()
