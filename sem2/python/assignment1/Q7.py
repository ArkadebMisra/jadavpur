import os

# creating a generator to generate the path one by one
def findfiles(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            yield os.path.join(root, file)

# only looking all the files and folder in the current directory
directory_path = './'
for filepath in findfiles(directory_path):
    print(filepath)