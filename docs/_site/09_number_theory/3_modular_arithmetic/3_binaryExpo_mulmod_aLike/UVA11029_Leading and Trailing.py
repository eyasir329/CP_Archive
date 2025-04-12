import math

def calculate_first_and_last_digits(n, k):
    # Calculate last three digits using modular exponentiation
    last_three = pow(n, k, 1000)
    
    # Calculate first three digits
    log_value = k * math.log10(n)
    fractional_part = log_value - math.floor(log_value)
    first_three = int(10**fractional_part * 100)
    
    return first_three, last_three

# Input and Output
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    first_three, last_three = calculate_first_and_last_digits(n, k)
    print(f"{first_three:03d}...{last_three:03d}")
