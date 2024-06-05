import itertools

class NumIter:
    """Iterator for looping over a sequence backwards."""
    def __init__(self, nums):
        self.data = [i for i in range(1, nums+1)]
        self.index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.index == len(self.data):
            raise StopIteration
        self.index = self.index + 1
        return self.data[self.index-1]


num_ele = 20
nums_e = NumIter(num_ele)
nums_o = NumIter(num_ele)

print("even Numbers")
for n in itertools.compress(nums_e, [1 if x%2==0 else 0 for x in range(1, num_ele+1)]):
    print(n, end=" ")

print()

print("odd Numbers")
for n in itertools.compress(nums_o, [0 if x%2==0 else 1 for x in range(1, num_ele+1)]):
    print(n, end = " ")

print()