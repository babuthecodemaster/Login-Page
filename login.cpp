#include <iostream>
#include <cstdlib>  // For getenv
#include <string>
using namespace std;

int main() {
    // Set content-type header
    cout << "Content-type: text/html\r\n\r\n";
    
    // Output the start of the HTML response
    cout << "<html>\n<head>\n<title>Login Result</title>\n</head>\n<body>\n";

    // Get form data from environment variables (using POST method)
    string query = getenv("QUERY_STRING");  // Get query string
    string username, password;
    
    // Example: extract the username and password from query (you can expand parsing as needed)
    size_t pos_username = query.find("username=");
    size_t pos_password = query.find("&password=");

    if (pos_username != string::npos && pos_password != string::npos) {
        username = query.substr(pos_username + 9, pos_password - (pos_username + 9));
        password = query.substr(pos_password + 10);

        // Simple login check (you can add more secure methods)
        if (username == "admin" && password == "1234") {
            cout << "<h2>Login Successful!</h2>\n";
        } else {
            cout << "<h2>Invalid username or password.</h2>\n";
        }
    } else {
        cout << "<h2>Error in form submission</h2>\n";
    }

    // End HTML response
    cout << "</body>\n</html>\n";

    return 0;
}
