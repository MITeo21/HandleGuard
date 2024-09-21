#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "cycleGuard";
const char *password = "cycleGuard";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void setupWebsocket() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println(WiFi.localIP());

  server.begin();
  ws.onEvent(onWebSocketEvent);

  server.addHandler(&ws);
  server.begin();
}

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
                      AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.println("WebSocket client connected");
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.println("WebSocket client disconnected");
  } else if (type == WS_EVT_DATA) {
    Serial.printf("Received data: %.*s\n", len, (char *)data);
  }
}

void sendWebsocketData(const String& data) {
  Serial.printf("sending data: %.*s\n", data);
  ws.textAll(data);
}