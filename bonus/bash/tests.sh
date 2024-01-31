#!/bin/bash

gcc -o tests -fprofile-arcs -ftest-coverage requirement.c tests/test.c -lcriterion

./tests

gcovr --exclude tests/
gcovr --html-details -o coverage_report.html

mv *.html test_results/

rm -rf *.gcda *.gcno
rm tests

xdg-open test_results/coverage_report.html