#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    // Set content-type header
    cout << "Content-type: text/html\r\n\r\n";
    
    // Get form data from environment variables (using POST method)
    string username = getenv("USERNAME");
    string password = getenv("PASSWORD");

    // Example login check
    if (username == "admin" && password == "1234") {
        // Redirect to afterLR.html with action=login
        cout << "Location: afterLR.html?action=login\r\n\r\n";
    } else {
        // Redirect to afterLR.html with action=error
        cout << "Location: afterLR.html?action=error\r\n\r\n";
    }

    return 0;
}