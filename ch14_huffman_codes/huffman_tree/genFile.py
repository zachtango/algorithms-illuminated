import os

# Set the size of the file in bytes
file_size = 100 * 1024 * 1024  # 100 MB

# Generate random data and write it to the file
with open("large_file.txt", "wb") as file:
    file.write(os.urandom(file_size))

print("Large file 'large_file.txt' generated successfully.")