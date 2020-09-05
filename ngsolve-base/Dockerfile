FROM ubuntu:20.04

ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt install -y software-properties-common libpython3.8 sudo
RUN add-apt-repository ppa:ngsolve/ngsolve
RUN apt-get update && apt-get install -y ngsolve python3-pip
RUN pip3 install jupyterlab scipy matplotlib ipywidgets mako

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && apt-get install -y xfce4 xfce4-goodies tightvncserver nano

RUN useradd -m ngsolve && echo "ngsolve:ngsolve" | chpasswd && adduser ngsolve sudo

# Create VNC config scripts
RUN mkdir /home/ngsolve/.vnc
COPY xstartup /home/ngsolve/.vnc/xstartup
RUN chmod +x /home/ngsolve/.vnc/xstartup
RUN chown -R ngsolve /home/ngsolve/.vnc
RUN chgrp -R ngsolve /home/ngsolve/.vnc

# TODO: install and configure some text editor

########### Mesa with sofware rendering (swpipe) ###########
#RUN ln -s /usr/bin/python3 /usr/bin/python

# Build Mesa
RUN apt-get install -y wget llvm-dev meson ninja-build bison flex
RUN wget https://mesa.freedesktop.org/archive/mesa-20.1.7.tar.xz
RUN tar xf mesa-20.1.7.tar.xz
RUN mkdir mesa-20.1.7/build
WORKDIR mesa-20.1.7/build

RUN meson -D glx=gallium-xlib -D gallium-drivers=swrast \
          -D platforms=x11 -D dri3=false -D dri-drivers="" \
          -D vulkan-drivers="" -D buildtype=release -D optimization=3
RUN ninja

# Setup our environment variables.
ENV XVFB_WHD="1920x1080x24"\
    LIBGL_ALWAYS_SOFTWARE="1" \
    GALLIUM_DRIVER="softpipe"

########### END build Mesa ############

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

# Needed for vncserver
ENV USER=ngsolve
