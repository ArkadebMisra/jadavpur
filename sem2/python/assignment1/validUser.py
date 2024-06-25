import re  # Import the regular expressions module for email validation

# Define the User class with attributes for username, email, and age
class User:
    def __init__(self, username, email, age):
        self.username = username
        self.email = email
        self.age = age

# Define custom exceptions for various error conditions
class UsernameNotUniqueError(Exception):
    pass

class AgeNotPositiveIntegerError(Exception):
    pass

class UserUnder16Error(Exception):
    pass

class InvalidEmailError(Exception):
    pass

# Function to add a user to the directory if all conditions are met
def add_user_to_directory(users, username, email, age):
    # Check if the username is unique
    for user in users:
        if user.username == username:
            raise UsernameNotUniqueError(f"Username already exists: {username}")

    # Simple email validation (presence of username, @, and domain)
    pattern = r"^[a-zA-Z0-9_\.+]+@[a-zA-Z0-9]+\.[a-zA-Z]+$"
    match = re.search(pattern, email) 
    if not match:
        raise InvalidEmailError(f"Invalid email format: {email}")

    # Check if the age is a positive integer
    if age < 0:
        raise AgeNotPositiveIntegerError(f"Age is not positive: {age}")

    # Check if the user is at least 16 years old
    if age < 16:
        raise UserUnder16Error(f"User is under age: {age}")

    # Add the user to the directory
    users.append(User(username, email, age))
    print(f"User '{username}' added to directory")

# Initialize an empty list to store user data
user_data = []

# Collect user data through input
for i in range(2):
    uname = input("Enter user name: ")
    age = int(input("Enter age: "))
    email = input("Enter user email: ")
    user = (uname, email, age)  # Create a tuple with the user's data
    user_data.append(user)  # Add the tuple to the user_data list
    print(" ")

# Initialize an empty list to serve as the user directory
user_directory = []

# Iterate over the collected user data and try to add each user to the directory
print("")
for username, email, age in user_data:
    print("Trying to add", "(", username, ", ", email, ", ", age, ") to the directory")
    try:
        add_user_to_directory(user_directory, username, email, age)
    except UsernameNotUniqueError as e:
        print(f"Error: {e}")
    except AgeNotPositiveIntegerError as e:
        print(f"Error: {e}")
    except UserUnder16Error as e:
        print(f"Error: {e}")
    except InvalidEmailError as e:
        print(f"Error: {e}")
    except Exception as e:  # Catch any other unexpected exceptions
        print(f"Unexpected error: {e}")
    print()

# Print the users in the directory
print("\nUsers in directory:\n")
for user in user_directory:
    print(f"uname: {user.username}\t uemail: {user.email}\t age: {user.age}")
