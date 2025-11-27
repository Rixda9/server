#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {

  struct sockaddr_in address;

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080);

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("Socket failed\n");
    exit(EXIT_FAILURE);
  }

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Binding failed\n");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 10) < 0) {
    perror("Listen failed\n");
    exit(EXIT_FAILURE);
  }
  printf("Server is listening...\n");

  while (1) {
    struct sockaddr_in address_client;
    socklen_t addr_len = sizeof(address_client);

    int new_socket =
        accept(server_fd, (struct sockaddr *)&address_client, &addr_len);

    if (new_socket < 0) {
      perror("Accept failed\n");
      continue;
    }

    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);
    // send(new_socket, "ECHO: ", 6, 0);
    // send(new_socket, buffer, bytes, 0);

    const char *http_response = "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "\r\n"
                                "<!DOCTYPE html>"
                                "<html>"
                                "<head><title> My C Server</title></head>"
                                "<body>"
                                "<p>This is written in C from scratch. </p>"
                                "<a href='/about'> About </a>"
                                "</body>"
                                "</html>";

    write(new_socket, http_response, strlen(http_response));

    close(new_socket);
    printf("Client disconnected\n");
  }
  return 0;
}
