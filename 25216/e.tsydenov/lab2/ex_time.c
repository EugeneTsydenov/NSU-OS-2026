#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setenv("TZ", "PST8", 1);
    tzset();

    time_t now = time(NULL);
    struct tm *california_time = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S %Z", california_time);

    printf("California date: %s\n", buffer);

    return 0;
} 