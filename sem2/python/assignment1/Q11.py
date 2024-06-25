# n = 10
# a = [(a, b, c) for a in range(n) for b in range(a) for c in range(a+b)]
# b = filter(lambda x: x[0]**2+x[1]**2==x[2]**2, a)

# print("pythagorian triplets:")
# for e in b:
#     print(e)


# Define the upper limit for the short sides of the Pythagorean triples
n = 10

# Use a list comprehension to generate all possible triples (a, b, c)
# where a and b are less than n and c is less than a + b
a = [(a, b, c) for a in range(n) for b in range(a) for c in range(a + b)]

# Use filter to keep only the tuples that satisfy the Pythagorean condition: a^2 + b^2 = c^2
b = filter(lambda x: x[0]**2 + x[1]**2 == x[2]**2, a)

# Print the Pythagorean triples
print("Pythagorean triplets:")
for e in b:
    print(e)
