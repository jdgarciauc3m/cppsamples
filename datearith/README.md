# Goal

The goal of this exercise is designing a very simplified library to handle dates and durations.

# A duration class

We are required to develop a duration class with the following requirements:


* A Duration is represented as a number of years, months and days.
* It must be possible to build a duration from an aribtrary amount of years, months and days.
* Durations must be internally stored normalized. 
    * Consequently a duration of 1 year and 366 days should be internally converted to 2 years and 1 day.
    * For normalization 1 year is 365 days and 1 month is 30 days.
* You must be able to get years, monts and days form a duration through separate query functions.
* Durations must support construction and assignment operations both copy and move.

# A date class

We are required to develop a date class with the following requirements:

* It must represent dates between january 1, 1900 and december 31, 2200.
* It must consider leap years (recall that year 2000 was not leap).
* It must support copy construction and copy assignment.
* It must support move semantics.
* Default constructed values must be set to january 1, 1900.
* You must be able to add a duration to a date, getting a new date.
* You must be able to substract to dates getting a duration.
