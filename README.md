
# File Splitter

File Splitter is a C++ utility that allows you to divide a large file into multiple pieces of a size specified by the user. This feature is particularly useful when you need to transfer large files via limited storage media or when downloading large files over unstable networks.


## How It Works


1. The user is prompted to enter the name of the file to be split.
2. The program checks if the file exists before proceeding.
3. The user is prompted to specify the chunk size in megabytes (MB).
4. The program calculates the number of bytes equivalent to the specified size in MB.
5. The file is opened in binary mode (ios::binary) to ensure proper handling of bytes.
6. The program loops through the input file and reads chunks of the specified size, writing them into separate output files.
7. Each output file receives a unique name based on the input file name, with a suffix ".partX" where X is the chunk number.
8. The program stores the names of the output files in a vector to display them to the user at the end.
9. Once all the chunks are created, the program displays the names of the output files to the user.


## Memory Management

The program uses a temporary vector to store each chunk of the file during reading and writing, allowing efficient handling of large files without consuming an excessive amount of RAM. Read and write operations are performed using fixed-size buffers (determined by the chunk size), reducing pressure on the system's memory.


## Why It's Great

- User-Friendly: The program guides users through the file division process by asking for the input file name and the desired size for the chunks.
- Efficient: Optimized input/output operations enable the program to efficiently split large files into chunks without consuming excessive RAM.
- Convenient: File splitting is useful for transferring and storing large files, especially in scenarios with limited storage media.
- Crash Prevention: Allowing users to specify the chunk size prevents crashes caused by excessive RAM usage when processing very large files.


## Disclaimer

Ensure you have a backup of your original files before splitting them, as the resulting chunks will be independent files and cannot be used as a single complete file without being reassembled in their original order.

Feel free to contribute or report issues if you have any suggestions to improve the program!

## Installation

- Make sure you have a C++ compiler installed on your system. (GCC, Clang...)
- Clone the repository or download the source code files to your local machine.
```bash
  git clone https://github.com/TanevAZ/FileSplitter.git
  cd FileSplitter
```
- Compile the program using the C++ compiler your downloaded.
- After successful compilation, you will find an executable file named "FileSplitter" in the same directory.

## Screenshot

![image](https://github.com/TanevAZ/FileSplitter/assets/66444552/f179b580-3d8e-432a-b5c9-219ebae1ee69)
