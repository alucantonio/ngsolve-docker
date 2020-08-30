FROM ubuntu:20.04

ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt install -y software-properties-common libpython3.8 sudo
RUN add-apt-repository ppa:ngsolve/ngsolve
RUN apt-get update && apt-get install -y ngsolve python3-pip
RUN pip3 install jupyterlab
RUN useradd -m docker && echo "docker:docker" | chpasswd && adduser docker sudo

# TODO: install and configure some text editor

USER docker

COPY run_jupyterlab.sh /home/docker

WORKDIR /home/docker
