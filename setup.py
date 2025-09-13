import os
import sys
from setuptools import setup, Extension

# Check if the user is on macOS
if sys.platform == 'darwin':
    # Get the directory for the Command Line Tools SDK
    # This resolves the 'limits.h must define UCHAR_MAX' error
    try:
        sdk_path = os.popen('xcode-select --print-path').read().strip()
        include_path = os.path.join(sdk_path, 'SDKs/MacOSX.sdk/usr/include')
        compile_args = ['-I' + include_path]
    except (OSError, ValueError):
        compile_args = []
else:
    compile_args = []

# Define the C extension module
module = Extension('my_c_module',
                   sources=['my_c_module.c'],
                   extra_compile_args=compile_args,
                   # The following paths may need to be adjusted based on your Python installation
                   include_dirs=[],
                   library_dirs=[],
                   libraries=[]
                  )

# Set up the Python package
setup(
    name='my_c_module',
    version='1.0',
    description='A simple C extension module for factorial calculation.',
    ext_modules=[module]
)

