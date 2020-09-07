# ngsolve-docker
Some simple Dockerfiles to compile and run [netgen/ngsolve](http://ngsolve.org) in Docker containers.
Graphical output is provided either through host's driver (ngsolve-base image) or via VNC using the approach described in [docker-ubuntu-vnc-desktop](https://github.com/fcwu/docker-ubuntu-vnc-desktop). In the latter case, desktop is Ubuntu-LXQT (Focal).

## Instructions (X server running on host)
- to build the container (installs ngsolve from .deb package):

    ```docker build -t ngsolve-base ngsolve-base```

- to create and run the container:
  1. launch ```xhost +``` from the host's shell;
  2. execute

    ```docker run -it --name ngsolve -e DISPLAY=$DISPLAY -p 8888:8888 -v /tmp/.X11-unix:/tmp/.X11-unix -v $(pwd):/home/ngsolve/mnt ngsolve-base```;

  3. to launch Jupyter Lab within the container: ```sh run_jupyterlab.sh``` from ```/home/ngsolve```;
  4. after using the container, reset host's X server settings with ```xhost -```


- to start the container created previously and open the shell:

    ```docker start ngsolve && docker attach ngsolve```

## Instructions (X server integrated within container, access via VNC)
- to build the container:

  ```docker build -t ngsolve-vnc ngsolve-lxqt-vnc```

- to run the container:

  launch ```run_vnc.sh``` script in the main folder of the repository.
