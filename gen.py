import sys
import random

# Default values
default_count = 50
default_max = 100

# Parse command-line arguments
try:
    input_count = int(sys.argv[1]) if len(sys.argv) > 1 else default_count
    max_value = int(sys.argv[2]) if len(sys.argv) > 2 else default_max
except ValueError:
    print("Please provide valid integer inputs.")
    sys.exit(1)

# Validation
if input_count < 1 or max_value < 1:
    print("Both input count and max value must be positive integers.")
    sys.exit(1)

if input_count > max_value + 1:
    print("Input count cannot exceed max value + 1.")
    sys.exit(1)

# Generate unique random numbers
numbers = random.sample(range(max_value + 1), input_count)

# Output the numbers as space-separated values
print(" ".join(map(str, numbers)))
