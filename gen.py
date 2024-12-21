import sys
import random

# Get input from command line or use default value
default_value = 50
try:
    input_value = int(sys.argv[1]) if len(sys.argv) > 1 else default_value
except ValueError:
    print("Please provide a valid integer input.")
    sys.exit(1)

# Generate unique random numbers
if 0 < input_value <= 101:
    numbers = random.sample(range(101), input_value)
    print(" ".join(map(str, numbers)))
else:
    print("Input must be between 1 and 101.")
