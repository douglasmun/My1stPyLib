import sys

try:
    import my_c_module
    print("Module loaded successfully.")
    
    # Test the factorial function with an example number
    n = 10
    result = my_c_module.factorial(n)
    
    print(f"The factorial of {n} is: {result}")
    
except ImportError as e:
    print("Error: Could not import the module.")
    print("Please ensure you have built and installed it using 'python3 setup.py install'.")
    print(f"Details: {e}")
    sys.exit(1)
