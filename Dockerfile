# Get the GCC preinstalled image from Docker Hub
FROM g++:4.9

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . ./

# Specify the working directory
WORKDIR ./

# Use GCC to compile the Test.cpp source file
RUN g++ -o source_file *.cpp

# Run the program output from the previous step
CMD ["./source_file"]
