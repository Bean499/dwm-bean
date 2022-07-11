#!/usr/bin/env bash
git submodule update --init --recursive
mkdir -p out
cp -r dwm out
cp config.h out/
cd out
for patch in ../patches/; do
	git apply "../patches/$patch"
done
make
sudo make install
