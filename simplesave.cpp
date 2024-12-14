#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

using namespace std;

void createFile() {
    string filename, content;

    cout << "Enter the file name (with extension): ";
    getline(cin, filename);

    cout << "Enter the content for the file: ";
    getline(cin, content);

    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
        cout << "File '" << filename << "' has been successfully saved!" << endl;
    } else {
        cout << "Error creating the file!" << endl;
    }
}

void readFile() {
    string filename;

    cout << "Enter the name of the file you want to read (with extension): ";
    getline(cin, filename);

    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "Content of the file '" << filename << "':\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "File '" << filename << "' not found!" << endl;
    }
}

void deleteFile() {
    string filename;

    cout << "Enter the name of the file you want to delete (with extension): ";
    getline(cin, filename);

    if (fs::exists(filename)) {
        fs::remove(filename);
        cout << "File '" << filename << "' has been deleted!" << endl;
    } else {
        cout << "File '" << filename << "' does not exist!" << endl;
    }
}

void showSavedFiles() {
    cout << "Saved files in the current directory:\n";

    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        if (fs::is_regular_file(entry.status())) {
            cout << entry.path().filename().string() << endl;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Menu =====\n";
        cout << "1. Create file\n";
        cout << "2. Read file\n";
        cout << "3. Delete file\n";
        cout << "4. Show saved files\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline after the number input

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                showSavedFiles();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}