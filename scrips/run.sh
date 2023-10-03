#!/bin/sh

premake5 gmake && make && ./bin/Debug/lump "$@"

