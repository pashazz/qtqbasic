#!/bin/bash
#USE BEFORE GIT COMMIT!

make clean
rm QtQBasic
rm -rf qtc-gdbmacros
rm -rf debug release
find ./ -path "./*~" -delete
find ./ -path "./*Makefile*" -delete         