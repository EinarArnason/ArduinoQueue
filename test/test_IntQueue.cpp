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

TEST_CASE("Concistency with multiple items", "[single-file]") {
  ArduinoQueue<int> ints;
  for (int i = 0; i < 1000; ++i) {
    ints.enqueue(i);
  }

  REQUIRE(ints.isEmpty() == false);

  for (int i = 0; i < 1000; i++) {
    REQUIRE(ints.getHead() == i);
    REQUIRE(ints.getTail() == 999);
    REQUIRE(ints.dequeue() == i);
  }
}