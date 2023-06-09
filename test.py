file1_lines = []
file2_lines = []

# Read lines from file-1.txt
with open("file-1.txt", "r") as file1:
    file1_lines = file1.readlines()

# Read lines from file-2.txt
with open("file-2.txt", "r") as file2:
    file2_lines = file2.readlines()

# Initialize a dictionary to store the sums for each line in file-1.txt
sums = {}

# Compare each line from file-1.txt to file-2.txt
for line1 in file1_lines:
    line1 = line1.strip()
    line_sum = 0

    for line2 in file2_lines:
        line2_parts = line2.split("$")
        if line1 == line2_parts[0].strip():
            last_column_value = int(line2_parts[1].strip())
            line_sum += last_column_value

    sums[line1] = line_sum

# Print each line from file-1.txt with its sum
for line in file1_lines:
    line = line.strip()
    line_sum = sums[line]
    print(line, "Sum:", line_sum)
