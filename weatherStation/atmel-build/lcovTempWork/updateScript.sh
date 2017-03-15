#! /bin/bash
SCRIPT=$(readlink -f $0)
# Absolute path this script is in. /home/user/bin
SCRIPTPATH=`dirname $SCRIPT`
rm -f coverage.info
rm -f $SCRIPTPATH/gcovSources/*.gcno
rm -f $SCRIPTPATH/gcovSources/*.gcda
rm -rf $SCRIPTPATH/lcovHtml/*
scp engr\$.admin@chlorine:/opt/Projects/cm130/source/GuiUnitTest/* $SCRIPTPATH/gcovSources
cp /opt/Projects/cm130/source/GuiUnitTest/*.gcno $SCRIPTPATH/gcovSources
lcov -b ./gui -c -d $SCRIPTPATH/gcovSources -o $SCRIPTPATH/coverage.info
lcov -e $SCRIPTPATH/coverage.info "`pwd`/gui/*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gcovSources/GuiUnitTest.*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/GuiUnitTest.*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gcovSources/main.cpp" -o /$SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/main.cpp" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/TCPTester.cpp" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/TCPTester.h" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gcovSources/TCPTester.o" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gcovSources/UnitTest_*.*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/UnitTest_*.*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/ui_*.*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/*.h" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gcovSources/moc_*.*" -o $SCRIPTPATH/coverage.info.filtered
lcov -r $SCRIPTPATH/coverage.info.filtered "`pwd`/gui/moc_*.*" -o $SCRIPTPATH/coverage.info.filtered
genhtml $SCRIPTPATH/coverage.info.filtered -o $SCRIPTPATH/lcovHtml/

