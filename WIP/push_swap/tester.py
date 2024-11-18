import random
import subprocess
import sys

if len(sys.argv) != 2:
	print("Insert the amount of numbers as command-line argument")
	exit(1)
numbers = int(sys.argv[1])

# Generate 100 unique random numbers
random_numbers = random.sample(range(-2147483648, 2147483647), numbers)
random_numbers_str = list(map(str, random_numbers))  # Convert numbers to strings

# Path to your program (replace 'your_program' with the actual path or command)
program_path = "./push_swap"  # Ensure the program is executable

# Combine the program path with the arguments
command = [program_path] + random_numbers_str

# Execute the program with the random numbers as arguments
try:
    result = subprocess.run(command, capture_output=True, text=True, check=True)
    print(result.stdout, end="")
except subprocess.CalledProcessError as e:
    print("Error:", e.stderr)