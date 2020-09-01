FROM ubuntu:20.04

ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt install -y software-properties-common libpython3.8 sudo
RUN add-apt-repository ppa:ngsolve/ngsolve
RUN apt-get update && apt-get install -y ngsolve python3-pip
RUN pip3 install jupyterlab scipy matplotlib ipywidgets

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && apt-get install -y xfce4 xfce4-goodies tightvncserver nano

RUN useradd -m ngsolve && echo "ngsolve:ngsolve" | chpasswd && adduser ngsolve sudo

# TODO: install and configure some text editor

RUN mkdir /home/ngsolve/.vnc
COPY xstartup /home/ngsolve/.vnc/xstartup
RUN chmod +x /home/ngsolve/.vnc/xstartup
RUN chown -R ngsolve /home/ngsolve/.vnc
RUN chgrp -R ngsolve /home/ngsolve/.vnc

USER ngsolve

# jupyter notebook extensions for interactive visualization
RUN jupyter nbextension install --py widgetsnbextension
RUN jupyter nbextension enable --py widgetsnbextension
RUN jupyter nbextension install --user --py ngsolve
RUN jupyter nbextension enable --user --py ngsolve

# The command needed to install the NGSolve Jupyter lab extension depends on the system and is generated with the following code:
# python3 -c 'import ngsolve.webgui; ngsolve.webgui.howtoInstallJupyterLabextension()'

# TODO: download and unpack ngsolve i-tutorials

COPY run_jupyterlab.sh /home/ngsolve

WORKDIR /home/ngsolve
# Needed for vncserver
ENV USER=ngsolve
