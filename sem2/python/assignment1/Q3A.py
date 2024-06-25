import itertools

# Generate 20 numbers
numbers1 = (i for i in range(20))
numbers2 = (i for i in range(20))

# print(next(numbers1))

# Mask for even and odd numbers to be used in 
#itertools.compress

even_mask = []
odd_mask = []

for i in range(20):
    if i%2 == 0:
        even_mask.append(True)
        odd_mask.append(False)
    else:
        even_mask.append(False)
        odd_mask.append(True)


# Using compress to get the first 10 even and odd elements
first_10_even = list(itertools.compress(numbers1, even_mask))
first_10_odd = list(itertools.compress(numbers2, odd_mask))

print("First 10 even numbers:", first_10_even)
print("First 10 odd numbers:", first_10_odd)
