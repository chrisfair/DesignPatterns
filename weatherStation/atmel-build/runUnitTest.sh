#! /bin/bash
REMOTEDIRECTORY="/tmp/fakeHome"
DIRECTORY_FOR_LCOV="/tmp/locvTempWork"
SCRIPTPATH=$1
USER_NAME="engr$.admin"
echo "Unit Testing for WeatherStation"
echo $(date)

echo "Removing old content, and writing new content..."

ssh -x -C $USER_NAME@chlorine mkdir "$REMOTEDIRECTORY" &>/dev/null
ssh -x -C $USER_NAME@chlorine mount "$REMOTEDIRECTORY" /opt &>/dev/null

ssh $USER_NAME@chlorine rm -rf /tmp/Home/*
scp $SCRIPTPATH/CatchUnitTests $USER_NAME@chlorine:/tmp
ssh -x -C $USER_NAME@chlorine /tmp/CatchUnitTests

#if ($PROCESSLCOV); then
#  cd $DIRECTORY_FOR_LCOV
#  ./updateScript.sh &>/tmp/log.output
#fi

