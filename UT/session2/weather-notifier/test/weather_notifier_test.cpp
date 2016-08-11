#include <cmock/cmock.h>
extern "C" {
#include "http_client.h"
#include "weather_notifier.h"
}

using namespace ::testing;
TEST(WeatherNotifier, ShouldSendMessageWhenItIsRaining) {
  
}

TEST(WeatherNotifier, ShouldDoNothingWhenItIsSunny) {

}