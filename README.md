# Polynomial Calculator

This project implements a polynomial calculator using linked lists. The program allows the user to perform various operations on polynomials such as addition, subtraction, multiplication, reading polynomials from a file, and writing the results to a file. The implementation makes use of object-oriented programming concepts, and linked lists are used to store polynomial terms efficiently.

## Directory Structure

```
.
|-- file1.txt              # Sample file to read polynomial expressions
|-- linkedlist.cpp         # Implementation of the linked list class
|-- linkedlist.h           # Header file for the linked list class
|-- linkedlist.o           # Compiled object file for linked list
|-- main.cpp               # Entry point for the program
|-- main.o                 # Compiled object file for main
|-- Makefile               # Build instructions for the project
|-- output.out             # Compiled executable for the program
|-- polycalculator.cpp     # Implementation of the polynomial calculator class
|-- polycalculator.h       # Header file for the polynomial calculator class
|-- polycalculator.o       # Compiled object file for the polynomial calculator
|-- README.md              # Project documentation
```

## How to Compile and Run the Program

1. **Navigate to the Project Directory:**

   ```bash
   cd /path/to/your/project
   ```

2. **Compile the Program Using `make`:**
   Run the `make` command to compile the program. This will generate the executable file named `output.out`.

   ```bash
   make
   ```

3. **Run the Program:**
   Execute the compiled program by running the following command:

   ```bash
   ./output.out
   ```

4. **Interact with the Program:**
   The program will display a list of available commands. Follow the prompts to perform operations on polynomials.

## Features and Commands

### Available Commands

- `display`: Display the current polynomials stored in the linked lists.
- `input`: Input polynomial expressions manually from the keyboard.
- `add`: Add the two polynomials and display the result.
- `sub`: Subtract the second polynomial from the first and display the result.
- `mul`: Multiply the two polynomials and display the result.
- `read <file_name>`: Read polynomial expressions from the specified file.
- `write <file_name>`: Write the polynomials and their results to the specified file.
- `help`: Display the list of available commands.
- `exit` or `quit`: Exit the program.

### Example Input and Output

**Example 1: Input Polynomials Manually**

```
> input
Enter the first polynomial expression: 3x^2 + 4x + 5
Enter the second polynomial expression: 2x^3 - 4x
```

**Example 2: Add Polynomials**

```
> add
Exp1 + Exp2 = +2x^3+3x^2+0x+5
```

**Example 3: Read Polynomials from a File**

```
> read file1.txt
Exp1: +3x^2+4x+5
Exp2: +2x^3-4x
```

**Example 4: Write Results to a File**

```
> write output.txt
```

## File Structure

### `main.cpp`

- Handles user input and calls appropriate methods from the `PolyCalculator` class.
- Displays a list of commands and processes user commands in a loop.

### `polycalculator.cpp`

- Implements the `PolyCalculator` class, which manages operations on polynomials stored as linked lists.
- Includes methods for:
  - Inputting polynomials
  - Adding, subtracting, and multiplying polynomials
  - Reading and writing polynomial data to/from files
  - Parsing polynomial expressions into linked lists

### `linkedlist.cpp`

- Implements the `LinkedList` class, which manages a list of nodes representing polynomial terms.
- Includes methods for:
  - Inserting nodes while maintaining order
  - Counting nodes
  - Printing the list
  - Removing all nodes (clearing the list)

### `Makefile`

- Provides build instructions to compile the program.
- Targets:
  - `all`: Compile all object files and link them to create the executable.
  - `clean`: Remove compiled object files and the executable.
