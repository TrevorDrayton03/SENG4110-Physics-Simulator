# Simple Physics Simulator

##### Project: SENG4110
##### Author: Trevor Drayton

## About 

This project is for performing a comprehensive test suite on a simple physics simulator.

The simulator determines the amount of time it takes for a cannonball to land after being shot from a cannon while utilizing Object Oriented Programming principles.

There are four inputs: gravity (newtons), cannonball type (rock, iron, glass), angle of cannon (0 to 90 degrees), and the cannon's height above the ground (meters).

## Testing

See the TESTING.MD file in the docs folder.

## Building & Using

1. Make a directory called build in the top level of the folder.
2. Change the working directory to the build folder.
3. Run the command: cmake ..
4. Run the command: make
5. Type ./project [gravity] [type] [angle] [height]

For example: ./project 9.8 iron 30.0 0.0 
