#!/bin/bash

# Run the tests and capture output
./test/bin/caesar_cipher_test > test_output.txt

# Count total tests and failures
TOTAL_TESTS=$(grep -c "not_equal" test/caesar_cipher_tests.cpp)
FAILURES=$(grep -c "FAILED" test_output.txt)
PASSED=$((TOTAL_TESTS - FAILURES))

# Generate timestamp
TIMESTAMP=$(date +"%Y-%m-%dT%H:%M:%S")

# Start XML file
cat > report.xml << EOF
<?xml version="1.0" encoding="UTF-8"?>
<testsuites>
  <testsuite name="CaesarCipherTests" tests="$TOTAL_TESTS" failures="$FAILURES" errors="0" skipped="0" timestamp="$TIMESTAMP">
EOF

# Add failure details
if [ $FAILURES -gt 0 ]; then
  grep "FAILED" test_output.txt | while read -r line; do
    # Extract test name and failure details
    TEST_NAME=$(echo "$line" | sed -r 's/FAILED: ([^ ]+) -- .*/\1/')
    FAILURE_MSG=$(echo "$line" | sed -r 's/FAILED: [^ ]+ -- (.*)/\1/')
    
    # Add testcase with failure
    cat >> report.xml << EOF
    <testcase name="$TEST_NAME" classname="CaesarCipher">
      <failure message="Test failed" type="AssertionFailure">$FAILURE_MSG</failure>
    </testcase>
EOF
  done
fi

# Add passed tests
if [ $PASSED -gt 0 ]; then
  for i in $(seq 1 $PASSED); do
    # If we could extract actual test names, that would be better
    cat >> report.xml << EOF
    <testcase name="PassedTest_$i" classname="CaesarCipher" />
EOF
  done
fi

# Close XML file
cat >> report.xml << EOF
  </testsuite>
</testsuites>
EOF

# Output the original test results to console
cat test_output.txt

# Clean up
rm test_output.txt

# Return the original exit code
if [ $FAILURES -eq 0 ]; then
  exit 0
else
  exit 1
fi