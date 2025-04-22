# Open the input file for reading
with open('input.txt', 'r') as input_file:
    # Open the output file for writing
    with open('output.txt', 'w') as output_file:
        # Read the input file line by line
        for line in input_file:
            # Split the line into individual hexadecimal numbers
            hex_numbers = line.strip().split()
            
            # Group the hexadecimal numbers into sets of four
            for i in range(0, len(hex_numbers), 4):
                # Get a set of four hexadecimal numbers
                four_bytes = hex_numbers[i:i+4]
                
                # Reverse the order of bytes to change endianness
                four_bytes_reversed = four_bytes[::-1]
                
                # Convert the set of four hexadecimal numbers to decimal
                decimal_num = int(''.join(four_bytes_reversed), 16)
                
                # Write the decimal number to the output file
                output_file.write(str(decimal_num) + '\n')

