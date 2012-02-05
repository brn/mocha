#!/bin/sh

Xvfb :2 -screen 0 800x600x24 2> /dev/null &
export DISPLAY=:2.0