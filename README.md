# get_next_line
What is a static variable?
A static variable in C is a variable that:

Keeps its value between function calls.
Is only accessible inside the function where it’s declared.
In the get_next_line project, static variables are useful because they allow us to "remember" leftover data from a previous function call.

Why do we need a static variable in get_next_line?
When you read data from a file using the read function:

You don’t always read a complete line.
Some part of the data may belong to the next line.
We need a static variable to:

Store the extra data that wasn’t used (because it’s part of the next line).
Use this leftover data the next time get_next_line is called.
How does it work?
First Call to get_next_line:
Use read to get some data from the file.
Find the first \n (newline character) in the data.
Extract everything up to the \n and return it as the current line.
Save the remaining data (after \n) in the static variable for later.
Second Call to get_next_line:
Check the static variable first.
If it has leftover data, process it:
Find the next \n in the leftover data.
Extract the next line.
If there’s no leftover data, use read again to get more data.
Repeat:
Each time get_next_line is called, it processes the static variable first and only reads new data if necessary.
An Example
Imagine you’re reading a file that looks like this:

Hello\nWorld\nThis is a test.
With a BUFFER_SIZE of 10, the process would look like this:

First Call to get_next_line:

read gets "Hello\nWor".
The function finds the \n after "Hello".
Returns "Hello\n".
Saves "Wor" in the static variable.
Second Call to get_next_line:

The static variable has "Wor".
read adds more data: "ld\nThis i".
The full data is now "World\nThis i".
The function finds the \n after "World".
Returns "World\n".
Saves "This i" in the static variable.
Third Call to get_next_line:

The static variable has "This i".
read adds more data: "s a test.".
The full data is now "This is a test.".
Since there’s no \n, the function returns "This is a test.".
The static variable is now empty.
Key Points to Remember
Static variables "remember" data between calls: This is important because files are read in chunks, and we need to process one line at a time.
Efficient memory usage: Instead of re-reading the file from the start, we just keep the leftover data in the static variable.
No global variables allowed: Using a static variable inside the function avoids the use of forbidden global variables.
