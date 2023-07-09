//g++.exe -fdiagnostics-color=always -g .\tests\timeTest.cpp .\src\Time.cpp -o C:\Users\danie\Desktop\PROI\projekt\src\main.exe
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../src/Time.h"
#include "catch.h"

SCENARIO("test of tv channels vector")
{

    GIVEN("Example time")
    {
        int Hour = 12;
        int Minute = 45;
        int Second = 23;
        Time time(Hour, Minute, Second);

        REQUIRE(time.getHour() == Hour);
        REQUIRE(time.getMinute() == Minute);
        REQUIRE(time.getSeconds() == Second);

        SECTION("Copy constructor")
        {
            Time time2(time);
            THEN("Correct values")
            {
                REQUIRE(time2.getHour() == Hour);
                REQUIRE(time2.getMinute() == Minute);
                REQUIRE(time2.getSeconds() == Second);
            }
        }

        SECTION("Assignment constructor")
        {
            Time time2(13, 24, 2);
            time2 = time;
            THEN("Correct values")
            {
                REQUIRE(time2.getHour() == Hour);
                REQUIRE(time2.getMinute() == Minute);
                REQUIRE(time2.getSeconds() == Second);
            }
        }

        SECTION("Compare times")
        {
            Time time2(Hour, Minute, Second);
            Time time3(13, 5, 2);
            Time t1(Hour + 1, Minute, Second);
            Time t2(Hour, Minute + 1, Second);
            Time t3(Hour, Minute, Second + 1);
            Time t4(Hour - 1, Minute, Second);
            Time t5(Hour, Minute - 1, Second);
            Time t6(Hour, Minute, Second - 1);

            THEN("time2 equal and time3 not equal")
            {
                REQUIRE(time2 == time);
                REQUIRE(time3 != time);
                REQUIRE(!(time3 == time));
                REQUIRE(!(time2 != time));

                REQUIRE(t1 > time);
                REQUIRE(t2 > time);
                REQUIRE(t3 > time);
                REQUIRE(time2 >= time);

                REQUIRE(t4 < time);
                REQUIRE(t5 < time);
                REQUIRE(t6 < time);
                REQUIRE(time2 <= time);

                REQUIRE(!(t1 < time));
                REQUIRE(!(t4 > time));
            }
        }

        SECTION("Add time")
        {
            ++time;
            Time time2(23,59,59);
            ++time2;
            THEN("Time increase")
            {
                REQUIRE(time.getHour() == Hour);
                REQUIRE(time.getMinute() == Minute);
                REQUIRE(time.getSeconds() == Second + 1);
                REQUIRE(time2.getHour() == 0);
                REQUIRE(time2.getMinute() == 0);
                REQUIRE(time2.getSeconds() == 0);
            }
        }

        SECTION("Postinkrementacja")
        {
            Time time2(23,34,34);
            time2 = time++;
            THEN("Time increase")
            {
                REQUIRE(time2.getHour() == Hour);
                REQUIRE(time2.getMinute() == Minute);
                REQUIRE(time2.getSeconds() == Second);
                REQUIRE(time.getHour() == Hour);
                REQUIRE(time.getMinute() == Minute);
                REQUIRE(time.getSeconds() == Second + 1);
            }
        }
    }
}