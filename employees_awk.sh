#!/bin/bash

# Create employees.txt
cat > employees.txt << EOF
Alice,Engineering,50,40
Bob,Marketing,35,38
Charlie,Engineering,60,45
David,HR,30,40
Eva,Engineering,55,35
EOF

echo "Task 1: Basic Field Extraction"
awk -F',' '{print $1, $2}' employees.txt

echo

echo "Task 2: Engineering Employees"
awk -F',' '$2=="Engineering" {print}' employees.txt

echo

echo "Task 3: Gross Pay"
awk -F',' '{print $1 " gross pay: $" $3*$4}' employees.txt

echo

echo "Task 4: NR and NF"
awk -F',' '{print NR " (" NF " fields): " $0}' employees.txt

echo

echo "Task 5: Total Engineering Payroll"
awk -F',' '
BEGIN { total = 0 }
$2 == "Engineering" {
    total += $3 * $4
}
END {
    print "Total Engineering Payroll: $" total
}
' employees.txt
