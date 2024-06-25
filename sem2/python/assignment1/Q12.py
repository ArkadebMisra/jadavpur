import string

# Get all lowercase ASCII letters
lowercase_letters = string.ascii_lowercase

# Use enumerate to numerate the sequence, starting from 1
for index, letter in enumerate(lowercase_letters, start=1):
    print(f"{index}: {letter}", end=", ")
print("")
