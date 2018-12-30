 
#include "../rsvp/rsvp.h"

void serial_printf(const char *fmt, ...) {
  char buf[128];
  va_list args;
  va_start(args, fmt );
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);
  Serial.print(buf);
}

// This will log to an embedis channel called "log".
// Use SUBSCRIBE LOG to get these messages.
// Logs are also printed to Serial until an empty message is received.
void LOG(const String& message) {
  #ifdef RSVP_ENABLE_LOG
    static bool inSetup = true;
    if (inSetup) {
        if (!message.length()) {
            inSetup = false;
            return;
        }
        RSVP_CONSOLE.println(message);
    }
    Embedis::publish("log", message);
  #endif
}
