#! /bin/bash
REMOTEDIRECTORY="/tmp/homeMount"
SCRIPT=$(readlink -f $0)
LCOV_PATH=`dirname $SCRIPT`
SCRIPTPATH=$1
USER_NAME="engr$.admin"
DIRECTORY_FOR_LCOV="$LCOV_PATH/lcovDir"
CURRENT_DIR=$PWD
cd $LCOV_PATH
cd ..
DIRECTORY_FOR_CODE=$PWD
echo "Unit Testing for WeatherStation"
echo $(date)

echo "Removing old content, and writing new content..."

ssh $USER_NAME@chlorine rm -rf $REMOTEDIRECTORY/*
scp $SCRIPTPATH/CatchUnitTests $USER_NAME@chlorine:/tmp
ssh -x -C $USER_NAME@chlorine mkdir $REMOTEDIRECTORY
ssh -x -C $USER_NAME@chlorine mount $REMOTEDIRECTORY /home
ssh -x -C $USER_NAME@chlorine /tmp/CatchUnitTests -r junit > catchUnitTests.xml

cd $DIRECTORY_FOR_LCOV

rm -f $DIRECTORY_FOR_LCOV/coverage.info
rm -rf $DIRECTORY_FOR_LCOV/gcovSources/*
rm -rf $DIRECTORY_FOR_LCOV/lcovHtml/*


CATCH_TESTS_BASE=$SCRIPTPATH/CMakeFiles/CatchUnitTests.dir/
BASENAME=$(find $CATCH_TESTS_BASE -type d -name "*weatherStation*")

DESTINATION=$DIRECTORY_FOR_LCOV/gcovSources/$BASENAME

echo $BASENAME
echo $DIRECTORY_FOR_CODE

scp -r $USER_NAME@chlorine:/home $DIRECTORY_FOR_LCOV/gcovSources
cp -rf $BASENAME/* $DESTINATION 
lcov -c -d $DIRECTORY_FOR_LCOV/gcovSources -o $DIRECTORY_FOR_LCOV/coverage.info 
lcov -e $DIRECTORY_FOR_LCOV/coverage.info "$DIRECTORY_FOR_CODE/*" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered
lcov -r $DIRECTORY_FOR_LCOV/coverage.info.filtered "$DIRECTORY_FOR_CODE/catch/*" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered
lcov -r $DIRECTORY_FOR_LCOV/coverage.info.filtered "$DIRECTORY_FOR_CODE/catch-tests/*" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered
lcov -r $DIRECTORY_FOR_LCOV/coverage.info.filtered "4.8.6" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered

geninfo $DIRECTORY_FOR_LCOV/ -o $DIRECTORY_FOR_LCOV/lcov.dat
cd $DIRECTORY_FOR_LCOV
lcov_cobertura -b $BASENAME $DIRECTORY_FOR_LCOV/lcov.dat -e catch,catch-test,arm-linu
cp coverage.xml $1
genhtml $DIRECTORY_FOR_LCOV/coverage.info.filtered -o $DIRECTORY_FOR_LCOV/lcovHtml


ssh -x -C $USER_NAME@chlorine rm -rf /tmp/homeMount
ssh -x -C $USER_NAME@chlorine umount /home
ssh -x -C $USER_NAME@chlorine rm /tmp/CatchUnitTests


