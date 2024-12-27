#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    // Set content-type header
    cout << "Content-type: text/html\r\n\r\n";
    
    // Output the start of the HTML response
    cout << "<html>\n<head>\n<title>Registration Result</title>\n</head>\n<body>\n";

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
            // Here you would save the user credentials to a file or database
            cout << "<h2>Registration Successful!</h2>\n";
        } else {
            cout << "<h2>Passwords do not match.</h2>\n";
        }
    } else {
        cout << "<h2>Error in form submission</h2>\n";
    }

    // End HTML response
    cout << "</body>\n</html>\n";

    return 0;
}
