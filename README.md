# ngsolve-docker
Some simple Dockerfiles to compile and run [netgen/ngsolve](http://ngsolve.org) in Docker containers.

## Instructions
- to build the base image (ngsolve installed from .deb package):
    ```docker build -t ngsolve-base ngsolve-base```

- to create and run the container with graphical support (XServer from host), port forwarding for Jupyter Lab and mounting host local directory:
    First launch ```xhost +``` from the host's shell; then:
    ```docker run -it --name ngsolve -e DISPLAY=$DISPLAY -p 8888:8888 -v /tmp/.X11-unix:/tmp/.X11-unix -v $(pwd):/home/ngsolve/mnt ngsolve-base```
    After using the container, reset host's X server settings with ```xhost -```. To launch Jupyter Lab within the container: ```sh run_jupyterlab.sh```
    from ```/home/ngsolve```

- to start the container created previously:
    ```docker start ngsolve```; to attach current console to that of the running container ```docker attach ngsolve```

- to build the container with integrated X11 support: ```docker build -t ngsolve-x11 ngsolve-base```

- to run the container with X11 session (Mate desktop): ```sudo ./x11docker --desktop --share PATH_TO_SHARE --user=RETAIN ngsolve-x11```

- to compile ngsolve from sources (work in progress):
    ```docker build -t ngsolve ngsolve```
