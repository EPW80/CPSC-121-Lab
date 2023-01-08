#include <string>

std::string MilitaryToRegularTime(int military_time) {
  int hours, minutes;
  std::string meridian;
  if (military_time < 1200) {
    hours = military_time / 100;
    minutes = military_time % 100;
    meridian = " am";
  } else if (military_time == 1200) {
    hours = 12;
    minutes = 0;
    meridian = " pm";
  } else {
    hours = military_time / 100;
    minutes = military_time % 100;
    hours = hours - 12;
    meridian = " pm";
  }
  std::string time = std::to_string(hours) + ":";
  if (minutes < 10)
    time = time + "0";
  time = time + std::to_string(minutes) + meridian;

  return time;
}
