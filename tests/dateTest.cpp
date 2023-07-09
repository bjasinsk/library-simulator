//g++.exe -fdiagnostics-color=always -g .\tests\dateTest.cpp .\src\Date.cpp -o C:\Users\danie\Desktop\PROI\projekt\src\main.exe
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../src/Date.h"
#include "catch.h"

SCENARIO("Test")
{

    GIVEN("Example date")
    {
        int Year = 2022;
        int Month = 5;
        int Day = 10;
        Date date(Day, Month, Year);

        REQUIRE(date.get_day() == Day);
        REQUIRE(date.get_month() == Month);
        REQUIRE(date.get_year() == Year);

        SECTION("Copy constructor")
        {
            Date date2(date);
            THEN("Correct values")
            {
                REQUIRE(date2.get_day() == Day);
                REQUIRE(date2.get_month() == Month);
                REQUIRE(date2.get_year() == Year);
            }
        }

        SECTION("Assignment constructor")
        {
            Date date2(13, 6, 2022);
            date2 = date;
            THEN("Correct values")
            {
                REQUIRE(date2.get_day() == Day);
                REQUIRE(date2.get_month() == Month);
                REQUIRE(date2.get_year() == Year);
            }
        }

        SECTION("Compare dates")
        {
            Date date2(Day, Month, Year);
            Date date3(13, 5, 2022);
            Date t1(Day + 1, Month, Year);
            Date t2(Day, Month + 1, Year);
            Date t3(Day, Month, Year + 1);
            Date t4(Day - 1, Month, Year);
            Date t5(Day, Month - 1, Year);
            Date t6(Day, Month, Year - 1);

            THEN("date2 equal and date3 not equal")
            {
                REQUIRE(date2 == date);
                REQUIRE(date3 != date);
                REQUIRE(!(date3 == date));
                REQUIRE(!(date2 != date));

                REQUIRE(t1 > date);
                REQUIRE(t2 > date);
                REQUIRE(t3 > date);
                REQUIRE(date2 >= date);

                REQUIRE(t4 < date);
                REQUIRE(t5 < date);
                REQUIRE(t6 < date);
                REQUIRE(date2 <= date);

                REQUIRE(!(t1 < date));
                REQUIRE(!(t4 > date));
            }
        }

        SECTION("Add date")
        {
            ++date;
            Date date2(31,12,2022);
            ++date2;
            THEN("date increase")
            {
                REQUIRE(date.get_day() == Day + 1);
                REQUIRE(date.get_month() == Month);
                REQUIRE(date.get_year() == Year);
                REQUIRE(date2.get_day() == 1);
                REQUIRE(date2.get_month() == 1);
                REQUIRE(date2.get_year() == 2023);
            }
        }

        SECTION("Postinkrementacja")
        {
            Date date2(11,5,2022);
            date2 = date++;
            THEN("date increase")
            {
                REQUIRE(date2.get_day() == Day);
                REQUIRE(date2.get_month() == Month);
                REQUIRE(date2.get_year() == Year);
            }
        }
    }
}