-- Keep a log of any SQL queries you execute as you solve the mystery.

--Get Crime report for the day time and place the crime took place
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = 'Humphrey Street';
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were
--present at the time – each of their interview transcripts mentions the bakery.

--Check interview transcript of witnesses
SELECT transcript FROM interviews WHERE day = 28 AND month = 7;


--According Ruth(witness 1) to: Sometime within ten minutes of the theft (10:15am), I saw the thief get into a car in the bakery parking lot and drive away.
--If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

--Check bakery security log for cars exiting within 10mins of 10:15
SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute BETWEEN 15 AND 25 ORDER BY minute;
--Suspect plates [5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55]

--Check for owners of suspect license plate
SELECT name FROM people WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute BETWEEN 15 AND 25 ORDER BY minute
);
--Suspects [Vanessa, Barry, Iman, Sofia, Luca, Diana, Kelsey, Bruce]


--According to Eugene(witness 2) I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
--I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--Check atm withdrawal transactions made on legget street
SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
--Suspect acc number [28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199]

--Check for owners of account numbers
SELECT name FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts WHERE account_number IN (
        SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
    )
);
--Suspect acc number owners [Kenny, Iman, Benista, Taylor, Brooke, Luca, Diana, Bruce]


--MAIN SUSPECTS [Iman, Luca, DIANA, Bruce]

--According to Raymond(witness 3)As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.

--Check calls on the day of theft that lasted less than 60 secs
SELECT caller FROM phone_calls  WHERE day = 28 AND month = 7 AND duration < 60;
-- Suspects Number [(130) 555-0289, (499) 555-9472, (367) 555-5533, (499) 555-9472, (286) 555-6063, (770) 555-1861, (031) 555-6622, (826) 555-1652, (338) 555-6650]

--Check owners of numbers
SELECT name FROM people WHERE phone_number IN (
    SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60
);
--Owners [Kenny, Sofia, Benista, Taylor, Diana, Kelsey, Bruce, Carina]


---MAIN SUSPECTS [Diana, Bruce]


--Get fiftyville airport id
SELECT id FROM airports WHERE city = 'Fiftyville';
-- 8

--Check destination for all early flights leaving fiftyville on july 29
SELECT city FROM airports WHERE id IN (
    SELECT destination_airport_id FROM flights WHERE origin_airport_id IN (
        SELECT id FROM airports WHERE city = 'Fiftyville'
    ) AND day = 29 AND month = 7 AND hour = 8
);
--NEW York City

SELECT destination_airport_id FROM flights WHERE origin_airport_id IN (
    SELECT id FROM airports WHERE city = 'Fiftyville'
) AND day = 29 AND month = 7 AND hour = 8;
-- 4, 36

--Check for name using passport number gotten by flight id
SELECT name FROM people WHERE passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id IN (
        SELECT id FROM flights WHERE origin_airport_id IN (
            SELECT id FROM airports WHERE city = 'Fiftyville'
        ) AND day = 29 AND month = 7 AND hour = 8
    )
);

--Check for accomplice by finding who called Bruce
SELECT name FROM people WHERE phone_number IN (
    SELECT receiver FROM phone_calls WHERE caller IN (
        SELECT phone_number FROM people WHERE name = 'Bruce'
    ) AND day = 28 AND month = 7 AND duration < 60
);
--Robin