import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Error Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    data = []
    with open(sys.argv[1]) as database_file:
        csv_reader = csv.DictReader(database_file) #csv.DictReader
        for i in csv_reader:
            #data.update(i)
            #i[1:] = int(i[1:])
            print(i)
            #i[1:] = int(i[1:])
            data.append(i)

        print(data)
        # type conversation in list of dicts.
    for dicts in data:
        for (keys + 1) in dicts:
            dicts[keys] = int(dicts[keys])

        print(data)

    sequence = []
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as sequence_file:
        txt_reader = sequence_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    """profile = []
    for i in range(len(txt_reader)):
        AAGATC_count = longest_match(txt_reader, "AAGATC")
        TTTTTTCT_count = longest_match(txt_reader, "TTTTTTCT")
        AATG_count = longest_match(txt_reader, "AATG")
        TCTAG_count = longest_match(txt_reader, "TCTAG")
        GATA_count = longest_match(txt_reader, "GATA")
        TATC_count = longest_match(txt_reader, "TATC")
        GAAA_count = longest_match(txt_reader, "GAAA")
        TCTG_count = longest_match(txt_reader, "TCTG")
    profile.append(AAGATC_count, TTTTTTCT_count, AATG_count, TCTAG_count, GATA_count, TATC_count, GAAA_count, TCTG_count)
    print(profile)"""
    #profile["AGATC","TTTTTTCT","AATG","TCTAG","GATA","TATC","GAAA","TCTG"] = [AAGATC_count, TTTTTTCT_count, AATG_count, TCTAG_count, GATA_count, TATC_count, GAAA_count, TCTG_count]

    # TODO: Check database for matching profiles
    """for i in csv_reader:
        if csv_reader[i] == profile:"""

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
