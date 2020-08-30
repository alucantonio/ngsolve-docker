# ngsolve-docker
Some simple Dockerfiles to compile and run netgen/ngsolve (ngsolve.org) in Docker containers.

- to build the base image
```docker build -t ngsolve-base ngsolve-base```

- to compile ngsolve form sources
```docker build -t ngsolve ngsolve```

- to run the container
```docker run -dit --name ngsolve -p 220:22 --shm-size=2G -v ~/<sometestcodedir>:/root/<sometestcodedir> ngsolve```

- to run the container with graphical support (XServer)
First launch ```xhost +``` from the Host's shell. Then:
```docker run -ti -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix ngsolve-base```
After using the container, launch ```xhost -```.

- to login via docker
```docker exec -it ngsolve bash```

- to login via ssh (currently not supported)
```ssh -p 220 -i <somekeyfile> root@localhost```
Note that in order to log with a key file you have to replace the public key while building the ngsolve-base.
