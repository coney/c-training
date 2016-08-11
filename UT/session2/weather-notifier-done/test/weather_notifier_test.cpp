#include <cmock/cmock.h>
extern "C" {
#include "http_client.h"
#include "weather_notifier.h"
}

DECLARE_FUNCTION_MOCK1(HttpGetMock, http_get, const char *(const char *));
IMPLEMENT_FUNCTION_MOCK1(HttpGetMock, http_get, const char *(const char *));

DECLARE_FUNCTION_MOCK1(HttpPostMock, http_post, void(const char *));
IMPLEMENT_FUNCTION_MOCK1(HttpPostMock, http_post, void(const char *));

using namespace ::testing;
TEST(WeatherNotifier, ShouldSendMessageWhenItIsRaining) {
    HttpGetMock getMock;
    HttpPostMock postMock;
    EXPECT_FUNCTION_CALL(getMock, (StrEq("http://api.com/weather-api?location=Xi'an")))
        .WillOnce(Return("raining"));
    EXPECT_FUNCTION_CALL(postMock, (StrEq("http://api.com/sms-gateway?number=13012345678&content=今天下雨,记得带伞哦")))
        .Times(1);
    check_weather();
}

TEST(WeatherNotifier, ShouldDoNothingWhenItIsSunny) {
    HttpGetMock getMock;
    HttpPostMock postMock;
    EXPECT_FUNCTION_CALL(getMock, (StrEq("http://api.com/weather-api?location=Xi'an")))
        .WillOnce(Return("sunny"));
    EXPECT_FUNCTION_CALL(postMock, (StrEq("http://api.com/sms-gateway?number=13012345678&content=今天下雨,记得带伞哦")))
        .Times(0);
    check_weather();
}