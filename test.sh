#!/bin/bash

BLACK=`tput setaf 0`
RED=`tput setaf 1`
GREEN=`tput setaf 2`
YELLOW=`tput setaf 3`
BLUE=`tput setaf 4`
MAGENTA=`tput setaf 5`
CYAN=`tput setaf 6`
WHITE=`tput setaf 7`

BOLD=`tput bold`
RESET=`tput sgr0`

failed=0

rm output.log &>/dev/null

# P1 Test
cd test/p1
make clean &>/dev/null
make >> ../../output.log 2>&1
compile=$?
test=1
if [ ${compile} -eq 0 ]; then
  ./test >> ../../output.log 2>&1
  test=$?
fi
leak=1
if [ ${test} -eq 0 ]; then
  valgrind --error-exitcode=2 --leak-check=full ./test >> ../../output.log 2>&1
  leak=$?
fi
cd ../..

if [ ${compile} -ne 0 ]; then
    echo "${RED}[ FAILED ]${RESET} problem 1 cannot compile"
    failed=1
elif [ ${test} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 1 failed test"
    failed=1
elif [ ${leak} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 1 memory leaking"
    failed=1
else
    echo "${GREEN}[ OK     ]${RESET} problem 1 passed"
fi

# P2 Test
cd test/p2
make clean &>/dev/null
make >> ../../output.log 2>&1
compile=$?
test=1
if [ ${compile} -eq 0 ]; then
  ./test >> ../../output.log 2>&1
  test=$?
fi
leak=1
if [ ${test} -eq 0 ]; then
  valgrind --error-exitcode=2 --leak-check=full ./test >> ../../output.log 2>&1
  leak=$?
fi
cd ../..

if [ ${compile} -ne 0 ]; then
    echo "${RED}[ FAILED ]${RESET} problem 2 cannot compile"
    failed=1
elif [ ${test} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 2 failed test"
    failed=1
elif [ ${leak} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 2 memory leaking"
    failed=1
else
    echo "${GREEN}[ OK     ]${RESET} problem 2 passed"
fi

# P3 Test
cd test/p3
make clean &>/dev/null
make >> ../../output.log 2>&1
compile=$?
test=1
if [ ${compile} -eq 0 ]; then
  ./test >> ../../output.log 2>&1
  test=$?
fi
leak=1
if [ ${test} -eq 0 ]; then
  valgrind --error-exitcode=2 --leak-check=full ./test >> ../../output.log 2>&1
  leak=$?
fi
cd ../..

if [ ${compile} -ne 0 ]; then
    echo "${RED}[ FAILED ]${RESET} problem 3 cannot compile"
    failed=1
elif [ ${test} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 3 failed test"
    failed=1
elif [ ${leak} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 3 memory leaking"
    failed=1
else
    echo "${GREEN}[ OK     ]${RESET} problem 3 passed"
fi

# P4 Test
cd test/p4
make clean &>/dev/null
make >> ../../output.log 2>&1
compile=$?
test=1
if [ ${compile} -eq 0 ]; then
  ./test >> ../../output.log 2>&1
  test=$?
fi
leak=1
if [ ${test} -eq 0 ]; then
  valgrind --error-exitcode=2 --leak-check=full ./test >> ../../output.log 2>&1
  leak=$?
fi
cd ../..

if [ ${compile} -ne 0 ]; then
    echo "${RED}[ FAILED ]${RESET} problem 4 cannot compile"
    failed=1
elif [ ${test} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 4 failed test"
    failed=1
elif [ ${leak} -ne 0 ]; then
    echo "${YELLOW}[ FAILED ]${RESET} problem 4 memory leaking"
    failed=1
else
    echo "${GREEN}[ OK     ]${RESET} problem 4 passed"
fi

if [ ${failed} == 1 ]; then
  echo -e "\nError log: \n"
  cat output.log
  exit 1
fi

