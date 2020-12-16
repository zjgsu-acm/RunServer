#!/bin/sh

java -Xshare:dump
exec $@
