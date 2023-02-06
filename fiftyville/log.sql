-- Keep a log of any SQL queries you execute as you solve the mystery.

--Convert database to excel to better understand the tables and their interconnections

--Get Crime report for the day time and place the crime took place
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = 'Humphrey Street';
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were
--present at the time – each of their interview transcripts mentions the bakery.

--Check interview transcript of witnesses
SELECT transcript FROM interviews WHERE day = 28 AND month = 7;

--According Ruth(witness 1) to: Sometime within ten minutes of the theft (10:15am), I saw the thief get into a car in the bakery parking lot and drive away.
--If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

