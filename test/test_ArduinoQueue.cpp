// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <ArduinoQueue.h>
#include <catch2/catch.hpp>

TEST_CASE("Queue is empty", "[single-file]") {
  ArduinoQueue<int> ints;
  REQUIRE(ints.isEmpty() == true);
}

TEST_CASE("List has one element", "[single-file]") {
  ArduinoQueue<int> ints;
  ints.enqueue(1);
  REQUIRE(ints.isEmpty() == false);
}