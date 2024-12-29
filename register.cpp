#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    // Set content-type header
    cout << "Content-type: text/html\r\n\r\n";
    
    // Get form data from environment variables (using POST method)
    string query = getenv("QUERY_STRING");
    string username, password, confirm_password;

    // Example: extract the username, password, and confirmation (basic parsing)
    size_t pos_username = query.find("new-username=");
    size_t pos_password = query.find("&new-password=");
    size_t pos_confirm = query.find("&confirm-password=");

    if (pos_username != string::npos && pos_password != string::npos && pos_confirm != string::npos) {
        username = query.substr(pos_username + 13, pos_password - (pos_username + 13));
        password = query.substr(pos_password + 14, pos_confirm - (pos_password + 14));
        confirm_password = query.substr(pos_confirm + 17);

        // Simple password matching check
        if (password == confirm_password) {
            // Here you would typically save the username and password to a database
            // For this example, we will just redirect to afterLR.html with action=register
            cout << "Location: afterLR.html?action=register\r\n\r\n";
        } else {
            // Redirect to afterLR.html with action=error if passwords do not match
            cout << "Location: afterLR.html?action=error\r\n\r\n";
        }
    } else {
        // Redirect to afterLR.html with action=error if data is not properly received
        cout << "Location: afterLR.html?action=error\r\n\r\n";
    }

    return 0;
}