# Websockets

## Wat zijn websockets?

* WebSocket protocol
* WebSocket API

### Architectuur

<img src="https://tutorials.freshersnow.com/wp-content/uploads/2020/01/websocket-architecture.png">

### Protocol

* Zelfde poorten als HTTP en HTTPS
* Protocol: ws en wss
* Mask: 4 bytes (client only)
* Opcode & length: 2 bytes
* Extended length & extension data
* Application data: n bytes

### API (deels)

```js
let myWebSocket = new WebSocket("ws://www.websockets.org");
// connectie geopend
myWebSocket.addEventListener('open', function (event) {
    myWebSocket.send('Hello Server!');
});
// luisteren naar berichten
myWebSocket.addEventListener('message', function (event) {
    console.log('Message from server ', event.data);
});
// server sluit verbindin
myWebSocket.addEventListener('close', function(event) {
    alert("Connection closed.");
});
myWebSocket.send("Hello WebSockets!");
myWebSocket.close();
```

<img src="https://i.ibb.co/PYqYNWF/afbeelding.png">

<img src="https://i.ibb.co/YTrntCm/afbeelding.png">

