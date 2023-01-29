import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Error Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    data_b = []
    with open(sys.argv[1]) as database_file:
        csv_reader = csv.DictReader(database_file)
        for i in csv_reader:
            data_b.append(i)
        #print(data_b)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as sequence_file:
        txt_reader = sequence_file.read()

    sequences = []
    # TODO: Find longest match of each STR in DNA sequence
    #Add each STR to a list
    sequences = list(data_b[0].keys())[1:]
    #print(sequences)

    dna_profile = {}
    for sequence in sequences:
        dna_profile[sequence] = longest_match(txt_reader, sequence)
    #print(dna_profile)

    # TODO: Check database for matching profiles
    for profile in data_b:
        match = 0
        for sequence in sequences :
            if int(profile[sequence]) == dna_profile[sequence] :
                match =  match + 1
            else:
                pass

        #Check if all the sequences match:
        if match == len(sequences):
            print(profile["name"])
            return

    #If all profiles has been checked and no match
    print("No match")


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
