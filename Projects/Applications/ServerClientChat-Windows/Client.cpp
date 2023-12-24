#include <iostream>
#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock.\n";
        return 1;
    }

    // Create a socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket.\n";
        WSACleanup();
        return 1;
    }

    // Set up server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Loopback address

    // Connect to the server
    if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error connecting to server.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server.\n";

  // Send and receive messages
    std::wstring wmessage;

    do {
        std::wcout << L"Enter a message: ";
        std::getline(std::wcin, wmessage);

        // Convert wide string to narrow string (UTF-8)
        std::string message(wmessage.begin(), wmessage.end());

        // Send the message to the server
        send(clientSocket, message.c_str(), message.length(), 0);

        // Receive and display the echoed message from the server
        char buffer[1024];
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::wcout << L"Server says: " << buffer << std::endl;
        }
    } while (wmessage != L"exit");

    // Close the socket
    closesocket(clientSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}