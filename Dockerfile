# Use the Fedora base image
FROM fedora:latest

# Install necessary dependencies
RUN dnf -y install gcc make CSFML-devel mesa-libGLU-devel xorg-x11-server-Xorg xorg-x11-xauth

# Set the working directory inside the container
WORKDIR /app

# Copy the source code to the container
COPY . /app

# Compile the game
RUN make
RUN chmod +x corewar.sh

# Define the command to run the game
CMD ["./corewar.sh"]
