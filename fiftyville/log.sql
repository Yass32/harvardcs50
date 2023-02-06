-- Keep a log of any SQL queries you execute as you solve the mystery.

--Convert database to excel to better understand the tables and their interconnections

--Get Crime report for the day time and place the crime took place
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = 'Humphrey Street';
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were
--present at the time – each of their interview transcripts mentions the bakery.

--Ceck interview transcript of witnesses

