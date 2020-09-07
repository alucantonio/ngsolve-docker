#!/bin/sh
docker run -p 6080:80 -p 5900:5900 -e RESOLUTION=1920x1080 -e USER=ngsolve -v /dev/shm:/dev/shm ngsolve-vnc
