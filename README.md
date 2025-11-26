# Basic HTTP Server

A simple, from-scratch web server implementation in C using the Linux Socket API.

## Features

Implements the full TCP Socket lifecycle (`socket`, `bind`, `listen`, `accept`)

Serves a static "Hello World" HTML response

Handles sequential client connections

Compliant HTTP/1.1 response headers

## How It Works

The server creates a TCP socket bound to port 8080. When a browser connects, the server accepts the connection, reads the raw HTTP request into a buffer, and immediately writes back a pre-formatted HTTP response string before closing the connection.

## Building
```bash
```bash
make
./webserver
```


## What I Learned

Linux Socket Programming concepts (socket, bind, listen, accept)

Network Byte Order vs Host Byte Order (htons)

How File Descriptors represent network connections in Unix

The basic structure of HTTP/1.1 requests and responses

## Limitations

No request parsing (ignores the specific file path requested)

Single-threaded (can only handle one request at a time)

Content is hardcoded strings, not loaded from files

No keep-alive support (closes connection after every request)
