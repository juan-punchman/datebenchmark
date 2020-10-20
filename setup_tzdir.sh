#!/bin/sh

# Download and unpack the latest iana database
mkdir -p tzdb
cd tzdb
wget https://www.iana.org/time-zones/repository/tzcode-latest.tar.gz
wget https://www.iana.org/time-zones/repository/tzdata-latest.tar.gz
gzip -dc tzcode-latest.tar.gz | tar -xf -
gzip -dc tzdata-latest.tar.gz | tar -xf -
rm -f tzcode-latest.tar.gz tzdata-latest.tar.gz

# Compile timezone database
mkdir -p tzdata
make TOPDIR=$(pwd)/tzdata install