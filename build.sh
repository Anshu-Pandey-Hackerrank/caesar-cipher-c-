#!/bin/bash

# Remove the existing 'build' if it's not a directory
if [ -e build ] && [ ! -d build ]; then
  rm -f build
fi

# Create build directory
mkdir -p build
cd build || exit 1

# Run cmake with the correct path (parent directory)
cmake ..
if [ $? -ne 0 ]; then
  echo "CMake configuration failed. Make sure CMakeLists.txt exists in the parent directory."
  exit 1
fi

# Build the project
make
if [ $? -ne 0 ]; then
  echo "Build failed."
  exit 1
fi

# Return to the original directory
cd ..

# Create bin directories
mkdir -p bin
mkdir -p test/bin

# Copy binaries with error checking
if [ -f build/caesar_cipher_app ]; then
  cp build/caesar_cipher_app bin/
else
  echo "Warning: build/caesar_cipher_app not found"
fi

if [ -f build/caesar_cipher_test ]; then
  cp build/caesar_cipher_test test/bin/
else
  echo "Warning: build/caesar_cipher_test not found"
fi

echo "Build completed successfully."