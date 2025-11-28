# PowerShell script to automate the sorting algorithm testing

Write-Host "=== AUTOMATED SORTING ALGORITHM TEST ===" -ForegroundColor Green
Write-Host "Generating 1 million element files and comparing algorithms..." -ForegroundColor Yellow

# Create input for the program
$input_commands = @(
    "1",        # Select file generation menu
    "4",        # Generate all types of files
    "1000000",  # Size: 1 million elements
    "0",        # Back to main menu
    "4",        # Compare algorithms
    "Ordenado01000000.txt",  # Test with ordered file
    "4",        # Compare algorithms again
    "Invertido01000000.txt", # Test with inverted file
    "4",        # Compare algorithms again
    "Randomico01000000.txt", # Test with random file
    "0"         # Exit
)

# Convert to string with newlines
$input_string = $input_commands -join "`n"

# Run the program with automated input
Write-Host "Starting program execution..." -ForegroundColor Cyan
$input_string | ./output/main

Write-Host "`nAutomated test completed!" -ForegroundColor Green
