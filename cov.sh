#!/bin/bash

LOCATION="."
SRC="CMakeFiles/units.dir/src/"
find $SRC -name '*.cpp' -exec cp -t $LOCATION {} +
find $SRC -name '*.gcno' -exec cp -t $LOCATION {} +
find $SRC -name '*.gcda' -exec cp -t $LOCATION {} +
cd $LOCATION
find $SRC -name '*.cpp' -exec gcov -bf {} \;
