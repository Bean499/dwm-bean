#!/bin/bash
shopt -s dotglob
# git submodule update --init --recursive
rm -rf out
mkdir out
for file in dwm/*; do
	cp -r $file out/
done
cp config.h out/
cd out
for patch in ../patches/*; do
	git apply $patch;
done
make
sudo make clean install
