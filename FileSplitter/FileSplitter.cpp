#include "FileSplitter.h"

using namespace std;

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << R"(
                ______ _ _      _____       _ _ _   _            
                |  ___(_) |    /  ___|     | (_) | | |           
                | |_   _| | ___\ `--. _ __ | |_| |_| |_ ___ _ __ 
                |  _| | | |/ _ \`--. \ '_ \| | | __| __/ _ \ '__|
                | |   | | |  __/\__/ / |_) | | | |_| ||  __/ |   
                \_|   |_|_|\___\____/| .__/|_|_|\__|\__\___|_|   
                                     | |                         
                                     |_|                         
        
                    Github : https://github.com/TanevAZ
                                        
)" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << "\n[1] Exit  [2] File Splitter\n";
    cout << "\nOption > ";
}

int main() {
    SetConsoleTitle(TEXT("File Splitter"));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    displayMenu();

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    bool exitProgram = false;
    int choice;

    while (!exitProgram) {
        cin >> choice;
        switch (choice) {
        case 1:
            exitProgram = true;
            break;
        case 2: {
            // Get the input file name from the user.
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nEnter the input file name: ";
            string inputFileName;
            cin >> inputFileName;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            // Check if the input file exists.
            if (!filesystem::exists(inputFileName)) {
                cout << "Error: Input file not found." << endl;
                continue;
            }

            // Get the size of the input file.
            long long fileSize = filesystem::file_size(inputFileName);

            // Create a vector to store the split file names.
            vector<string> splitFileNames;

            // Get the chunk size from the user (in MB).
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nEnter the chunk size in MB: ";
            double chunkSizeMB;
            cin >> chunkSizeMB;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            long long chunkSize = static_cast<long long>(chunkSizeMB * 1024 * 1024);

            // Split the input file into chunks of the specified size.
            ifstream inputFile(inputFileName, ios::binary);
            for (long long i = 0; i < fileSize; i += chunkSize) {
                // Get the extension of the input file.
                string extension = inputFileName.substr(inputFileName.find_last_of(".") + 1);

                // Create a new output file.
                string outputFileName = inputFileName + ".part" + to_string(i / chunkSize) + "." + extension;
                ofstream outputFile(outputFileName, ios::binary);

                // Calculate the actual chunk size to read in this iteration.
                long long remainingBytes = fileSize - i;
                long long bytesToRead = min(chunkSize, remainingBytes);

                // Write the next chunk of the input file to the output file.
                vector<char> buffer(bytesToRead);
                inputFile.read(buffer.data(), bytesToRead);
                outputFile.write(buffer.data(), bytesToRead);

                // Add the output file name to the vector of split file names.
                splitFileNames.push_back(outputFileName);
            }

            // Print the list of split file names to the user.
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nThe split file names are: " << endl;
            for (const string& splitFileName : splitFileNames) {
                cout << splitFileName << endl;
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }

        // Display the menu again after finishing file splitting.
        displayMenu();
    }

    return 0;
}