# ngsolve-docker
some simple Dockerfiles to compile and run ngsolve.org in docker containers

# to build the base image
```docker build -t ngsolve-base ngsolve-base```

# to compile ngsolve
```docker build -t ngsolve ngsolve```

# to run the container
```docker run -dit --name ngsolve -p 220:22 --shm-size=2G -v ~/<sometestcodedir>:/root/<sometestcodedir> ngsolve```

# to login via docker
```docker exec -it ngsolve bash```
# to login via ssh
```ssh -p 220 -i <somekeyfile> root@localhost```
Note that in order to log with a key file you have to replace the public key while building the ngsolve-base.
Note that netgen with XServer currently does not work.
