# Create the install directory if it doesn't exist
mkdir -p install

# Run cmake to generate build files for installation
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..

# Run make to install the library and headers
make install

# Return to the root directory
cd ..