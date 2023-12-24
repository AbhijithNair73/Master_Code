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
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket.\n";
        WSACleanup();
        return 1;
    }

    // Set up server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error binding socket.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Error listening for connections.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 12345...\n";

    // Accept incoming connections
    sockaddr_in clientAddr;
    int clientAddrSize = sizeof(clientAddr);

    SOCKET clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&clientAddr), &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error accepting connection.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connection from " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;

    // Receive and echo messages
    char buffer[1024];
    int bytesRead;
    std::wstring wmessage;
    do {
        bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::wcout << L"Client says: " << buffer << std::endl;
            std::wcout << L"Enter a message: ";
            std::getline(std::wcin, wmessage);

            // Convert wide string to narrow string (UTF-8)
            std::string message(wmessage.begin(), wmessage.end());

            // Send the message to the server
            send(clientSocket, message.c_str(), message.length(), 0);
        }
    } while (bytesRead > 0);

    // Close sockets
    closesocket(clientSocket);
    closesocket(serverSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}
