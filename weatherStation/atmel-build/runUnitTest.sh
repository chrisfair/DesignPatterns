#! /bin/bash
REMOTEDIRECTORY="/tmp/homeMount"
SCRIPT=$(readlink -f $0)
LCOV_PATH=`dirname $SCRIPT`
SCRIPTPATH=$1
USER_NAME="engr$.admin"
DIRECTORY_FOR_LCOV="$LCOV_PATH/lcovDir"
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


BASENAME=$SCRIPTPATH/CMakeFiles/CatchUnitTests.dir/home/cfair/Tutorial/DesignPatterns/weatherStation/atmel-build/build/CMakeFiles/CatchUnitTests.dir/home/cfair/Tutorial/DesignPatterns/weatherStation
scp -r $USER_NAME@chlorine:/home $DIRECTORY_FOR_LCOV/gcovSources
cp -rf $SCRIPTPATH/CMakeFiles/CatchUnitTests.dir/home/cfair $DIRECTORY_FOR_LCOV/gcovSources/home/cfair/Tutorial/DesignPatterns/weatherStation/atmel-build/build/CMakeFiles/CatchUnitTests.dir/home
lcov -c -d $DIRECTORY_FOR_LCOV/gcovSources -o $DIRECTORY_FOR_LCOV/coverage.info 
lcov -e $DIRECTORY_FOR_LCOV/coverage.info "/home/cfair/Tutorial/DesignPatterns/weatherStation/*" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered
lcov -r $DIRECTORY_FOR_LCOV/coverage.info.filtered "/home/cfair/Tutorial/DesignPatterns/weatherStation/catch/*" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered
lcov -r $DIRECTORY_FOR_LCOV/coverage.info.filtered "/home/cfair/Tutorial/DesignPatterns/weatherStation/catch-tests/*" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered
lcov -r $DIRECTORY_FOR_LCOV/coverage.info.filtered "4.8.6" -o $DIRECTORY_FOR_LCOV/coverage.info.filtered

geninfo $DIRECTORY_FOR_LCOV/ -o $DIRECTORY_FOR_LCOV/lcov.dat
lcov_cobertura $DIRECTORY_FOR_LCOV/  $DIRECTORY_FIR_LCOV/coverage.xml
genhtml $DIRECTORY_FOR_LCOV/coverage.info.filtered -o $DIRECTORY_FOR_LCOV/lcovHtml

ssh -x -C $USER_NAME@chlorine rm -rf /tmp/homeMount
ssh -x -C $USER_NAME@chlorine umount /home
ssh -x -C $USER_NAME@chlorine rm /tmp/CatchUnitTests


