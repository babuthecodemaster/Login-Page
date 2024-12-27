#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

int main() {
    // Print the content-type header
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Login Result</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";

    // Get form data from POST request
    string username = getenv("USERNAME");
    string password = getenv("PASSWORD");

    // Simulate login validation
    if (username == "Babu" && password == "BabuKaka123$") {
        cout << "<h2>Login successful!</h2>\n";
    } else {
        cout << "<h2>Login failed. Invalid username or password.</h2>\n";
    }

    cout << "</body>\n";
    cout << "</html>\n";
    
    return 0;
}
