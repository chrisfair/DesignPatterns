#! /bin/bash
REMOTEDIRECTORY="/tmp/fakeHome"
SCRIPTPATH=$1
USER_NAME="engr$.admin"
DIRECTORY_FOR_LCOV="$1/locvTempWork"
echo "Unit Testing for WeatherStation"
echo $(date)

echo "Removing old content, and writing new content..."

ssh -x -C $USER_NAME@chlorine mkdir "$REMOTEDIRECTORY" &>/dev/null
ssh -x -C $USER_NAME@chlorine mount "$REMOTEDIRECTORY" /opt &>/dev/null

ssh $USER_NAME@chlorine rm -rf /tmp/Home/*
scp $SCRIPTPATH/CatchUnitTests $USER_NAME@chlorine:/tmp
ssh -x -C $USER_NAME@chlorine mkdir /tmp/homeMount
ssh -x -C $USER_NAME@chlorine mount /tmp/homeMount /home
ssh -x -C $USER_NAME@chlorine /tmp/CatchUnitTests

ssh -x -C $USER_NAME@chlorine umount /home
ssh -x -C $USER_NAME@chlorine rm /tmp/CatchUnitTests
ssh -x -C $USER_NAME@chlorine rm -rf /tmp/homeMount

cd $DIRECTORY_FOR_LCOV
./updateScript.sh &>/tmp/log.output

