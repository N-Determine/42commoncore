import random
import subprocess
import sys

# Make sure that the right amount of arguments have been passed
if len(sys.argv) != 2:
    print("Usage: python3 tester.py [Amount of numbers]")
    exit(1)

numbers = int(sys.argv[1])

# Generate unique random numbers
random_numbers = random.sample(range(-2147483648, 2147483647), numbers)
random_numbers_str = list(map(str, random_numbers))  # Convert numbers to strings

program_path = "./push_swap"
checker_path = "./checker_linux"

# Create the full shell command
command = f"{program_path} {' '.join(random_numbers_str)} | {checker_path} {' '.join(random_numbers_str)}"

print(command + '\n')
print("Result: ", end="")
# Execute the program with the random numbers as arguments
try:
    result = subprocess.run(command, capture_output=True, text=True, check=True, shell=True)
    print(result.stdout, end="")
except subprocess.CalledProcessError as e:
    print("Error:", e.stderr)
