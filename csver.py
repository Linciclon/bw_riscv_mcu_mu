def merge_consecutive_lines(input_file, output_file):
    # Open the input file for reading
    with open(input_file, 'r') as file:
        # Read the lines from the file
        lines = file.readlines()
        
        # Open the output file for writing
        with open(output_file, 'w') as output:
            # Iterate over pairs of consecutive lines
            for i in range(0, len(lines), 2):
                # Combine consecutive lines separated by a comma
                if i + 1 < len(lines):
                    merged_line = lines[i].strip() + ',' + lines[i + 1].strip()
                else:
                    # Handle the case where there's an odd number of lines
                    merged_line = lines[i].strip()
                
                # Write the merged line to the output file
                output.write(merged_line + '\n')

# Example usage:
merge_consecutive_lines('output.txt', 'output.csv')

