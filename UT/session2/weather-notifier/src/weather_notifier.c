#include "stdio.h"
#include "string.h"
#include "http_client.h"
#include "weather_notifier.h"

    void check_weather()
    {
        char urlbuf[128];
        sprintf(urlbuf, "http://api.com/weather-api?location=%s", "Xi'an");
        const char *result = http_get(urlbuf);
        if (result && !strcmp(result, "raining")) {
            sprintf(urlbuf, "http://api.com/sms-gateway?number=%s&content=%s", 
                "13012345678", "今天下雨,记得带伞哦");
            http_post(urlbuf);
        }
    }
