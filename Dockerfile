# Use the latest Ubuntu as the base image
FROM ubuntu:latest

# Install necessary tools
RUN apt-get update && apt-get install -y \
    gcc \
    gdb \
    perl \
    sudo \
    && apt-get clean

# Set the working directory
WORKDIR /app

# Copy the C source code into the container
COPY buffer_overflow_demo.c /app/buffer_overflow_demo.c

# Compile the program with a fixed base address and disabled stack protection
RUN gcc -fno-stack-protector -z execstack -Wl,-Ttext=0x400000 -o buffer_overflow_demo buffer_overflow_demo.c

# Disable ASLR and start an interactive shell at runtime
CMD echo 0 | sudo tee /proc/sys/kernel/randomize_va_space && /bin/bash
